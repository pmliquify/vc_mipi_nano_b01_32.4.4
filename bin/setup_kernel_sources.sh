#!/bin/bash
#
# Read this for more details
# https://docs.nvidia.com/jetson/l4t/index.html#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/kernel_custom.html#
#
source configure.sh

if [ ! -f "$L4T_TMP_DIR/$L4T_DRV_FILE" ] ; then
    echo "Downloading the Driver Package Sources ..."
    cd $L4T_TMP_DIR
    wget $L4T_DRV_URL/$L4T_DRV_FILE
fi

if [ ! -f "$L4T_TMP_DIR/$L4T_SRC_FILE" ] ; then
    echo "Downloading the Kernel Sources ..."
    cd $L4T_TMP_DIR
    wget $L4T_SRC_URL/$L4T_SRC_FILE
fi

if [ ! -f "$L4T_TMP_DIR/$L4T_RFS_FILE" ] ; then
    echo "Downloading the Sample Root Filesystem ..."
    cd $L4T_TMP_DIR
    wget $L4T_RFS_URL/$L4T_RFS_FILE
fi

if [ ! -d "$L4T_BUILD_DIR/Linux_for_Tegra" ] ; then
    echo "Extracting files ..."
    tar xjf $L4T_TMP_DIR/$L4T_DRV_FILE -C $L4T_DRV_DIR
    tar xjf $L4T_TMP_DIR/$L4T_SRC_FILE -C $L4T_SRC_DIR
    cd $L4T_BUILD_DIR/Linux_for_Tegra/source/public
    tar xf kernel_src.tbz2
    tar xjf $L4T_TMP_DIR/$L4T_RFS_FILE -C $L4T_RFS_DIR
    echo "Extraction of $L4T_DRV_FILE and $L4T_SRC_FILE completed"
fi