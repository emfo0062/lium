OBJS=main.o a_functions.o b_functions.o c_functions.o d_functions.o

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
