#!/bin/sh

for i in `seq 1 ${1}`
do
  touch "input_example_${2}_${i}.txt"
  touch "output_example_${2}_${i}.txt"
done