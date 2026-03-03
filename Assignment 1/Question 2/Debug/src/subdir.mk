################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Question\ 2.cpp 

CPP_DEPS += \
./src/Question\ 2.d 

OBJS += \
./src/Question\ 2.o 


# Each subdirectory must supply rules for building sources it contributes
src/Question\ 2.o: ../src/Question\ 2.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Question 2.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Question\ 2.d ./src/Question\ 2.o

.PHONY: clean-src

