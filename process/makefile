multisum : main.o time.o readwritefile.o process.o
	cc -o multisum main.o time.o readwritefile.o process.o

main.o : main.c 
	g++ -c main.c
	

time.o : time.c time.h
	g++ -c time.c

readwritefile.o : readwritefile.c readwritefile.h
	g++ -c readwritefile.c

process.o : process.c process.h
	g++ -c process.c

clean :
	rm multisum main.o time.o readwritefile.o process.o

test : 
	./multisum