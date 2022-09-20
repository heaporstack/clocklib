.DEFAULT_GOAL := default

default:
	gcc -c datetime.c timestamp.c
	gcc -o main main.c datetime.o timestamp.o

clean:
	rm datetime.o timestamp.o
