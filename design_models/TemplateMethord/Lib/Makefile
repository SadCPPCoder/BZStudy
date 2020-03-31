CC:=g++
PWD:=$(shell pwd)
STD:=c++11
CFLAG:= -fPIC

all: static_lib shared_lib

static_lib: build
	ar rcs libSoupRecipe.a SoupRecipe.o
	
shared_lib: build
	$(CC) -shared -o libSoupRecipe.so SoupRecipe.o

build:
    # If we want to build a shared library, we sould add -fPIC when
    # build the .o file.
	$(CC) -c SoupRecipe.cpp -std=$(STD) -fPIC

clean:
	rm *.o *.a *.so 
