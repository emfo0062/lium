CC = gcc -g
#LIBFLAG = -Llib -lresistance -lpower -lcomponent -Wl,-rpath,lib
LIBFLAG = -Llib -lresistance -Wl,-rpath,lib
INC = -Iresistance/src -Ipower/src -Icomponent/src

all:		  electrotest

		  #libpower.so libcomponent.so

electrotest:	  src/electrotest.c libresistance.so 
		  $(CC) $(INC) -o electrotest src/electrotest.c $(LIBFLAG)

resistance:	  libresistance.so

libresistance.so: resistance/src/resistance.c resistance/src/resistance.h 
		  $(CC) $(INC) -c -fPIC resistance/src/resistance.c
		  $(CC) $(INC) -shared -fPIC -o lib/libresistance.so resistance.o
power:		  libpower.so

libpower.so:	  power/src/power.c power/src/power.h 
		  $(CC) $(INC) -c -fPIC power/src/power.c
		  $(CC) $(INC) -shared -fPIC -o lib/libpower.so power.o

component:	  libcomponent.so

libcomponent.so:  component/src/component.c component/src/component.h 
		  $(CC) $(INC) -c -fPIC component/src/component.c
		  $(CC) $(INC) -shared -fPIC -o lib/libcomponent.so component.o


clean:
		  rm -f *.o *.so lib/* electrotest 
