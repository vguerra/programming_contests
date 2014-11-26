#!/bin/sh

OUT=predict
rm -f $OUT
clang++ -I/usr/local/repos/dclib-code -std=c++11 -o $OUT "$OUT".cc
clang++ -I/usr/local/repos/dclib-code -std=c++11 -o test_matrix test_matrix.cc
/usr/bin/time -lp ./$OUT < "$OUT".in
./test_matrix < test_matrix.in
