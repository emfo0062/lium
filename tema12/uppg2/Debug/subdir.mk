################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OpenCV_Capture.c 

OBJS += \
./OpenCV_Capture.o 

C_DEPS += \
./OpenCV_Capture.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc  -std=gnu99 `pkg-config --cflags gtk+-2.0` `pkg-config --cflags opencv` -I/usr/include/opencv -I/usr/include/gtk-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


