#pragma once
#include <thread>
#include <chrono>

namespace RXEmulator::Mainboard {
    /**
     * This class generates a square wave with a given frequency and duty cycle.
     */
    class SquareGenerator {
    protected:
        virtual void OnPulseChange(bool pulse) = 0;

    private:
        std::thread *m_thread;

        size_t m_frequency;
        size_t m_duty;

        bool m_active;

        void ThreadFunction() {
            while (m_active) {
                std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000 / m_frequency * m_duty / 100));
                OnPulseChange(true);
                std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000 / m_frequency * (100 - m_duty) / 100));
                OnPulseChange(false);
            }
        }

    public:
        /**
         * @param frequency The frequency of the square wave in Hz.
         * @param duty The duty cycle of the square wave in percent.
         */
        SquareGenerator(size_t frequency, size_t duty) : m_frequency(frequency), m_duty(duty), 
            m_thread(nullptr), m_active(false) {}
        ~SquareGenerator() {
            Stop();
            delete m_thread;
        }

        void Start() {
            if (m_active) return;
            m_active = true;
            m_thread = new std::thread(&SquareGenerator::ThreadFunction, this);
        }

        void Stop() {
            if (!m_active) return;
            m_active = false;
            m_thread->join();

            delete m_thread;
            m_thread = nullptr;
        }

        void Block() {
            if (m_active && m_thread->joinable()) m_thread->join();
        }
    };
}