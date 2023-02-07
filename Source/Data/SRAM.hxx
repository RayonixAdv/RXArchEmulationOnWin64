#pragma once
#include <iostream>

namespace RXEmulator::Data {
    /**
     * Static random access memory. 
     */
    class SRAM {
    private:
        size_t m_bytesWidth;
        size_t m_height;

        uint8_t *m_data;
        uint8_t *m_capturedBytes;

    public:
        explicit SRAM(size_t bytesWidth = 4, size_t height = 4) : m_bytesWidth(bytesWidth), m_height(height) {
            m_data = new uint8_t[m_bytesWidth * m_height];
        }
        ~SRAM() {
            delete[] m_data;
        }

        void Read(size_t row) {
            m_capturedBytes = new uint8_t[m_bytesWidth];
            for (size_t i = 0; i < m_bytesWidth; i++)
                m_capturedBytes[i] = m_data[row * m_bytesWidth + i];
        }

        void Write(size_t row, uint8_t *bytes) {
            for (size_t i = 0; i < m_bytesWidth; i++)
                m_data[row * m_bytesWidth + i] = bytes[i];
        }

        uint8_t *GetCapturedBytes() {
            return m_capturedBytes;
        }

        uint8_t *GetMemory() {
            return m_data;
        }

        size_t GetSize() {
            return m_bytesWidth * m_height;
        }
    };
}