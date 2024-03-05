cmake_minimum_required(VERSION 3.10)
project(CustomListTest)

# Adăugăm compilarea testelor folosind Boost.Test
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# Adăugăm compilarea și executarea testelor
add_executable(test_custom_list CustomListTest.cpp)
target_link_libraries(test_custom_list PRIVATE Boost::unit_test_framework)

# Adăugăm compilarea și legarea fișierului sursă CustomList.cpp
add_library(custom_list STATIC CustomList.cpp)
# Asigurăm că fișierul header CustomList.h este accesibil
target_include_directories(custom_list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Adăugăm legătura între test și clasa CustomList
target_link_libraries(test_custom_list PRIVATE custom_list)

# Adăugăm opțiunile de acoperire a codului
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
