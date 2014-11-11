#!/bin/sh

clang++ -std=c++11 -o sherlock-array sherlock-array.cc
./sherlock-array < sherlock-array.in
