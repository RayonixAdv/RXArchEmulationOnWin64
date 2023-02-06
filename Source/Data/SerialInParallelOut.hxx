#pragma once
#include <iostream>

namespace emulator {
class SerialInParallelOut {
private:
    size_t m_dataWidth;
    bool *m_bits;
    const bool *m_empty; 
    bool m_outputEnable;

public:
    SerialInParallelOut(size_t dataWidth = 8) : m_dataWidth(dataWidth), m_outputEnable(false), m_empty(new bool[dataWidth]) {
        m_bits = new bool[m_dataWidth];
    }

    ~SerialInParallelOut() {
        delete[] m_bits;
    }

    void setOutputEnable(bool enable) { m_outputEnable = enable; }

    void clock(bool pulse, bool bit) {
        if (pulse) {
            for (size_t i = 0; i < m_dataWidth - 1; i++)
                m_bits[i] = m_bits[i + 1];
            m_bits[m_dataWidth - 1] = bit;
        }
    }

    bool *data() { if (m_outputEnable) return m_bits; else return (bool*) m_empty; }
};
}