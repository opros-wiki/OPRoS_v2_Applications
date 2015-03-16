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
	g++ -I"/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/workspace/GazeboJointMessage" -O0 -g3 -Wall -c -fPIC -fmessage-length=0 -o "$@" "$<" `pkg-config --cflags gazebo` && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	g++ -MM -MG -P -w -I"/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/workspace/GazeboJointMessage" -O0 -g3 -Wall -c -fPIC -fmessage-length=0   "$<" `pkg-config --cflags gazebo` >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


