#!/bin/sh

clang++ -std=c++11 -o pairs pairs.cc
./pairs < pairs.in
