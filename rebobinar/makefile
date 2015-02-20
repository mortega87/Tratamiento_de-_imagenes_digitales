INCLUDE = .
LIB     = .

rebobinar : rebobinar.cpp libimg.a video.h
	g++ -L$(LIB) -o rebobinar -I$(INCLUDE) rebobinar.cpp -limg

libimg.a : imagenES.o 
	ar rvs $(LIB)/libimg.a imagenES.o 
	
imagenES.o: imagenES.cpp imagenES.h
	g++ -g -c -o imagenES.o -I. imagenES.cpp
	
