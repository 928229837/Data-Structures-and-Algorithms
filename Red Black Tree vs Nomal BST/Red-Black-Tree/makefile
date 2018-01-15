OBJS = string.o cda.o queue.o bst.o scanner.o gt.o rbt.o trees.o 

OPTS = -Wall -Wextra -g -std=c99

trees : $(OBJS)
	gcc $(OPTS) $(OBJS) -lm -o trees

gt.o : gt.c bst.h gt.h
	gcc $(OPTS) -c gt.c

rbt.o : rbt.c bst.h rbt.h
	gcc $(OPTS) -c rbt.c

string.o : string.c string.h
	gcc $(OPTS) -c string.c

cda.o : cda.c cda.h
	gcc $(OPTS) -c cda.c

queue.o : queue.c cda.h queue.h
	gcc $(OPTS) -c queue.c

bst.o : bst.c bst.h string.h queue.h
	gcc $(OPTS) -c bst.c

trees.o : trees.c gt.h scanner.h rbt.h string.h
	gcc $(OPTS) -c trees.c

scanner.o : scanner.c scanner.h
	gcc $(OPTS) -c scanner.c

clean:
	rm -f $(OBJS) trees


