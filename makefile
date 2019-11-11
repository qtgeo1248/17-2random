ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o random.o
	gcc -o program main.o random.o

main.o: main.c random.h
	gcc -c main.c

random.o: random.c random.h
	gcc -c random.c

run:
	./program

clean:
	rm *.o

memcheck:
	valgrind --leak-check=yes ./program
