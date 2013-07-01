#!/usr/bin/env python
from setuptools import setup, find_packages
from distutils.extension import Extension

import sys

if 'setuptools.extension' in sys.modules:
    m = sys.modules['setuptools.extension']
    m.Extension.__dict__ = m._Extension.__dict__

packages = find_packages()

linked_list_extension = Extension('cpppython.linked_list', ['cpppython/linked_list.pyx'],include_dirs=['include/'], language='c++')

setup(name='cpptest',
        version='0.0.1',
        packages=packages,
        setup_requires=['setuptools_cython'],
        ext_modules=[linked_list_extension],
        )
