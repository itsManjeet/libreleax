#!/bin/sh

g++ $(find src -name "*.cc" -type f) -o build/libreleax.so -fPIC -shared -I api/ -fpermissive `pkg-config --libs --cflags gtkmm-3.0`