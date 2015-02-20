INCLUDE = .
LIB     = .

zoom : zoom.cpp libimg.a
	g++ -L$(LIB) -o zoom -I$(INCLUDE) zoom.cpp -limg

libimg.a : imagenES.o 
	ar rvs $(LIB)/libimg.a imagenES.o 
	
imagenES.o: imagenES.cpp imagenES.h
	g++ -g -c -o imagenES.o -I. imagenES.cpp
	
