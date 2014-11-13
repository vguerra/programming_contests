#!/bin/sh

OUT=odd

clang++ -std=c++11 -o $OUT "$OUT".cpp
./$OUT "$OUT".in
