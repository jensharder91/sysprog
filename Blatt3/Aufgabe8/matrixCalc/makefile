OBJECTS = main.o mymatrix.o 
CPPFLAGS = -Wall -g -pg
CC = gcc

run: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o run $(OBJECTS)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $<
