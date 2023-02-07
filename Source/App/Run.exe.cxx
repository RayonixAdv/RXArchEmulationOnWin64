#include <iostream>
#include "../Mainboard/SquareGenerator.hxx"

class Hi : public RXEmulator::Mainboard::SquareGenerator {
protected:
    void OnPulseChange(bool pulse) override {
        std::cout << "Pulse: " << pulse << std::endl;
    }

public:
    Hi() : SquareGenerator(10, 50) {}
};

int main(int argc, char* argv[]) {
    Hi hi;

    hi.Start();
    hi.Block();

    return 0;
}