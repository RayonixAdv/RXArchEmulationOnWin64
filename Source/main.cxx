#include <iostream>
#include "Sync/ClockGenerator.hxx"
#include "Sync/MachineController.hxx"

int main(int argc, char** argv) {
    emulator::ClockGenerator *clock = new emulator::ClockGenerator(10);
    emulator::MachineController *controller = new emulator::MachineController(clock);

    controller->tryInitialize();
    clock->mode(true);
    clock->block();

    return 0;
}