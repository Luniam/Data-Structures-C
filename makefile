CC = cc
PROG = linkedlist
SRCS = linkedlist.c
$(PROG) : $(SRCS)
	$(CC) $(SRCS) -o $(PROG)