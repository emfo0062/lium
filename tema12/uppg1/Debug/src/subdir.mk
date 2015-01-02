################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ComplexZ.cpp \
../src/Fractal.cpp \
../src/main.cpp \
../src/mandelbrot.cpp 

OBJS += \
./src/ComplexZ.o \
./src/Fractal.o \
./src/main.o \
./src/mandelbrot.o 

CPP_DEPS += \
./src/ComplexZ.d \
./src/Fractal.d \
./src/main.d \
./src/mandelbrot.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ `pkg-config --cflags gtk+-2.0` -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/glib-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


