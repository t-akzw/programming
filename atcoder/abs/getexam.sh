#!/bin/sh

AUTOMATION_PATH='../automation'
EXAMPATH='./examples'

[[ $1 == '' ]] && echo "please input (ex.abc001)" && exit 1
[[ $2 == '' ]] && echo "please input (ex.a-f)" && exit 1
[[ $3 == 'curl' ]] && curl https://atcoder.jp/contests/abs/tasks/${1}_${2} > ${AUTOMATION_PATH}/app/atcoder.html

./scraping.sh

mkdir -p $EXAMPATH
mv ${AUTOMATION_PATH}/app/*_example_*.txt $EXAMPATH

for i in $(ls -1 $EXAMPATH/*_example_*.txt)
do
  name=$(echo $i |sed "s/.*\/\([i|o]\).*_example_\([0-9]\)\.txt/\1_${2}_\2/g")
  mv $i $EXAMPATH/$name
done