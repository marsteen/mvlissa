#!/bin/sh
find ./lib/shader -name "*.shader" -exec shader2source {} \;
make -j4