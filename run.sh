#!/bin/sh

mkdir -p build
g++ -Werror -Wall -Wextra -pedantic -std=c++17 -Isrc src/main.cpp -o build/main
