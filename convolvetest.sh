#!/bin/bash

./convolve cropballoons.ppm filters/target25.ppm balloonstarget.ppm
composite filters/target25.ppm cropballoons.ppm -gravity SouthWest balloons_target.ppm
convert balloons_target.ppm balloonstarget.ppm +append convexamples/balloonstarget.png
echo "wrote balloonstarget.png"

./convolve cropballoons.ppm filters/whitetriangle21.ppm balloonstriangle.ppm
composite filters/whitetriangle21.ppm cropballoons.ppm -gravity SouthWest balloons_triangle.ppm
convert balloons_triangle.ppm balloonstriangle.ppm +append convexamples/balloonstriangle.png
echo "wrote balloonstriangle.png"

./convolve cropballoons.ppm filters/11x11.ppm balloonsx11.ppm
composite filters/11x11.ppm cropballoons.ppm -gravity SouthWest balloons_x11.ppm
convert balloons_x11.ppm balloonsx11.ppm +append convexamples/balloonsx11.png
echo "wrote balloonsx11.png"

./convolve cat.ppm filters/whiteheart25.ppm catheart.ppm
composite filters/whiteheart25.ppm cat.ppm -gravity SouthWest cat_heart.ppm
convert cat_heart.ppm catheart.ppm +append convexamples/catheart.png
echo "wrote catheart.png"

./convolve cat.ppm filters/graysmiley35.ppm catsmiley.ppm
composite filters/graysmiley35.ppm cat.ppm -gravity SouthWest cat_smiley.ppm
convert cat_smiley.ppm catsmiley.ppm +append convexamples/catsmiley.png
echo "wrote catsmiley.png"

./convolve cat.ppm filters/whitex21.ppm catx.ppm
composite filters/whitex21.ppm cat.ppm -gravity SouthWest cat_x.ppm
convert cat_x.ppm catx.ppm +append convexamples/catx.png
echo "wrote catx.png"

./convolve filters/whiteplus21.ppm filters/5x5.ppm plus5x5.ppm
composite filters/5x5.ppm filters/whiteplus21.ppm -gravity SouthWest plus_5x5.ppm
convert plus_5x5.ppm plus5x5.ppm +append convexamples/plus5x5.png
echo "wrote plus5x5.png"

./convolve filters/graysmiley35.ppm filters/5x5.ppm smiley5x5.ppm
composite filters/5x5.ppm filters/graysmiley35.ppm -gravity SouthWest smiley_5x5.ppm
convert smiley_5x5.ppm smiley5x5.ppm +append convexamples/smiley5x5.png
echo "wrote smiley5x5.png"

./convolve filters/target25.ppm filters/5x5.ppm target5x5.ppm
composite filters/5x5.ppm filters/target25.ppm -gravity SouthWest target_5x5.ppm
convert target_5x5.ppm target5x5.ppm +append convexamples/target5x5.png
echo "wrote target5x5.png"

./convolve filters/yinyang25.ppm filters/5x5.ppm yinyang5x5.ppm
composite filters/5x5.ppm filters/yinyang25.ppm -gravity SouthWest yinyang_5x5.ppm
convert yinyang_5x5.ppm yinyang5x5.ppm +append convexamples/yinyang5x5.png
echo "wrote yinyang5x5.png"
