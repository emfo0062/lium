CC = gcc -g
LIBFLAG = -Llib -lresistance -lpower -lcomponent -Wl,-rpath,lib
INSTALL_LIBFLAG = -Llib -lresistance -lpower -lcomponent
INC = -Iresistance/src -Ipower/src -Icomponent/src

all:			electrotest
lib:			libresistance libcomponent libpower
install:		electrotest
			$(CC) $(INC) -o electrotest src/electrotest.c $(INSTALL_LIBFLAG)
			install electrotest /usr/bin/electrotest
			install lib/* /usr/lib
uninstall:
			rm -f /usr/bin/electrotest /usr/lib/libresistance.so /usr/lib/libpower.so /usr/lib/libcomponent.so

electrotest:		src/electrotest.c lib/libresistance.so lib/libcomponent.so lib/libpower.so
			$(CC) $(INC) -o electrotest src/electrotest.c $(LIBFLAG)
test:			electrotest
			./electrotest < testdata.txt

libresistance:		lib/libresistance.so
lib/libresistance.so:	resistance/src/resistance.c resistance/src/resistance.h 
			$(CC) $(INC) -c -fPIC resistance/src/resistance.c
			$(CC) $(INC) -shared -fPIC -o lib/libresistance.so resistance.o

libpower:		lib/libpower.so
lib/libpower.so:	power/src/power.c power/src/power.h
			$(CC) $(INC) -c -fPIC power/src/power.c
			$(CC) $(INC) -shared -fPIC -o lib/libpower.so power.o

libcomponent:		lib/libcomponent.so
lib/libcomponent.so:	component/src/component.c component/src/component.h 
			$(CC) $(INC) -c -fPIC component/src/component.c
			$(CC) $(INC) -shared -fPIC -o lib/libcomponent.so component.o

clean:
		 	 rm -f *.o *.so lib/* electrotest 
