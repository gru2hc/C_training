CC=gcc

msnv.o: msnv.c
	$(CC) -c msnv.c -o msnv.o

msnv:msnv.o
	$(CC) msnv.o -o msnv
	
all: msnv

exec:
	msnv

clean:
	rm -rf *.exe *.o
