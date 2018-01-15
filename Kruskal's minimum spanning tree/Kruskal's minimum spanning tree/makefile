OBJS = kruskal.o vertex.o set.o edge.o da.o integer.o cda.o queue.o bst.o scanner.o rbt.o

OPTS = -Wall -Wextra -g -std=c99

test : kruskal

kruskal : $(OBJS)
	gcc $(OPTS) $(OBJS) -lm -o kruskal

vertex.o : vertex.c vertex.h da.h edge.h
	gcc $(OPTS) -c vertex.c

set.o : set.c set.h da.h
	gcc $(OPTS) -c set.c

edge.o : edge.c edge.h vertex.h
	gcc $(OPTS) -c edge.c
	
da.o : da.c da.h
	gcc $(OPTS) -c da.c

rbt.o : rbt.c bst.h rbt.h
	gcc $(OPTS) -c rbt.c

integer.o : integer.c integer.h
	gcc $(OPTS) -c integer.c

cda.o : cda.c cda.h
	gcc $(OPTS) -c cda.c

queue.o : queue.c cda.h queue.h
	gcc $(OPTS) -c queue.c

bst.o : bst.c bst.h string.h queue.h
	gcc $(OPTS) -c bst.c

kruskal.o : kruskal.c rbt.h set.h bst.h edge.h queue.h vertex.h scanner.h integer.h
	gcc $(OPTS) -c kruskal.c
	
scanner.o : scanner.c scanner.h
	gcc $(OPTS) -c scanner.c


clean:
	rm -f $(OBJS) kruskal


 test : kruskal

	@echo Removing previous outputs.
	rm ./testFiles/submission0/myOutput/*
	rm ./testFiles/output/*
	
	@echo Running up to 1,000,000 node inputs. These files take a while around 10 seconds each for me.
	@echo 
	@echo They are optional. I included them seperately because they are so large. 10MB each.
	@echo 
	rm ./largeFiles/largeOutput/*
	kruskal ./largeFiles/largeInput/random100000Input0.txt >> ./largeFiles/largeOutput/random100000Output0.txt
	kruskal ./largeFiles/largeInput/random100000Input1.txt >> ./largeFiles/largeOutput/random100000Output1.txt
	kruskal ./largeFiles/largeInput/random100000Input2.txt >> ./largeFiles/largeOutput/random100000Output2.txt
	kruskal ./largeFiles/largeInput/random100000Input3.txt >> ./largeFiles/largeOutput/random100000Output3.txt

	
	diff ./largeFiles/largeOutput/random100000Output0.txt ./largeFiles/givenLargeOutput/random100000Output0.txt
	diff ./largeFiles/largeOutput/random100000Output1.txt ./largeFiles/givenLargeOutput/random100000Output1.txt
	diff ./largeFiles/largeOutput/random100000Output2.txt ./largeFiles/givenLargeOutput/random100000Output2.txt
	diff ./largeFiles/largeOutput/random100000Output3.txt ./largeFiles/givenLargeOutput/random100000Output3.txt
	
	@echo Testing sequence has finished. Your code matches everything.
