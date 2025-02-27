#include <iostream>
#include <iomanip>
#include <bitset>
#include "valence/ValenceState.hpp"

int main() {
    std::cout << "Valence Quantum" << std::endl;
    std::cout << "====================================" << std::endl;
    
    const int num_qubits = 22;
    valence::ValenceState state(num_qubits);
    
    std::cout << "Num qubits: " << num_qubits << std::endl;
    std::cout << "====================================" << std::endl;
    
    state.print(true);
    
    return 0;
}
