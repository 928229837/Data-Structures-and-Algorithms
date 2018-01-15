OBJS = integer.o real.o string.o da.o cda.o stack.o queue.o bst.o scanner.o process.o matilda.o 

OPTS = -Wall -Wextra -g -std=c99


matilda : $(OBJS)
	gcc $(OPTS) $(OBJS) -lm -o matilda

integer.o : integer.c integer.h
	gcc $(OPTS) -c integer.c

real.o : real.c real.h
	gcc $(OPTS) -c real.c

string.o : string.c string.h
	gcc $(OPTS) -c string.c

da.o : da.c da.h
	gcc $(OPTS) -c da.c

cda.o : cda.c cda.h
	gcc $(OPTS) -c cda.c

stack.o : stack.c da.h stack.h
	gcc $(OPTS) -c stack.c

queue.o : queue.c cda.h queue.h
	gcc $(OPTS) -c queue.c

bst.o : bst.c bst.h string.h 
	gcc $(OPTS) -c bst.c

matilda.o : matilda.c integer.h real.h string.h da.h cda.h stack.h queue.h bst.h scanner.h process.h
	gcc $(OPTS) -c matilda.c

scanner.o : scanner.c scanner.h
	gcc $(OPTS) -c scanner.c

process.o : process.c real.h string.h bst.h queue.h stack.h process.h
	gcc $(OPTS) -c process.c


clean:
	rm -f $(OBJS) matilda


