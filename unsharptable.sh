#!/bin/bash

./unsharpmask cropballoons.ppm 1 1 blurballoons.ppm maskballoons1.ppm
convert maskballoons1.ppm maskballoons1.png
./blur maskballoons1.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask1.ppm
convert thumbnailmask1.ppm thumbnailmask1.png
echo "wrote maskballoons1.png"
echo "wrote thumbnailmask1.png"

./unsharpmask cropballoons.ppm 2 1 blurballoons.ppm maskballoons2.ppm
convert maskballoons2.ppm maskballoons2.png
./blur maskballoons2.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask2.ppm
convert thumbnailmask2.ppm thumbnailmask2.png
echo "wrote maskballoons2.png"
echo "wrote thumbnailmask2.png"

./unsharpmask cropballoons.ppm 3 1 blurballoons.ppm maskballoons3.ppm
convert maskballoons3.ppm maskballoons3.png
./blur maskballoons3.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask3.ppm
convert thumbnailmask3.ppm thumbnailmask3.png
echo "wrote maskballoons3.png"
echo "wrote thumbnailmask3.png"

./unsharpmask cropballoons.ppm 4 1 blurballoons.ppm maskballoons4.ppm
convert maskballoons4.ppm maskballoons4.png
./blur maskballoons4.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask4.ppm
convert thumbnailmask4.ppm thumbnailmask4.png
echo "wrote maskballoons4.png"
echo "wrote thumbnailmask4.png"

./unsharpmask cropballoons.ppm 1 5 blurballoons.ppm maskballoons5.ppm
convert maskballoons5.ppm maskballoons5.png
./blur maskballoons5.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask5.ppm
convert thumbnailmask5.ppm thumbnailmask5.png
echo "wrote maskballoons5.png"
echo "wrote thumbnailmask5.png"

./unsharpmask cropballoons.ppm 2 5 blurballoons.ppm maskballoons6.ppm
convert maskballoons6.ppm maskballoons6.png
./blur maskballoons6.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask6.ppm
convert thumbnailmask6.ppm thumbnailmask6.png
echo "wrote maskballoons6.png"
echo "wrote thumbnailmask6.png"

./unsharpmask cropballoons.ppm 3 5 blurballoons.ppm maskballoons7.ppm
convert maskballoons7.ppm maskballoons7.png
./blur maskballoons7.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask7.ppm
convert thumbnailmask7.ppm thumbnailmask7.png
echo "wrote maskballoons7.png"
echo "wrote thumbnailmask7.png"

./unsharpmask cropballoons.ppm 4 5 blurballoons.ppm maskballoons8.ppm
convert maskballoons8.ppm maskballoons8.png
./blur maskballoons8.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask8.ppm
convert thumbnailmask8.ppm thumbnailmask8.png
echo "wrote maskballoons8.png"
echo "wrote thumbnailmask8.png"

./unsharpmask cropballoons.ppm 1 10 blurballoons.ppm maskballoons9.ppm
convert maskballoons9.ppm maskballoons9.png
./blur maskballoons9.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask9.ppm
convert thumbnailmask9.ppm thumbnailmask9.png
echo "wrote maskballoons9.png"
echo "wrote thumbnailmask9.png"

./unsharpmask cropballoons.ppm 2 10 blurballoons.ppm maskballoons10.ppm
convert maskballoons10.ppm maskballoons10.png
./blur maskballoons10.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask10.ppm
convert thumbnailmask10.ppm thumbnailmask10.png
echo "wrote maskballoons10.png"
echo "wrote thumbnailmask10.png"

./unsharpmask cropballoons.ppm 3 10 blurballoons.ppm maskballoons11.ppm
convert maskballoons11.ppm maskballoons11.png
./blur maskballoons11.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask11.ppm
convert thumbnailmask11.ppm thumbnailmask11.png
echo "wrote maskballoons11.png"
echo "wrote thumbnailmask11.png"

./unsharpmask cropballoons.ppm 4 10 blurballoons.ppm maskballoons12.ppm
convert maskballoons12.ppm maskballoons12.png
./blur maskballoons12.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask12.ppm
convert thumbnailmask12.ppm thumbnailmask12.png
echo "wrote maskballoons12.png"
echo "wrote thumbnailmask12.png"

./unsharpmask cropballoons.ppm 1 15 blurballoons.ppm maskballoons13.ppm
convert maskballoons13.ppm maskballoons13.png
./blur maskballoons13.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask13.ppm
convert thumbnailmask13.ppm thumbnailmask13.png
echo "wrote maskballoons13.png"
echo "wrote thumbnailmask13.png"

./unsharpmask cropballoons.ppm 2 15 blurballoons.ppm maskballoons14.ppm
convert maskballoons14.ppm maskballoons14.png
./blur maskballoons14.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask14.ppm
convert thumbnailmask14.ppm thumbnailmask14.png
echo "wrote maskballoons14.png"
echo "wrote thumbnailmask14.png"

./unsharpmask cropballoons.ppm 3 15 blurballoons.ppm maskballoons15.ppm
convert maskballoons15.ppm maskballoons15.png
./blur maskballoons15.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask15.ppm
convert thumbnailmask15.ppm thumbnailmask15.png
echo "wrote maskballoons15.png"
echo "wrote thumbnailmask15.png"

./unsharpmask cropballoons.ppm 4 15 blurballoons.ppm maskballoons16.ppm
convert maskballoons16.ppm maskballoons16.png
./blur maskballoons16.ppm 8 blurballoons2.ppm
./downsize blurballoons2.ppm 8 thumbnailmask16.ppm
convert thumbnailmask16.ppm thumbnailmask16.png
echo "wrote maskballoons16.png"
echo "wrote thumbnailmask16.png"
