#pragma once

#include <iostream>
#include <string>
#include "StateVector.hpp"

// for now, only using full state vector simulation. density matrices soon i swear


namespace valence {

class ValenceState {
public:
    explicit ValenceState(std::size_t num_qubits);
    
    void print(bool print_empty_states = false) const;
    
    std::size_t getNumQubits() const;
    
    Amplitude getAmplitude(std::size_t index) const;
    
    // void applyGate(const Gate& gate);
    // double getProbability(std::size_t basis_state) const;

private:
    StateVector m_state_vector;
    
    std::size_t m_num_qubits;
};

} 
