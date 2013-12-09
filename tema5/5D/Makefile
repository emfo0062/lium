OBJS=main.o a_functions.o b_functions.o c_functions.o d_functions.o
CC=gcc
CFLAGS=-c

all: alfa

alfa: $(OBJS)
	gcc $(OBJS) -o alfa

clean:
	rm -f *.o alfa

install: alfa
	mkdir -p release
	cp alfa release/alfa

uninstall:
	rm -rf release

main.o: main.c main.h
	$(CC) $(CFLAGS) main.c -o main.o

a_functions.o: a_functions.c a.h
	$(CC) $(CFLAGS) a_functions.c -o a_functions.o

b_functions.o: b_functions.c b.h
	$(CC) $(CFLAGS) b_functions.c -o b_functions.o

c_functions.o: c_functions.c c.h
	$(CC) $(CFLAGS) c_functions.c -o c_functions.o

d_functions.o: d_functions.c d.h
	$(CC) $(CFLAGS) d_functions.c -o d_functions.o
