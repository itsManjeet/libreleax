#!/bin/sh

CPP="g++"
CPFLAGS="-fPIC -shared -I api/ -fpermissive -lstdc++fs -std=c++17 -lcurl -Wno-write-strings"
[ -d build ] && rm -rf build

mkdir -p build/{test,cache}

for lib in src/* ; do
    echo "Building $(basename $lib)"
    for f in $lib/*.cc ; do
        echo "    CC $(basename ${f%.*})"
        $CPP -c $f -o build/cache/$(basename ${f%.*}).o $CPFLAGS
        if [[ $? != 0 ]] ; then 
            echo "\n[Error $?]: while building $f"
            exit 1
        fi 
    done
done

$CPP -o build/libreleax.so build/cache/*.o $CPFLAGS
rm -rf build/cache
