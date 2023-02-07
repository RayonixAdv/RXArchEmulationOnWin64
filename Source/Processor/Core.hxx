#pragma once
#include <iostream>

namespace RXEmulator::Processor {
    /**
     * The core of the processor.
     */
    class Core {
    private:
        size_t m_coreID;

    public:
        explicit Core(size_t coreID) : m_coreID(coreID) {}

        void ClockTick(bool pulse) {
            std::cout << "Core " << m_coreID << " ticked with pulse " << pulse << std::endl;
        }
    };
}