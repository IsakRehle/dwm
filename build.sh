#!/bin/sh

make clean && rm -f config.h
make
sudo make install
