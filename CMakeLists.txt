# this thing sucks we'll clean up later right? right??

cmake_minimum_required(VERSION 3.16)
project(Valence LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# options -- toggle as needed
option(BUILD_SHARED_LIBS   "Build shared instead of static libraries" OFF)
option(BUILD_TESTS         "Build unit/integration tests" OFF)
option(BUILD_EXAMPLES      "Build example programs" ON)
option(USE_METAL           "Enable Metal-based acceleration on Apple" OFF)
option(USE_CUDA            "Enable CUDA-based acceleration" OFF)
option(BUILD_PYTHON_BINDINGS "Build Python bindings using pybind11" OFF)

# dependencies
find_package(Threads REQUIRED)

# py binds god py binds are ass!
if(BUILD_PYTHON_BINDINGS)
    find_package(pybind11 QUIET)
    if(NOT pybind11_FOUND)
        message(STATUS "pybind11 not found, Python bindings will not be built")
        set(BUILD_PYTHON_BINDINGS OFF)
    else()
        message(STATUS "Python bindings will be built")
    endif()
endif()

# metal -- M-series, might need custom bindings
if(USE_METAL)
    # possibly
    # set(METAL_LIB "-framework Metal -framework Foundation -framework CoreGraphics")
    message(STATUS "Metal backend enabled.")
endif()

# for CUDA (placeholder)
if(USE_CUDA)
    message(STATUS "CUDA backend enabled.")
endif()

# Include
include_directories(${PROJECT_SOURCE_DIR}/include)

# src VVV

# core
file(GLOB_RECURSE CORE_SRC
    "${PROJECT_SOURCE_DIR}/src/core/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/ops/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/utils/*.cpp"
)

# cpu
file(GLOB CPU_BACKEND_SRC
    "${PROJECT_SOURCE_DIR}/src/backends/CPUBackend.cpp"
)

# metal
set(METAL_BACKEND_SRC "")
if(USE_METAL)
    file(GLOB METAL_BACKEND_SRC
        "${PROJECT_SOURCE_DIR}/src/backends/MetalBackend.mm"
    )
endif()

# cuda
set(CUDA_BACKEND_SRC "")
if(USE_CUDA)
    file(GLOB CUDA_BACKEND_SRC
        "${PROJECT_SOURCE_DIR}/src/backends/CUDABackend.cu"
    )
endif()

# src blender
set(VALENCE_SOURCES
    ${CORE_SRC}
    ${CPU_BACKEND_SRC}
    ${METAL_BACKEND_SRC}
    ${CUDA_BACKEND_SRC}
)

# lib init/link
add_library(valence ${VALENCE_SOURCES})

target_link_libraries(valence PUBLIC Threads::Threads)
if(USE_METAL)
    target_compile_definitions(valence PUBLIC USE_METAL)
    # e.g. target_link_libraries(valence PUBLIC ${METAL_LIB})
    target_link_libraries(valence PUBLIC "-framework Metal")
    target_link_libraries(valence PUBLIC "-framework Foundation")
endif()

if(USE_CUDA)
    target_compile_definitions(valence PUBLIC USE_CUDA)
endif()

# build module (py) - Only if Python bindings are enabled
if(BUILD_PYTHON_BINDINGS)
    pybind11_add_module(pyValence
        ${PROJECT_SOURCE_DIR}/python/bindings/pybind_module.cpp
    )
    target_link_libraries(pyValence PRIVATE valence)
endif()

# tests, might use gtest idk
if(BUILD_TESTS)
    message(STATUS "Tests are currently disabled to simplify the build")
    # "yea we'll totally implement testing later"
endif()

# build examples
if(BUILD_EXAMPLES)
    if(EXISTS "${PROJECT_SOURCE_DIR}/examples/CMakeLists.txt")
        add_subdirectory(examples)
    else()
        message(STATUS "Examples directory doesn't contain CMakeLists.txt, skipping...")
    endif()
endif()

# ✨ boilerplate garb ✨

install(TARGETS valence
    EXPORT valenceTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

# only install Python bindings if they were built
if(BUILD_PYTHON_BINDINGS)
    install(TARGETS pyValence
        LIBRARY DESTINATION python
    )
endif()

# public headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/valence
    DESTINATION include
)

# export package cfg
install(EXPORT valenceTargets
    FILE ValenceTargets.cmake
    NAMESPACE Valence::
    DESTINATION lib/cmake/valence
)
