#pragma once
#include <iostream>
#include <initializer_list>

namespace emulator {
class ParallelInParallelOut {
private:
    size_t m_dataWidth;
    bool *m_bits;
    const bool *m_empty;
    bool m_outputEnable;

public:
    ParallelInParallelOut(size_t dataWidth = 8) : m_dataWidth(dataWidth), m_outputEnable(false), m_empty(new bool[dataWidth]) {
        m_bits = new bool[m_dataWidth];
    }

    ~ParallelInParallelOut() {
        delete[] m_bits;
    }

    void setOutputEnable(bool enable) { m_outputEnable = enable; }

    void clock(bool pulse, bool** bits) {
        if (pulse) {
            for (size_t i = 0; i < m_dataWidth; i++)
                m_bits[i] = bits[i];
        }
    }

    void clock(bool pulse, std::initializer_list<bool> bits) {
        if (pulse) {
            for (size_t i = 0; i < m_dataWidth; i++)
                m_bits[i] = bits.begin()[i];
        }
    }

    bool *data() { if (m_outputEnable) return m_bits; else return (bool*) m_empty; }
};
}