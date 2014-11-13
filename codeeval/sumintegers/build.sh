#!/bin/sh

OUT=sum

clang++ -std=c++11 -o $OUT "$OUT".cpp
./$OUT "$OUT".in
