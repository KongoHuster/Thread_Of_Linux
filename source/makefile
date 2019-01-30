aplication : main.o time.o readfile.o
	cc -o aplication main.o time.o readfile.o

main.o : main.c 
	g++ -c main.c

time.o : time.c time.h
	g++ -c time.c

readfile.o : readfile.c readfile.h
	g++ -c readfile.c

clean :
	rm aplication main.o time.o readfile.o