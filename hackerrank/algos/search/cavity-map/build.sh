#!/bin/sh

clang++ -std=c++11 -o cavity cavity.cc
./cavity < cavity.in
