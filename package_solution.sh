#!/bin/bash

for p in $(find $(seq $1 $2) -maxdepth 0 -type d)
do
    echo "working on problem $p"
    cd $p
    
    cp program.java "$p.java"
    cp solution.cpp "$p.cpp"
    zip "../exports/solutions/java.zip" "$p.java"
    zip "../exports/solutions/cpp.zip" "$p.cpp"
    zip "../exports/solutions/python.zip" "$p.py"
    rm -f "$p.java"
    rm -f "$p.cpp"

    cd ..
done