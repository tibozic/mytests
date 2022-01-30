CC=gcc
CFLAGS=-std=c99 -Wall -Wextra

libname=mytests
path=/home/billy/Documets/Projects/c/mytests

libraries=-lmytests
# libpaths=-L/home/billy/Documents/Projects/c/xlib/ -L/home/billy/Documents/Projects/c/myfiles

name=main

library: $(libname).c
	$(CC) $(CFLAGS) -c -fpic $(libname).c
	$(CC) -shared -o lib$(libname).so $(libname).o
	$(CC) -L$(path) -o $(name).o $(name).c $(libraries)
	sudo cp lib$(libname).so /usr/lib/
	sudo cp $(libname).h /usr/include/
	sudo ldconfig
	#now you need to copy the library.so file to standard library path (/usr/lib)
	#also copy the .h file to /usr/includes
	#then you need to run ldconfig
	#https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html


compile: $(name).c
	$(CC) $(CFLAGS) -o $(name).o $(name).c $(libraries)

run: compile $(name.o)
	./$(name).o

clean:
	rm *.o *.so
