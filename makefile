all: program5
program5: program5.o list.o vector.o stack.o
	gcc -g  program5.o list.o vector.o stack.o -o program5
program5.o: program5.c
	gcc -g -c program5.c -o program5.o
list.o: list.c
	gcc -g -c list.c -o list.o
vector.o: vector.c
	gcc -g -c vector.c -o vector.o
stack.o: stack.c
	gcc -g -c stack.c -o stack.o
run: program5
	./program5
checkmem: program5.c
	valgrind ./program5
clean:
	rm program5 *.o
