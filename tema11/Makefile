CC = gcc -g
LIBFLAG = -Llib -lresistance -lpower -lcomponent
INSTALL_LIBFLAG = -Llib -lresistance -lpower -lcomponent
INC = -Ilib

all:			electrotestgtk
libinstall:
			cd ../tema6/svn/
			make install
			cd ../../tema11/
			cp ../tema6/svn/component/src/component.h lib/.
			cp ../tema6/svn/resistance/src/resistans.h lib/.
			cp ../tema6/svn/power/src/power.h lib/.
libuninstall:
			cd ../tema6/svn/
			make uninstall
			cd ../../tema11/

electrotestgtk:		src/electrotestgtk.c lib/resistance.h lib/component.h lib/power.h
			gcc src/elektrotestgtk.c -o electrotestgtk `pkg-config --cflags --libs gtk+-2.0`
			#libinstall
			#$(CC) $(INC) -o electrotestgtk src/electrotest.c $(LIBFLAG)
			
test:			electrotest
			./electrotest < testdata.txt

clean:
			libuninstall
		 	rm -f *.o electrotestgtk