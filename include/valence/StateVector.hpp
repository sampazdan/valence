#pragma once

#include <vector>
#include <complex>
#include <iostream>
#include <iomanip>
#include <bitset>

namespace valence {

using Amplitude = std::complex<double>;

class StateVector {

public:
    explicit StateVector(std::size_t num_qubits);

    std::size_t getSize() const;
    Amplitude getAmplitude(std::size_t index) const;
    void print(bool printEmptyStates = false) const;

private:
    std::vector<Amplitude> m_data;
    std::size_t m_size;
};


}