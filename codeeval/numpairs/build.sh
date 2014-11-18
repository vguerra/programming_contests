#!/bin/sh

OUT=numpairs

clang++ -std=c++11 -o $OUT "$OUT".cpp
./$OUT "$OUT".in
