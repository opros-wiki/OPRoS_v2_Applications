################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../joint_control_test_plugin.cpp 

OBJS += \
./joint_control_test_plugin.o 

CPP_DEPS += \
./joint_control_test_plugin.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/root/workspace/GazeboJointMessage" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<" `pkg-config --cflags gazebo`
	@echo 'Finished building: $<'
	@echo ' '


