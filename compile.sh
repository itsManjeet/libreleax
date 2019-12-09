#!/bin/sh

CPP="g++"
CPFLAGS="-fPIC -shared -I api/ -fpermissive `pkg-config --libs --cflags gtkmm-3.0` -lstdc++fs -std=c++17 -lcurl"
[ -d build ] && rm -rf build

mkdir -p build/{test,cache}

for lib in src/* ; do
    echo "Building $(basename $lib)"
    for f in $lib/*.cc ; do
        echo "    CC $(basename ${f%.*})"
        $CPP -c $f -o build/cache/$(basename ${f%.*}).o $CPFLAGS
    done
done

$CPP -o build/libreleax.so build/cache/*.o $CPFLAGS
rm -rf build/cache