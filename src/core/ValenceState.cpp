#include "valence/ValenceState.hpp"

namespace valence {

ValenceState::ValenceState(std::size_t num_qubits)
    : m_state_vector(num_qubits), m_num_qubits(num_qubits) {
}

void ValenceState::print(bool print_empty_states) const {
    m_state_vector.print(print_empty_states);
}

std::size_t ValenceState::getNumQubits() const {
    return m_num_qubits;
}

Amplitude ValenceState::getAmplitude(std::size_t index) const {
    return m_state_vector.getAmplitude(index);
}

} // namespace valence