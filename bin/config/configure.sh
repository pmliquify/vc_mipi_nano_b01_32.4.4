#!/bin/bash

WORKING_DIR=$(dirname $PWD)
BIN_DIR=$WORKING_DIR/bin

print_jetpack_version_definition() {
    echo "Jetpack version not $1!"
    echo "Please set VC_MIPI to one of the possible options."
    echo "  $ export VC_MIPI=45a"
    echo "Options:"
    echo "  43  : Jetpack 4.3   for NVIDIA Dev Kit B01"
    echo "  43a : Jetpack 4.3   for Auvidea JNX30"
    echo "  441 : Jetpack 4.4.1 for NVIDIA Dev Kit B01"
    echo "  45a : Jetpack 4.5   for Auvidea JNX30"
}

if [[ -z $VC_MIPI ]]; then
    print_jetpack_version_definition "defined"
    exit 1
fi

case $VC_MIPI in
    43)   . $BIN_DIR/config/config_JP4.3.sh ;;
    43a)  . $BIN_DIR/config/config_JP4.3_auvidea.sh ;; 
    441)  . $BIN_DIR/config/config_JP4.4.1.sh ;;
    45a)  . $BIN_DIR/config/config_JP4.5_auvidea.sh ;;
    *) 
        print_jetpack_version_definition "supported"
        exit 1
        ;;
esac

BUILD_DIR=$WORKING_DIR/build/jp$JP_VERSION
PATCH_DIR=$WORKING_DIR/patch/$JP_VERSION
SRC_DIR=$WORKING_DIR/src/$JP_VERSION
TMP_DIR=$BUILD_DIR/downloads
GCC_DIR=$BUILD_DIR/toolchain
KERNEL_SOURCE=$BUILD_DIR/Linux_for_Tegra/source/public
KERNEL_OUT=$KERNEL_SOURCE/build
MODULES_OUT=$KERNEL_SOURCE/modules

export CROSS_COMPILE=$GCC_DIR/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
export LOCALVERSION=-tegra
export ARCH=arm64

TARGET_IP=nano
TARGET_USER=peter
TARGET_SHELL="ssh $TARGET_USER@$TARGET_IP"
# TARGET_BOARD=jetson-nano-devkit
TARGET_BOARD=jetson-nano-emmc