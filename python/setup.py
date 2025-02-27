from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import os

setup(
    name='valence',
    version='0.1.0',
    author='Your Name',
    author_email='your_email@example.com',
    description='Valence Quantum Simulator Python Bindings',
    long_description='A next-generation quantum simulator targeting Apple M4 with Metal backend.',
    ext_modules=[
        # Will be built by pybind11_add_module / or external CMake
    ],
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
)
