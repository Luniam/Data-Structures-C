CC = cc
PROG = bin/linkedlist
SRCS = linkedlist.c
$(PROG) : $(SRCS)
	$(CC) $(SRCS) -o $(PROG)