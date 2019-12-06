#!/bin/sh

if [[ $1 == "disk" ]] ; then 
    flags="-lblkid"
fi
g++ test/test_$1.cc -o build/test_$1 -I api -L build -lreleax $flags

LD_LIBRARY_PATH=build/ build/test_$1 $2