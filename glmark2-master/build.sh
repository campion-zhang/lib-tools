#!/bin/bash

if [[ -a build ]]; then
	rm -rf build
fi

myPath=`pwd`
./waf configure --with-flavors=x11-gl --data-path=$myPath/data
./waf -j8
