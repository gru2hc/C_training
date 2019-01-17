CC=gcc

main.o: main.c
	$(CC) -c main.c -o main.o
handle_node.o: handle_node.c
	$(CC) -c handle_node.c -o handle_node.o
display.o: display.c
	$(CC) -c display.c -o display.o

main:main.o handle_node.o display.o
	$(CC) main.o handle_node.o display.o -o main
	
all: main

exec:
	main.exe

clean:
	rm -rf *.exe *.o
