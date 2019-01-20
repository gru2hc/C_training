CC=gcc

equation.o: equation.c
	$(CC) -c equation.c -o equation.o

equation:equation.o
	$(CC) equation.o -o equation
	
all: equation

exec: all
	./equation.exe

clean:
	rm -rf *.exe *.o
