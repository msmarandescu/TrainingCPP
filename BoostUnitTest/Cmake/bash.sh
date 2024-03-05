#!/bin/bash

# Compilare
cmake -S . -B build
cmake --build build

# Rulează testele
./build/test_custom_list

# Colecteaza datele de acoperire a codului într-un fișier coverage.info
lcov --capture --directory . --output-file coverage.info --no-external

# Elimina informațiile legate de fișierele din sistemul de operare (de exemplu, fișierele din /usr/*) din raportul de acoperire a codului. 
lcov --remove coverage.info -o coverage_filtered.info '/usr/*'

# Genereaza raportul de coverage
genhtml --demangle-cpp coverage_filtered.info --output-directory lcov

# Deschide raportul
firefox lcov/index.html
