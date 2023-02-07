#pragma once
#include "SRAM.hxx"
#ifdef _WIN32
#include <Windows.h>
#endif

namespace RXEmulator::Data {
    class PermanentSRAM {
    private:
        SRAM m_sram;
        std::string m_fileSource;

    public:
        explicit PermanentSRAM(std::string fileSource, size_t bytesWidth = 4, size_t bytesHeight = 4) : m_fileSource(std::move(fileSource)) {
            m_sram = SRAM(bytesWidth, bytesHeight);
            Load();
        }

        ~PermanentSRAM() {
            Save();
        }

        void Load() {
            FILE *file = fopen(m_fileSource.c_str(), "rb");
            if (file == nullptr) {
                std::cout << "Failed to open file: " << m_fileSource << std::endl;
                return;
            }

            fread(m_sram.GetMemory(), sizeof(uint8_t), m_sram.GetSize(), file);
            fclose(file);
        }

        void Save() {
            FILE *file = fopen(m_fileSource.c_str(), "wb");
            if (file == nullptr) {
                std::cout << "Failed to open file: " << m_fileSource << std::endl;
                return;
            }

            fwrite(m_sram.GetMemory(), sizeof(uint8_t), m_sram.GetSize(), file);
            fclose(file);
        }

        Data::SRAM *GetSRAM() {
            return &m_sram;
        }
    };
}