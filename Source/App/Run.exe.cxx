#include "../MainBoard/MainBoard.hxx"

int main(int argc, char* argv[]) {
    std::vector<RXEmulator::Processor::Core *> cores;
    size_t coreCount = 1;
    for (size_t i = 0; i < coreCount; i++)
        cores.push_back(new RXEmulator::Processor::Core(i));
    RXEmulator::Processor::CPU cpu(cores);

    RXEmulator::MainBoard::MainBoard machine(2, { &cpu });

    machine.Start();
    machine.Block();

    for (auto core : cores)
        delete core;
    return 0;
}