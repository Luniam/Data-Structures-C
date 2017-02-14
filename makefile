CC = gcc
FLAGS = -g -Wall
PROG = bin/main
SRCS = src/main.c src/linkedlist.c
DEPS = src/main.c src/linkedlist.c src/include/linkedlist.h
$(PROG) : $(DEPS)
	$(CC) $(FLAGS) $(SRCS) -o $(PROG)