#!/bin/sh

execfile="./${1}.out"

filenum=$(ls -1 input_example_${1}_* |wc -l |sed "s/ //g")

echo "expected, output"
for i in `seq 1 ${filenum}`
do
  echo "example ${i} ----"
  input_example_filename="input_example_${i}.txt"
  output_example_filename="output_example_${i}.txt"
  output_filename="output_${1}_${i}.txt"
  $execfile < $input_example_filename > $output_filename
  diff -y --suppress-common-lines $output_example_filename $output_filename
done

exit 0
