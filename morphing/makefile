INCLUDE = .
LIB     = .

morphing : morphing.cpp libimg.a video.h
	g++ -L$(LIB) -o morphing -I$(INCLUDE) morphing.cpp -limg

libimg.a : imagenES.o 
	ar rvs $(LIB)/libimg.a imagenES.o 
	
imagenES.o: imagenES.cpp imagenES.h
	g++ -g -c -o imagenES.o -I. imagenES.cpp
	
