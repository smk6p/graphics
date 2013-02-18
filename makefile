
CFLAGS = -ggdb -Wall

%.o : %.cc
	gcc -c -o $@ $< $(CFLAGS) 

ramp: ramp.o
	gcc -o ramp ramp.o

constant: constant.o ppm.o util.o
	gcc -o constant constant.o ppm.o util.o

img2gray: img2gray.o ppm.o
	gcc -o img2gray img2gray.o ppm.o

noise: noise.o ppm.o util.o
	gcc -o noise noise.o ppm.o util.o

drawcirc: drawcirc.o ppm.o util.o draw2D.o
	gcc -o drawcirc drawcirc.o ppm.o util.o draw2D.o

drawline: drawline.o ppm.o util.o
	gcc -o drawline drawline.o ppm.o util.o

drawrect: drawrect.o ppm.o util.o draw2D.o
	gcc -o drawrect drawrect.o ppm.o util.o draw2D.o

strcmptest: strcmptest.o util.o
	gcc -o strcmptest strcmptest.o util.o

drawcirctest: drawcirctest.o ppm.o util.o draw2D.o
	gcc -o drawcirctest drawcirctest.o ppm.o util.o draw2D.o

drawrecttest: drawrecttest.o ppm.o util.o draw2D.o
	gcc -o drawrecttest drawrecttest.o ppm.o util.o draw2D.o

clean:
	rm -f *.o
