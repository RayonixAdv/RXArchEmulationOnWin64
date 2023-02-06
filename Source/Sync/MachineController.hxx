#pragma once
#include "ClockGenerator.hxx"

namespace emulator {
/**
 * This is like a chipset of an x86 system.
 */
class MachineController {
private:
    ClockGenerator *m_clock;

    void clockCallback(bool signal) {
        printf("Clock signal: %d\n", signal);
    }

public:
    // You are required to start the clock your self to start the machine
    MachineController(ClockGenerator *clock) : m_clock(clock) {};

    // This will configure the clock generator to execute methods in the controller.
    void tryInitialize() {
        m_clock->setCallback([this](bool signal) { clockCallback(signal); });
    }
};
}