#!/bin/bash

echo "========compile"
g++ $1 $2

echo "========run"
if [ $# -eq 4 ]; then
    ./a.out <$3 | tee $4
else
    ./a.out <$3
fi

