INCLUDE = .
LIB     = .

contraste : contraste.cpp libimg.a
	g++ -L$(LIB) -o contraste -I$(INCLUDE) contraste.cpp -limg

libimg.a : imagenES.o 
	ar rvs $(LIB)/libimg.a imagenES.o 
	
imagenES.o: imagenES.cpp imagenES.h
	g++ -g -c -o imagenES.o -I. imagenES.cpp
	
