multisum : main.o time.o readwritefile.o thread.o
	cc -o multisum main.o time.o readwritefile.o thread.o

main.o : main.c 
	g++ -c main.c
	

time.o : time.c time.h
	g++ -c time.c

readwritefile.o : readwritefile.c readwritefile.h
	g++ -c readwritefile.c

thread.o : thread.c thread.h
	g++ -c thread.c

clean :
	rm multisum main.o time.o readwritefile.o thread.o

test : 
	./multisum