#!/bin/bash

atest[0]='one'
atest[1]='one'

echo "print array: "
echo ${atest[@]}

echo "array size: "
echo ${#atest[*]}
