#!/bin/sh

AUTOMATION_PATH='../automation'

# curl https://atcoder.jp/contests/${1}/tasks/${1}_${2} > ${AUTOMATION_PATH}/app/atcoder.html

./scraping.sh

mv ${AUTOMATION_PATH}/app/*_example_*.txt .

for i in $(ls -1 *_example_*.txt)
do
  name=$(echo $i |sed "s/example_/example_${2}_/g")
  mv $i $name
done