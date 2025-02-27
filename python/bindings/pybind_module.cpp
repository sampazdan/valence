#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
// #include "ValenceSimulator.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pyValence, m) {
    m.doc() = "Python bindings for Valence, a quantum simulator";
    // Expose classes, methods, etc.
}
