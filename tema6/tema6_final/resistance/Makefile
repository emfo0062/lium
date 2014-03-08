CC = gcc -g
LIBFLAG = -L. -lresistance -Wl,-rpath,.
INC = -Isrc

all:		testRes
test:		testRes
		./testRes
testRes:	test/test.c libresistance.so
		$(CC) $(INC) -o testRes test/test.c $(LIBFLAG)

libresistance.so:	src/resistance.c src/resistance.h 
			$(CC) -c -fPIC src/resistance.c
			$(CC) -shared -fPIC -o libresistance.so resistance.o

clean:
	rm -f *.o *.so testRes
