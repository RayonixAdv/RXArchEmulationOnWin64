#pragma once
#include <utility>
#include <vector>
#include "Core.hxx"

namespace RXEmulator::Processor {
    /**
     * Processor containing cores.
     */
    class CPU {
    private:
        std::vector<Core *> m_cores;

    public:
        explicit CPU(std::vector<Core *> cores) : m_cores(std::move(cores)) {}

        void ClockTick(bool pulse) {
            for (auto core : m_cores) {
                core->ClockTick(pulse);
            }
        }
    };
}