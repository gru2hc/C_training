CC=gcc

dob.o: dob.c
	$(CC) -c dob.c -o dob.o

dob:dob.o
	$(CC) dob.o -o dob
	
build: dob

exec:
	dob

clean:
	rm -rf *.exe *.o
