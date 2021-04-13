#!/bin/bash

for p in $(find $(seq $1 $2) -maxdepth 0 -type d)
do
    echo "working on problem $p"
    cd $p
    
    g++ solution.cpp -o solution -O2
    for c in cases/*.in
    do
        fn=${c##*/}
        num=${fn%.in}

        cat $c | ./solution > cases/"$num.out"
    done

    cd ..
done