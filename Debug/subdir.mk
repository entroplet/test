################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BinaryTree.cpp \
../Node.cpp 

CPP_DEPS += \
./BinaryTree.d \
./Node.d 

OBJS += \
./BinaryTree.o \
./Node.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -std=c++17 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./BinaryTree.d ./BinaryTree.o ./Node.d ./Node.o

.PHONY: clean--2e-

