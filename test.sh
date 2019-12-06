#!/bin/sh

g++ test/test_$1.cc -o build/test_$1 -I api -L build -lreleax 

LD_LIBRARY_PATH=build/ build/test_$1 $2