#!/bin/bash

convert balloons.ppm -size 720x720 -crop '720x720 + 10 + 30' balloons_crop.ppm
./crop balloons.ppm croptest.ppm 10 30 730 750
convert balloons_crop.ppm croptest.ppm +append croptest1.png
echo "wrote croptest1.png"

convert balloons.ppm -size 10x100 -crop '10x100 + 20 + 100' balloons_crop.ppm
./crop balloons.ppm croptest.ppm 20 100 30 200
convert balloons_crop.ppm croptest.ppm +append croptest2.png
echo "wrote croptest2.png"

convert balloons.ppm -size 1500x2000 -crop '1500x2000 + 10 - 10' balloons_crop.ppm
./crop balloons.ppm croptest.ppm 10 -10 1510 1990
convert balloons_crop.ppm croptest.ppm +append croptest3.png
echo "wrote croptest3.png"

convert balloons.ppm -size 300x300 -crop '600x600 - 300 - 300' balloons_crop.ppm
./crop balloons.ppm croptest.ppm -300 -300 600 600
convert balloons_crop.ppm croptest.ppm +append croptest4.png
echo "wrote croptest4.png"

convert balloons.ppm -size 300x300 -crop '2500x2500 - 100 -100' balloons_crop.ppm
./crop balloons.ppm croptest.ppm -100 -100 2400 2400
convert balloons_crop.ppm croptest.ppm +append croptest5.png
echo "wrote croptest5.png"

convert balloons.ppm -size 300x300 -crop '300x300 + 500 + 500' balloons_crop.ppm
./crop balloons.ppm croptest.ppm 500 500 800 800
convert balloons_crop.ppm croptest.ppm +append croptest6.png
echo "wrote croptest6.png"

convert balloons.ppm -size 600x800 -crop '600x800 + 400 + 200' balloons_crop.ppm
./crop balloons.ppm croptest.ppm 1000 400 1000 200
convert balloons_crop.ppm croptest.ppm +append croptest7.png
echo "wrote croptest7.png"

convert balloons.ppm -size 300x10 -crop '300x10 + 0 + 90' balloons_crop.ppm
./crop balloons.ppm croptest.ppm 0 90 300 100
convert balloons_crop.ppm croptest.ppm +append croptest8.png
echo "wrote croptest8.png"

convert balloons.ppm -size 10x300 -crop '10x300 + 30 + 50' balloons_crop.ppm
./crop balloons.ppm croptest.ppm 30 50 40 350
convert balloons_crop.ppm croptest.ppm +append croptest9.png
echo "wrote croptest9.png"

convert balloons.ppm -size 65x65 -crop '65x65 + 35 + 35' balloons_crop.ppm
./crop balloons.ppm croptest.ppm 100 100 35 35
convert balloons_crop.ppm croptest.ppm +append croptest10.png
echo "wrote croptest10.png"


