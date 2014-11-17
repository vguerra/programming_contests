#!/bin/sh

OUT=cut

clang++ -std=c++11 -o $OUT "$OUT".cc
./$OUT < "$OUT".in
