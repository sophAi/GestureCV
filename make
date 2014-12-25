#!/bin/bash
EXEC_NAME=`echo ${PWD##*/}`
PWD_DIR=`pwd`
LIB_DIR=$PWD_DIR/lib
BIN_DIR=$PWD_DIR/bin
SRC_DIR=$PWD_DIR/src
DAT_DIR=$PWD_DIR/dat
DOC_DIR=$PWD_DIR/doc
MODULE_DIR=$PWD_DIR/modules
CMAKE_DIR=$PWD_DIR/find.cmake
MAKE_TEMP_DIR=$PWD_DIR/tmp_build
if [ "$1" == "" ]; then
	echo -e " "
	echo -e "SHELL: Building" $EXEC_NAME"..."
	echo -e " "
	test -d $LIB_DIR || mkdir $LIB_DIR
	test -d $BIN_DIR || mkdir $BIN_DIR
	test -d $MAKE_TEMP_DIR || mkdir $MAKE_TEMP_DIR
#	mkdir -p $MAKE_TEMP_DIR  # -p no error if existing
	cd $MAKE_TEMP_DIR
	cmake $@ ..

	if [ "$?" == "0" ]; then
		make
		if [ "$?" == "0" ]; then
			echo -e " "
			echo -e	"SHELL: Build Succeeded!"
		fi
		exit 0
	else
		echo -e " "
		echo -e "SHELL: Build Failed!"
		exit 1
	fi
fi



if [ "$1" == "clean" ]; then
	echo -e " "
	echo -e "SHELL: Cleaning" $EXEC_NAME"..."
	echo -e " "
	test -d $BIN_DIR && rm -rf $BIN_DIR/*
	test -d $LIB_DIR && rm -rf $LIB_DIR/*
	test -d $MAKE_TEMP_DIR && rm -rf $MAKE_TEMP_DIR/*
	echo -e "SHELL: Clean Succeeded!"	
fi

