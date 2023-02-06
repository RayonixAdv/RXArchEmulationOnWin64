#include <iostream>
#include "Sync/ClockGenerator.hxx"
#include "Sync/MachineController.hxx"
#include "Data/SerialInParallelOut.hxx"

int main(int argc, char** argv) {
    emulator::ClockGenerator *clock = new emulator::ClockGenerator(10);
    emulator::MachineController *controller = new emulator::MachineController(clock);

    // controller->tryInitialize();
    // clock->mode(true);
    // clock->block();

    emulator::SerialInParallelOut *sipo = new emulator::SerialInParallelOut(2);

    sipo->setOutputEnable(false);
    sipo->clock(true, true);
    sipo->clock(true, false);

    std::cout << sipo->data()[0] << " " << sipo->data()[1] << std::endl;

    sipo->clock(true, false);
    std::cout << sipo->data()[0] << " " << sipo->data()[1] << std::endl;
    sipo->clock(true, true);
    std::cout << sipo->data()[0] << " " << sipo->data()[1] << std::endl;

    return 0;
}