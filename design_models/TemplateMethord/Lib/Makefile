CC:=g++
PWD:=$(shell pwd)
STD:=c++11
CFLAG:= -fPIC

all: static_lib shared_lib

static_lib: build
	ar rcs libSoupRecipe.a SoupRecipe.o
	
shared_lib: build
	$(CC) -shared -fPIC -o libSoupRecipe.so SoupRecipe.o

build:
	$(CC) -c SoupRecipe.cpp -std=$(STD)

clean:
	rm *.o *.a *.so 
