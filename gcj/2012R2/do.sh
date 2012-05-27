#!/bin/bash

echo "========compile"
g++ $1

if [ $# -eq 3 ]; then
    echo "========run"
    ./a.out <$2 | tee $3
elif [ $# -eq 2 ]; then
    echo "========run"
    ./a.out <$2
fi

