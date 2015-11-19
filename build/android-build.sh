#!/bin/bash

cd conqueror
ndk-build NDK_PROJECT_PATH=. NDK_APPLICATION_MK=Application.mk

rm -rf obj && cp -R libs ../output && rm -rf libs

cd -