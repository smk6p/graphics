#!/bin/bash

convert -size 300x300 xc: -draw 'rectangle 10,30 80,50' im.png
./drawrect white.ppm recttest.ppm 10 30 50 80 0 0 0 1
convert im.png recttest.ppm +append recttest1.png
echo "wrote recttest1.png"

convert -size 300x300 xc: -draw 'rectangle 100,30 20,200' im.png
./drawrect white.ppm recttest.ppm 20 100 30 200 0 0 0 1
convert im.png recttest.ppm +append recttest2.png
echo "wrote recttest2.png"

convert -size 300x300 xc: -draw 'rectangle -10,10 35,100' im.png
./drawrect white.ppm recttest.ppm 10 100 -10 35 0 0 0 1
convert im.png recttest.ppm +append recttest3.png
echo "wrote recttest3.png"

convert -size 300x300 xc: -draw 'rectangle 200,10 335,151' im.png
./drawrect white.ppm recttest.ppm 10 151 200 335 0 0 0 1
convert im.png recttest.ppm +append recttest4.png
echo "wrote recttest4.png"

convert -size 300x300 xc: -draw 'rectangle -10,-10 250,350' im.png
./drawrect white.ppm recttest.ppm -10 350 -10 250 0 0 0 1
convert im.png recttest.ppm +append recttest5.png
echo "wrote recttest5.png"

convert -size 300x300 xc: -draw 'rectangle 30,300 100,-100' im.png
./drawrect white.ppm recttest.ppm -100 300 30 100 0 0 0 1
convert im.png recttest.ppm +append recttest6.png
echo "wrote recttest6.png"

convert -size 300x300 xc: -draw 'rectangle 100,10 200,451' im.png
./drawrect white.ppm recttest.ppm 10 451 100 200 0 0 0 1
convert im.png recttest.ppm +append recttest7.png
echo "wrote recttest7.png"

convert -size 300x300 xc: -draw 'rectangle 200,100 50,51' im.png
./drawrect white.ppm recttest.ppm 51 100 50 200 0 0 0 1
convert im.png recttest.ppm +append recttest8.png
echo "wrote recttest8.png"

convert -size 300x300 xc: -draw 'rectangle 20,10 35,5' im.png
./drawrect white.ppm recttest.ppm 5 10 20 35 0 0 0 1
convert im.png recttest.ppm +append recttest9.png
echo "wrote recttest9.png"

convert -size 300x300 xc: -draw 'rectangle 100,100 35,35' im.png
./drawrect white.ppm recttest.ppm 35 100 35 100 0 0 0 1
convert im.png recttest.ppm +append recttest10.png
echo "wrote recttest10.png"


