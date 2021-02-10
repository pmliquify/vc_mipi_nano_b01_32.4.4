#!/bin/bash
#
# Read this for more details
# https://docs.nvidia.com/jetson/l4t/index.html#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/xavier_toolchain.html#
#
source configure.sh

apt install build-essential bc python

if [ ! -f "$L4T_TMP_DIR/$L4T_GCC_FILE" ] ; then
    echo "Downloading the Toolchain ..."
    cd $L4T_TMP_DIR
    wget $L4T_GCC_URL/$L4T_GCC_FILE
fi

if [ ! -d "$L4T_GCC_DIR" ] ; then  
    mkdir $L4T_GCC_DIR
    echo "Extracting files ..."
    tar xf $L4T_TMP_DIR/$L4T_GCC_FILE -C $L4T_GCC_DIR
    echo "Extraction of $L4T_GCC_FILE completed"
fi