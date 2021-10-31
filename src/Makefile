CC := gcc
CFLAGS := -g -Wall -std=gnu11

all: clean main

main: main.o pi_uci.o list.o queue.o wireless.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $^ -o $@

pi_uci.o: pi_uci.c
	$(CC) $(CFLAGS) -c $^ -o $@

list.o: list.c
	$(CC) $(CFLAGS) -c $^ -o $@

queue.c:  queue.o
	$(CC) $(CFLAGS) -c $^ -o $@

wireless.o: wireless.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o main
