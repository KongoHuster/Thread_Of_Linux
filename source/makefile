aplication : main.o time.o
	cc -o aplication main.o time.o

main.o : main.c 
	g++ -c main.c

time.o : time.c time.h
	g++ -c time.c


clean :
	rm aplication main.o time.o