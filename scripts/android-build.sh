#!/bin/bash

set -e

cd conqueror
ndk-build NDK_PROJECT_PATH=. NDK_APPLICATION_MK=Application.mk
rm -rf obj && rm -rf ../output/jniLibs && cp -R libs ../output && rm -rf libs && mv ../output/libs ../output/jniLibs
cd -

# test
cp -r ./output/jniLibs ./samples/AndroidDemo/app/src/main