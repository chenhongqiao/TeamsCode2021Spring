#!/bin/bash

for p in $(find $(seq $1 $2) -maxdepth 0 -type d)
do
    echo "working on problem $p"
    cd $p
    rm -rf tests
    mkdir tests
    
    g++ solution.cpp -o solution -O2
    javac program.java

    excep=false
    for c in cases/*.in
    do
        fn=${c##*/}
        num=${fn%.in}

        cat $c | java program > tests/"$num-java.out"
        cat $c | ./solution > tests/"$num-cpp.out"
        cat $c | python "$p.py" > tests/"$num-python.out"

        if [[ $(diff -Z tests/"$num-java.out" tests/"$num-cpp.out") || $(diff -Z tests/"$num-python.out" tests/"$num-cpp.out") ]]
        then
            echo "exception occured on testcase $num"
            echo "ending generation on problem $p"
            excep=true
            break
        fi
    done
    
    if [[ "$excep" = true ]]
    then
        echo "================================"
        continue
    fi

    echo "solution test passed"

    for c in cases/*.in
    do
        fn=${c##*/}
        num=${fn%.in}

        cp tests/"$num-cpp.out" cases/"$num.out"
    done

    echo "output cases generated, clearing up"
    rm -rf tests
    echo "================================"

    cd ..
done