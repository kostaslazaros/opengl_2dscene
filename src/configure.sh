#! /bin/sh
rm -rf out/build
cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build
cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build