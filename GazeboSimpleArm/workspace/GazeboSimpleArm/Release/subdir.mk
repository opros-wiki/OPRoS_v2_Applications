################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GazeboSimpleArm.cpp 

OBJS += \
./GazeboSimpleArm.o 

CPP_DEPS += \
./GazeboSimpleArm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include/device -I/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include -I"/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/workspace/GazeboJointMessage" -O3 -Wall -c -fPIC -fmessage-length=0 -o "$@" "$<" `pkg-config --cflags gazebo` && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	g++ -MM -MG -P -w -I/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include/device -I/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include -I"/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/workspace/GazeboJointMessage" -O3 -Wall -c -fPIC -fmessage-length=0   "$<" `pkg-config --cflags gazebo` >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


