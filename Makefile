CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror
OBJ = spell.o dictionary.o
EXEC = spell

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

spell.o : spell.c dictionary.h
	$(CC) -c spell.c $(CFLAGS)

dictionary.o : dictionary.c dictionary.h
	$(CC) -c dictionary.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
