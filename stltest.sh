#/bin/bash

g++ -O2 -std=c++11 stltest.cpp -o stltest
./stltest

g++ -std=c++11 stltest.cpp -o stltest
./stltest
echo "test 종료";
