FLAGS=-g -Wall -pedantic 

all: 
	gcc ${FLAGS} -Wall -pedantic -c client1.c
	gcc ${FLAGS} -Wall -pedantic -c server1.c
	gcc ${FLAGS} -Wall -pedantic -c pcolparse.c
	gcc ${FLAGS} -Wall -pedantic -c summary.c
	gcc ${FLAGS} -o summary summary.o pcolparse.o
	g++ ${FLAGS} -Wall -pedantic -c extract.cc
	g++ ${FLAGS} -o extract extract.o pcolparse.o 
