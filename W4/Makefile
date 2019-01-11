CC=gcc

main.o: main.c
	$(CC) -c main.c -o main.o
qsort.o: qsort.c
	$(CC) -c qsort.c -o qsort.o
display.o: display.c
	$(CC) -c display.c -o display.o

main:main.o qsort.o display.o
	$(CC) main.o qsort.o display.o -o main
	
all: main

exec:
	main

clean:
	rm -rf *.exe *.o
