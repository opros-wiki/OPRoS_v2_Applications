################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../JointSpaceInverseDynamicsControlComp.cpp 

OBJS += \
./JointSpaceInverseDynamicsControlComp.o 

CPP_DEPS += \
./JointSpaceInverseDynamicsControlComp.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/root/work/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include -I/root/work/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include/device -O2 -g -Wall -c -fPIC -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	g++ -MM -MG -P -w -I/root/work/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include -I/root/work/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include/device -O2 -g -Wall -c -fPIC -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


