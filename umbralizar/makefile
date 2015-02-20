INCLUDE = .
LIB     = .

umbralizar : umbralizar.cpp libimg.a
	g++ -L$(LIB) -o umbralizar -I$(INCLUDE) umbralizar.cpp -limg

libimg.a : imagenES.o 
	ar rvs $(LIB)/libimg.a imagenES.o 
	
imagenES.o: imagenES.cpp imagenES.h
	g++ -g -c -o imagenES.o -I. imagenES.cpp
	
