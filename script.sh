#!/bin/bash

PATH_TO_HEADER=$1
PATH_TO_LIB=$2

echo 'compiling AXPY_H.cpp, the result is runH :'

g++ AXPY_H.cpp -g -I $PATH_TO_HEADER -L $PATH_TO_LIB -lHalide -lpthread -ldl -o runH -std=c++11

echo 'running runH, the result is a file results_H.txt :'

sudo LD_LIBRARY_PATH=$PATH_TO_LIB ./runH

echo 'compiling AXPY_C.c, the result is runC :'

gcc AXPY_C.c -o runC

echo 'running runC, the result is a file results_C.txt : '

sudo ./runC

echo 'Comparing the two files  results_C.txt and results_H.txt using Diff : '

diff  -s results_C.txt results_H.txt 