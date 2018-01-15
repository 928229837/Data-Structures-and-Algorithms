INTOBJS = integer.o test-integer.o
REALOBJS = real.o test-real.o
STROBJS = string.o test-string.o

DAOBJS = da.o integer.o real.o string.o test-da.o
CDAOBJS = cda.o integer.o real.o string.o test-cda.o

STACKOBJS = da.o integer.o real.o string.o stack.o test-stack.o
QUEOBJS = queue.o cda.o integer.o real.o string.o test-queue.o

OPTS = -Wall -Wextra -g -std=c99

all : test


test: test-integer test-real test-string test-da test-cda test-queue test-stack



test-integer : $(INTOBJS)
	gcc $(OPTS) $(INTOBJS) -o test-integer

test-real : $(REALOBJS)
	gcc $(OPTS) $(REALOBJS) -o test-real

test-string : $(STROBJS)
	gcc $(OPTS) $(STROBJS) -o test-string

test-da : $(DAOBJS)
	gcc $(OPTS) $(DAOBJS) -o test-da

test-cda : $(CDAOBJS)
	gcc $(OPTS) $(CDAOBJS) -o test-cda

test-stack : $(STACKOBJS)
	gcc $(OPTS) $(STACKOBJS) -o test-stack

test-queue : $(QUEOBJS)
	gcc $(OPTS) $(QUEOBJS) -o test-queue



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

stack.o : stack.c stack.h
	gcc $(OPTS) -c stack.c

queue.o : queue.c queue.h
	gcc $(OPTS) -c queue.c




test-integer.o : test-integer.c integer.h
	gcc $(OPTS) -c test-integer.c

test-real.o : test-real.c real.h
	gcc $(OPTS) -c test-real.c

test-string.o : test-string.c string.h
	gcc $(OPTS) -c test-string.c

test-da.o : test-da.c da.h integer.h real.h string.h
	gcc $(OPTS) -c test-da.c

test-cda.o : test-cda.c cda.h integer.h real.h string.h
	gcc $(OPTS) -c test-cda.c

test-stack.o : test-stack.c da.h integer.h stack.h real.h string.h
	gcc $(OPTS) -c test-stack.c

test-queue.o : test-queue.c queue.h cda.h integer.h real.h string.h
	gcc $(OPTS) -c test-queue.c



clean :
	rm -f $(INTOBJS) $(REALOBJS) $(STROBJS) $(DAOBJS) $(CDAOBJS) $(STACKOBJS) $(QUEOBJS) test-integer test-real test-string test-da test-cda test-stack test-queue 



