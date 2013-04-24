#!/bin/bash

echo "enter image:"
read image
echo "enter downsize factor:"
read factor
echo "enter 1st output file:"
read out
echo "enter 2nd output file:"
read out2
./blur $image $factor $out
./downsize $out $factor $out2
echo "wrote $out2"
