#include "valence/StateVector.hpp"

namespace valence {

StateVector::StateVector(std::size_t num_qubits) {
    m_size = 1ULL << num_qubits; 
    m_data = std::vector<Amplitude>(m_size, Amplitude(0.0, 0.0));
    
    m_data[0] = Amplitude(1.0, 0.0);
}

std::size_t StateVector::getSize() const { 
    return m_size; 
}

Amplitude StateVector::getAmplitude(std::size_t index) const { 
    return m_data[index]; 
}

void StateVector::print(bool printEmptyStates) const {

    size_t max_width = 0;
    for (std::size_t i = 0; i < m_size; i++) {
        if (m_data[i].real() != 0 || m_data[i].imag() != 0 || printEmptyStates) {
            max_width = std::max(max_width, i > 0 ? static_cast<size_t>(std::log2(i)) + 1 : 1);
        }
    }
    
    char buffer[128];
    
    for (std::size_t i = 0; i < m_size; i++) {
        if (m_data[i].real() != 0 || m_data[i].imag() != 0 || printEmptyStates) {
            char bin_buffer[64] = {0};
            int bin_pos = 63;
            
            std::size_t num = i;
            if (num == 0) {
                bin_buffer[--bin_pos] = '0';
            } else {
                while (num > 0) {
                    bin_buffer[--bin_pos] = (num & 1) ? '1' : '0';
                    num >>= 1;
                }
            }
            
            double real = m_data[i].real();
            double imag = m_data[i].imag();
            double abs_val = std::abs(m_data[i]);
            
            printf("|%*s> %8.2f + %.2fi    |%.2f|\n", 
                   static_cast<int>(max_width), &bin_buffer[bin_pos], 
                   real, imag, abs_val);
        }
    }
}

} 