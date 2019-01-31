multisum : main.o time.o readwritefile.o
	cc -o multisum main.o time.o readwritefile.o

main.o : main.c 
	g++ -c main.c

time.o : time.c time.h
	g++ -c time.c

readwritefile.o : readwritefile.c readwritefile.h
	g++ -c readwritefile.c

clean :
	rm multisum main.o time.o readwritefile.o

run :
	./multisum
