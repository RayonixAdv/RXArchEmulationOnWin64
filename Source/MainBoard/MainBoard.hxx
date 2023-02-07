#pragma once
#include <vector>
#include "SquareGenerator.hxx"
#include "../Processor/CPU.hxx"
#include "../Data/SRAM.hxx"
#include "../Data/PermanentSRAM.hxx"

namespace RXEmulator::MainBoard {
    /**
     * MainBoard that contains the processor(s), memory and other resources.
     */
    class MainBoard : public SquareGenerator {
    protected:
        void OnPulseChange(bool pulse) override {
            for (auto cpu : m_cpus)
                cpu->ClockTick(pulse);
        }

    private:
        std::vector<Processor::CPU *> m_cpus;

    public:
        explicit MainBoard(size_t frequency, std::vector<Processor::CPU *> cpus) : SquareGenerator(frequency, 50),
            m_cpus(std::move(cpus)) {}
    };
}