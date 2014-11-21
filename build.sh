#!/bin/bash
EXEC_NAME=`echo ${PWD##*/}`
echo -e "Building" $EXEC_NAME
mkdir -p make_temp_dir
cd make_temp_dir
cmake $@ ..

if [ "$?" == "0" ]; then
	make
	exit 0
else
	echo cmake exit $?
	exit 1
fi
