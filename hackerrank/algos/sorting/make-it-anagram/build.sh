#!/bin/sh

clang++ -std=c++11 -o make_anagram make_anagram.cc
./make_anagram < make_anagram.in
