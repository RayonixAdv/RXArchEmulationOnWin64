#pragma once
#include <iostream>
#include <thread>
#include <functional>

namespace emulator {
/**
 * Clock signal generator with built in automatic multiplier
 */
class ClockGenerator {
private:
    size_t m_frequency;
    size_t m_dutyCycle;
    bool m_running;

    std::thread m_thread;
    std::function<void(bool pulse)> m_callback = [](bool pulse) {};

public:
    /**
     * Clock will not start until mode(true) is called explicity.
     * @param frequency Frequency of the clock in hertz.
     */
    ClockGenerator(size_t frequency = 10) : m_frequency(frequency), m_dutyCycle(50), m_running(false) {}

    /**
     * @return Frequency of the clock in hertz.
     */
    size_t getFrequency() const { return m_frequency; }

    /**
     * @param frequency Frequency of the clock in hertz.
     */
    void setFrequency(size_t frequency) { m_frequency = frequency; }

    /**
     * @return Duty cycle of the clock in percent.
     */
    size_t getDutyCycle() const { return m_dutyCycle; }

    /**
     * @param dutyCycle Duty cycle of the clock in percent.
     */
    void setDutyCycle(size_t dutyCycle) { m_dutyCycle = dutyCycle; }

    void setCallback(std::function<void(bool pulse)> callback) { m_callback = callback; }
    void block() { m_thread.join(); }

    void mode(bool start) { 
        if (m_running && start) return;
        m_running = start;
    
        if (start) {
            m_thread = std::thread([this]() {
                while (m_running) {
                    std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000 / m_frequency * m_dutyCycle / 100));
                    m_callback(true);
                    std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000 / m_frequency * (100 - m_dutyCycle) / 100));
                    m_callback(false);
                }
            });
        }
    };
};
}