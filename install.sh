#!/bin/bash

mkdir -p build
cd build

if [[ "$OSTYPE" == "linux-gnu" ]];
then
    if [[ `awk -F= '$1=="ID" { print $2 ;}' /etc/os-release` == "ubuntu" ]];
    then
        sudo apt update
        sudo apt upgrade -y
        sudo apt install -y \
        cmake \
        build-essential \
        python3-pip \
        libudev-dev \
        libgl-dev \
        libx11-xcb-dev \
        libfontenc-dev \
        libxaw7-dev \
        libxcomposite-dev \
        libxcursor-dev \
        libxdamage-dev \
        libxfixes-dev \
        libxi-dev \
        libxinerama-dev \
        libxmu-dev \
        libxmuu-dev \
        libxpm-dev \
        libxrandr-dev \
        libxres-dev \
        libxss-dev \
        libxtst-dev \
        libxv-dev \
        libxvmc-dev \
        libxxf86vm-dev \
        libxcb-render-util0-dev \
        libxcb-xkb-dev \
        libxcb-icccm4-dev \
        libxcb-image0-dev \
        libxcb-keysyms1-dev \
        libxcb-randr0-dev \
        libxcb-shape0-dev \
        libxcb-sync-dev \
        libxcb-xfixes0-dev \
        libxcb-xinerama0-dev \
        libxcb-dri3-dev \
        libxcb-util-dev \
        libxcb-util0-dev
        sudo pip3 install conan

        conan install .. --build=missing -s compiler.libcxx=libstdc++11 -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
        cmake ..
        make
        cd bin
        cp -r r-type_server ../../bin/linux/
        cp -r r-type_client ../../bin/linux/
    elif [[ `awk -F= '$1=="ID" { print $2 ;}' /etc/os-release` == "fedora" ]];
    then
        sudo dnf update -y
        sudo dnf install -y \
        cmake \
        python3-pip \
        libudev-devel \
        libfontenc-devel \
        libXaw-devel \
        libXcomposite-devel \
        libXdmcp-devel \
        libXtst-devel \
        libxkbfile-devel \
        libXres-devel \
        libXScrnSaver-devel \
        libXvMC-devel \
        xorg-x11-xtrans-devel \
        xcb-util-wm-devel \
        xcb-util-keysyms-devel \
        xcb-util-renderutil-devel \
        libXdamage-devel \
        xcb-util-devel \
        xkeyboard-config-devel \
        systemd-devel \
        libuuid-devel
        sudo pip3 install conan

        conan install .. --build=missing -s compiler.libcxx=libstdc++11 -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
        cmake ..
        make
        cd bin
        cp -r r-type_server ../../bin/linux/
        cp -r r-type_client ../../bin/linux/
    fi
fi