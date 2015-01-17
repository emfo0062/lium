CC = gcc -g
#LIBFLAG = -Llib -lresistance -lpower -lcomponent -Wl,-rpath,lib
LIBFLAG = -Llib -lresistance -Wl,-rpath,lib
INC = -Iresistance/src -Ipower/src -Icomponent/src

all: libresistance.so libpower.so libcomponent.so

lib%.so: %.o
	gcc -shared -o $@ $<

%.o: %.c %.h
	gcc -Wall -Werror -std=c99 -c -fPIC $<

install:
	mkdir -p $(DESTDIR)/usr/lib
	mkdir -p $(DESTDIR)/usr/include
	cp -f *.so $(DESTDIR)/usr/lib
	cp -f *.h $(DESTDIR)/usr/include

clean:
	rm -f *.o *.so
