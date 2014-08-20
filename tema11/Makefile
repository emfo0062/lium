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

electrotestgtk:		src/elektrotestgtk.c src/calc.c lib/resistance.h lib/component.h lib/power.h
			gcc $(INC) src/elektrotestgtk.c src/calc.c -o electrotestgtk `pkg-config --cflags --libs gtk+-2.0` $(LIBFLAG)
			
test:			electrotestgtk
			./electrotestgtk

doc:                    src/elektrotestgtk.c src/calc.c src/calc.h lib/resistance.h lib/component.h lib/power.h
			doxygen
			cd doc/latex
			make
			cd -

clean:
		 	rm -f *.o electrotestgtk
			rm -rf doc/
