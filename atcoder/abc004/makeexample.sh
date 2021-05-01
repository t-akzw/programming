#!/bin/sh

EXAMPATH='./examples'

mkdir -p $EXAMPATH

[[ $1 == '' ]] && echo "please input (ex.3 example number)" && exit 1
[[ $2 == '' ]] && echo "please input (ex.a-f)" && exit 1

for i in `seq 1 ${1}`
do
  touch "${EXAMPATH}/i_${2}_${i}"
  touch "${EXAMPATH}/o_${2}_${i}"
done