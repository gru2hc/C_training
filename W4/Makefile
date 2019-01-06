CC=gcc

qsort.o: qsort.c
	$(CC) -c qsort.c -o qsort.o

qsort:qsort.o
	$(CC) qsort.o -o qsort
	
all: qsort

exec:
	qsort

clean:
	rm -rf *.exe *.o
