all: driver.o linked.o
	gcc driver.o linked.o

driver.o: driver.c linked.h
	gcc -c driver.c linked.h

linked.o: linked.c linked.h
	gcc -c linked.c linked.h

run:
	./a.out

