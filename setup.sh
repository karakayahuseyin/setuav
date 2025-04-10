#!/bin/bash

# This script sets up the environment for the project by installing necessary packages and dependencies.
# It is designed to be run in a Ubuntu 22.04 environment. For Windows you can use setup.bat.
# It is recommended to run this script with root privileges.

# Update the package list
sudo apt update

sudo apt-get -y install build-essential git cmake

# Install GLFW
sudo apt-get -y install libglfw3-dev

# OpenCASCADE dependencies
sudo apt-get -y install tcl tcl-dev tk tk-dev libfreeimage-dev
sudo apt-get -y install libxmu-dev libxi-dev
sudo apt-get -y install libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev
sudo apt-get -y install xvfb

# ===========================================================
#  Clone OpenCascade from its public repo, build and install
# ===========================================================

# OpenCascade
git clone https://github.com/Open-Cascade-SAS/OCCT.git Source/Lib/OpenCASCADE
cd Source/Lib/OpenCASCADE
git checkout V7_8_1 -b dev-branch
mkdir -p build
cd build
cmake .. \
    -DCMAKE_BUILD_TYPE=release \
    -DCMAKE_INSTALL_RPATH="" \
    -DCMAKE_INSTALL_PREFIX=../install \
    -DUSE_FREEIMAGE=OFF \
    -DUSE_FFMPEG=OFF \
    -DUSE_VTK=OFF \
    -DUSE_TBB=OFF
make -j$(nproc)
make install