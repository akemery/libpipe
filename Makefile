all: pipe.o libpipe.so libpipe.a main.o

pipe.o: pipe.c
	gcc -c -fPIC pipe.c -o pipe.o

libpipe.so: pipe.o
	gcc -shared pipe.o -o libpipe.so

libpipe.a: pipe.o
	ar rcs libpipe.a pipe.o
main.o: main.c
	gcc main.c -L. -lpipe -o pipe

clean:
	rm *.o
	rm *.so
	rm *.a
