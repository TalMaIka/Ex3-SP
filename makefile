CC=gcc
FLAGS= -Wall -g

all: isort txtfind
isort: sort.c
	${CC} ${FLAGS} sort.c -o isort
txtfind: text.c
	${CC} ${FLAGS} text.c -o txtfind

clean:
	rm -f *.o isort txtfind