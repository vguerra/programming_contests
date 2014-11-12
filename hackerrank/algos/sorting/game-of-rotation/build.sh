#!/bin/sh

OUT=rotation

clang++ -std=c++11 -o $OUT "$OUT".cc
./$OUT < "$OUT".in
