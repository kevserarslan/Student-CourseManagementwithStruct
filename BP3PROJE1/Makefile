CC = gcc
CFLAGS = -O2 -Wall
LINKFLAGS = -lm

OUTPUT = main.exe
OBJECTS = main.o Proje1.o

$(OUTPUT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LINKFLAGS) -o $(OUTPUT)

main.o: main.c Proje1.h 
	$(CC) -c main.c $(CFLAGS)

Proje1.o: Proje1.c Proje1.h
	$(CC) -c Proje1.c $(CFLAGS)

clean:
	rm -f *.o *~ *% *.*~ core $(OUTPUT) *.out *.prof