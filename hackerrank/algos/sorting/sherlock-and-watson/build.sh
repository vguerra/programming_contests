#!/bin/sh

clang++ -std=c++11 -o sherlock-watson sherlock-watson.cc
./sherlock-watson < sherlock-watson.in
