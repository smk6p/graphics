#!/bin/bash

convert -size 300x300 xc: -draw 'line 10,30 80,50' im.png
./drawline white.ppm linetest.ppm 10 30 80 50 0 0 0 1
convert im.png linetest.ppm +append linetest1.png
echo "wrote linetest1.png"

convert -size 300x300 xc: -draw 'stroke red line 100,30 20,200' im.png
./drawline white.ppm linetest.ppm 100 30 20 200 255 0 0 1
convert im.png linetest.ppm +append linetest2.png
echo "wrote linetest2.png"

convert -size 300x300 xc: -draw 'line 200,10 35,51' im.png
./drawline white.ppm linetest.ppm 200 10 35 51 0 0 0 1
convert im.png linetest.ppm +append linetest3.png
echo "wrote linetest3.png"

convert -size 300x300 xc: -draw 'line 200,10 335,151' im.png
./drawline white.ppm linetest.ppm 200 10 335 151 0 0 0 1
convert im.png linetest.ppm +append linetest4.png
echo "wrote linetest4.png"

convert -size 300x300 xc: -draw 'line 200,10 35,5' im.png
./drawline white.ppm linetest.ppm 200 10 35 5 0 0 0 1
convert im.png linetest.ppm +append linetest5.png
echo "wrote linetest5.png"

convert -size 300x300 xc: -draw 'line 300,300 -100,-100' im.png
./drawline white.ppm linetest.ppm 300 300 -100 -100 0 0 0 1
convert im.png linetest.ppm +append linetest6.png
echo "wrote linetest6.png"

convert -size 300x300 xc: -draw 'line 200,10 200,451' im.png
./drawline white.ppm linetest.ppm 200 10 200 451 0 0 0 1
convert im.png linetest.ppm +append linetest7.png
echo "wrote linetest7.png"

convert -size 300x300 xc: -draw 'line 200,100 50,51' im.png
./drawline white.ppm linetest.ppm 200 100 50 51 0 0 0 1
convert im.png linetest.ppm +append linetest8.png
echo "wrote linetest8.png"

convert -size 300x300 xc: -draw 'stroke green line 20,10 35,5' im.png
./drawline white.ppm linetest.ppm 200 10 35 51 0 255 0 1
convert im.png linetest.ppm +append linetest9.png
echo "wrote linetest9.png"

convert -size 300x300 xc: -draw 'line 100,100 35,35' im.png
./drawline white.ppm linetest.ppm 100 100 35 35 0 0 0 1
convert im.png linetest.ppm +append linetest10.png
echo "wrote linetest10.png"


