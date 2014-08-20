CC = gcc -g
LIBFLAG = -Llib -lresistance -lpower -lcomponent
INSTALL_LIBFLAG = -Llib -lresistance -lpower -lcomponent
INC = -Ilib

all:			elektrotestgtk
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

elektrotestgtk:		src/elektrotestgtk.c  src/elektrotestgtk.h\
                        src/calc.c  src/calc.h\
                        lib/resistance.h lib/component.h lib/power.h
			gcc $(INC) src/elektrotestgtk.c src/calc.c -o elektrotestgtk `pkg-config --cflags --libs libgnome-2.0 libgnomeui-2.0` $(LIBFLAG)
			
test:			elektrotestgtk
			./elektrotestgtk

doc:                    src/elektrotestgtk.c src/elektrotestgtk.h\
                        src/calc.c src/calc.h\
                        lib/resistance.h lib/component.h lib/power.h
			doxygen
			${MAKE} -C doc/latex

clean:
		 	rm -f *.o elektrotestgtk
			rm -rf doc/
