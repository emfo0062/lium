libname = component
libfilename = lib$(libname).so
local_lib_dir = ./local_lib
shared_lib_dir = /usr/lib
target = prog
shared_target = eres
installed_bin_dir = /usr/bin
installed_target = $(installed_bin_dir)/$(shared_target)
objects = main.o
lib_objects = $(libname).o
local_lib = $(local_lib_dir)/$(libfilename)
shared_lib = $(shared_lib_dir)/$(libfilename)


.PHONY : all
all : $(target)

$(target) : $(objects) $(local_lib)
	gcc -o $@ $(objects) -L$(local_lib_dir) -l$(libname) -Wl,-rpath,$(local_lib_dir)

.PHONY : lib
lib : $(local_lib)

$(local_lib) : $(lib_objects) $(local_lib_dir)
	gcc -shared -fPIC -o $(local_lib) $(lib_objects)

component.o : ./src/component.c 
	gcc -c -FPIC ./src/component.c

main.o : main.c ./src/component.h
	gcc -c -I./src main.c

%.o : %.c
	gcc -c $<

$(local_lib_dir) :
	mkdir $(local_lib_dir)

.PHONY : install
install : $(installed_target)

$(installed_target) : $(shared_target)
	sudo install $(shared_target) $(installed_bin_dir)

$(shared_target) : $(objects) $(shared_lib)
	gcc -o $@ main.o -L$(shared_lib_dir) -l$(libname) -Wl,-rpath,$(shared_lib_dir)

$(shared_lib) : $(local_lib)
	sudo install $(local_lib) $(shared_lib_dir)



.PHONY : clean
clean :
	-rm *.o $(local_lib) $(target) $(shared_target)
	rmdir $(local_lib_dir)

.PHONY : uninstall
uninstall :
	sudo rm $(installed_target) $(shared_lib)

