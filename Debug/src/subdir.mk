################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Main.cpp \
../src/Position.cpp \
../src/Reader.cpp \
../src/Room.cpp 

OBJS += \
./src/Main.o \
./src/Position.o \
./src/Reader.o \
./src/Room.o 

CPP_DEPS += \
./src/Main.d \
./src/Position.d \
./src/Reader.d \
./src/Room.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


