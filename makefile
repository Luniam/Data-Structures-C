CC = gcc
FLAGS = -g -Wall
PROG = bin/linkedlist
SRCS = main.c linkedlist.c
DEPS = main.c linkedlist.c linkedlist.h
$(PROG) : $(DEPS)
	$(CC) $(FLAGS) $(SRCS) -o $(PROG)