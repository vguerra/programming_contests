#!/bin/sh

for question in q1 q2 q3 q4 q5; do
  clang -g -o $question $question.c
done; 