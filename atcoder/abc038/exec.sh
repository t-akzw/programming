#!/bin/sh

EXAMPATH='./examples'
OUTPATH='./outputs'

mkdir -p $OUTPATH

[[ $1 == '' ]] && echo "please input (ex.a-f)" && exit 1

execfile="./${1}.out"

filenum=$(ls -1 ${EXAMPATH}/i_${1}_* |wc -l |sed "s/ //g")

echo "expected, output"
for i in `seq 1 ${filenum}`
do
  echo "example ${i} ----"
  input_example_filename="${EXAMPATH}/i_${1}_${i}"
  output_example_filename="${EXAMPATH}/o_${1}_${i}"
  output_filename="${OUTPATH}/o_${1}_${i}"
  $execfile < $input_example_filename > $output_filename
  diff -y --suppress-common-lines $output_example_filename $output_filename
done

exit 0
