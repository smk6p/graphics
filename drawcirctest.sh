#!/bin/bash

convert -size 300x300 xc: -draw 'circle 50,80 50,110' im.png
./drawcirc white.ppm circtest.ppm 50 80 30 0 0 0 1
convert im.png circtest.ppm +append circtest1.png
echo "wrote circtest1.png"

convert -size 300x300 xc: -draw 'circle 100,30 100,0' im.png
./drawcirc white.ppm circtest.ppm 100 30 30 0 0 0 1
convert im.png circtest.ppm +append circtest2.png
echo "wrote circtest2.png"

convert -size 300x300 xc: -draw 'circle 200,200 200,410' im.png
./drawcirc white.ppm circtest.ppm 200 200 210 0 0 0 1
convert im.png circtest.ppm +append circtest3.png
echo "wrote circtest3.png"

convert -size 300x300 xc: -draw 'circle 10,10 10,150' im.png
./drawcirc white.ppm circtest.ppm 10 10 140 0 0 0 1
convert im.png circtest.ppm +append circtest4.png
echo "wrote circtest4.png"

convert -size 300x300 xc: -draw 'circle 200,10 200,5' im.png
./drawcirc white.ppm circtest.ppm 200 10 5 0 0 0 1
convert im.png circtest.ppm +append circtest5.png
echo "wrote circtest5.png"

convert -size 300x300 xc: -draw 'circle 150,150 150,310' im.png
./drawcirc white.ppm circtest.ppm 150 150 160 0 0 0 1
convert im.png circtest.ppm +append circtest6.png
echo "wrote circtest6.png"

convert -size 300x300 xc: -draw 'circle 200,10 200,51' im.png
./drawcirc white.ppm circtest.ppm 200 10 41 0 0 0 1
convert im.png circtest.ppm +append circtest7.png
echo "wrote circtest7.png"

convert -size 300x300 xc: -draw 'circle -20,-10 -20,60' im.png
./drawcirc white.ppm circtest.ppm -20 -10 70 0 0 0 1
convert im.png circtest.ppm +append circtest8.png
echo "wrote circtest8.png"

convert -size 300x300 xc: -draw 'circle 20,10 35,10' im.png
./drawcirc white.ppm circtest.ppm 20 10 15 0 0 0 1
convert im.png circtest.ppm +append circtest9.png
echo "wrote circtest9.png"

convert -size 300x300 xc: -draw 'circle 100,100 35,100' im.png
./drawcirc white.ppm circtest.ppm 100 100 65 0 0 0 1
convert im.png circtest.ppm +append circtest10.png
echo "wrote circtest10.png"


