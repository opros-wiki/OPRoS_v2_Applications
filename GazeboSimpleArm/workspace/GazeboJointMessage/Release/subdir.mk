################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../joint_effort_cmd.pb.cc \
../joint_status.pb.cc 

CC_DEPS += \
./joint_effort_cmd.pb.d \
./joint_status.pb.d 

OBJS += \
./joint_effort_cmd.pb.o \
./joint_status.pb.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fPIC -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	g++ -MM -MG -P -w -O3 -Wall -c -fPIC -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


