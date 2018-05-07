#!/bin/bash
# Script for OpenCV instalation.
# OS Compatiable: Ubuntu 16.04.XX
clear

color_green="$(tput setaf 2)"
color_standard="$(tput sgr 0)"

echo "${color_green}Install OpenCV 3.4${color_standard}"
echo -e "\n${color_green}Update the repository packages${color_standard}"
sudo apt update;

echo -e "\n${color_green}Install essential packages${color_standard}"
sudo apt install build-essential;

echo -e "\n${color_green}Install required packages${color_standard}"
sudo apt install cmake git libgtk2.0-dev pkg-config libavcodec-dev \
  libavformat-dev libswscale-dev;

echo -e "\n${color_green}Checkout OpenCV 3.4${color_standard}"
git clone https://github.com/opencv/opencv.git -b 3.4

mkdir opencv/build
cd opencv/build

echo -e "\n${color_green}Start CMAKE${color_standard}"
cmake ..

echo -e "\n${color_green}Start MAKE${color_standard}"
make -j

echo -e "\n${color_green}Start MAKE install${color_standard}"
sudo make install

opencv_version=$(pkg-config opencv --modversion)
echo -e "\n${color_green}Installed OpenCV $opencv_version ${color_standard}"
