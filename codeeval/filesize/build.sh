#!/bin/sh

OUT=filesize

clang++ -std=c++11 -o $OUT "$OUT".cpp
./$OUT "$OUT".in
