# Valence - Quantum Computing Made Simple(r)

Learning quantum computing concepts is challenging enough as-is. Having to navigate a byzantine library only makes the learning curve steeper.

Valence is a lightweight and intuitive quantum library and simulator written in C++. It is designed to help quantum newcomers grasp the basic ideas of quantum computing on their own machine before delving into more advanced concepts.

This is a new project, and current functionality is limited (non-existent). Plans for now are:
- Make the damn thing
- Create a React interface for users to build quantum circuits with Bloch sphere visualization, measurement probabilities/amplitudes, and more. Think Qiskit, but WASM (more qubits).


## Quick Start

```bash
# Build and run tests
mkdir build && cd build
cmake ..
make
ctest
```
