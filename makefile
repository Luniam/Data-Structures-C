CC = gcc
FLAGS = -g -Wall
PROG = bin/linkedlist
SRCS = linkedlist.c
$(PROG) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(PROG)