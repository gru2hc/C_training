CC=gcc

area_triangle.o: area_triangle.c
	$(CC) -c area_triangle.c -o area_triangle.o

area_triangle:area_triangle.o
	$(CC) area_triangle.o -o area_triangle
	
build: area_triangle

exec:
	area_triangle

clean:
	rm -rf *.exe *.o
