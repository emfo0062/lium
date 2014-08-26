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
                        src/interface.c  src/interface.h\
                        lib/resistance.h lib/component.h lib/power.h
			gcc $(INC) src/elektrotestgtk.c src/calc.c src/interface.c -o elektrotestgtk `pkg-config --cflags --libs libgnome-2.0 libgnomeui-2.0` $(LIBFLAG)
			
test:			elektrotestgtk
			./elektrotestgtk

doc:                    src/elektrotestgtk.c src/elektrotestgtk.h\
                        src/calc.c src/calc.h\
                        lib/resistance.h lib/component.h lib/power.h
			doxygen
			${MAKE} -C doc/latex

release:                src/elektrotestgtk.c src/elektrotestgtk.h\
                        src/calc.c src/calc.h\
                        lib/resistance.h lib/component.h lib/power.h\
		 	Makefile Doxyfile
		 	mkdir -p lab11/doc
		 	cp -r src lab11/
		 	cp -r lib lab11/
		 	cp Makefile lab11/
		 	cp Doxyfile lab11/
		 	${MAKE} doc
		 	cp doc/latex/refman.pdf lab11/doc/doc.pdf
		 	tar -cvzf PetterLerenius_lab11.tar.gz lab11
clean:
		 	rm -f *.o elektrotestgtk PetterLerenius_lab11.tar.gz
			rm -rf doc/ lab11/
