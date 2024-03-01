#!/bin/bash

g++ -std=c++11 -o MyTests CustomListTest.cpp -lboost_unit_test_framework -DBOOST_TEST_DYN_LINK
./MyTests --log_level=all --show_progress=yes
