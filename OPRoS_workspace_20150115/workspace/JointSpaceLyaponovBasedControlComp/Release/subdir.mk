################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DynamicsControl.cpp \
../JointSpaceControl.cpp \
../JointSpaceLyaponovBasedControlComp.cpp \
../JointSpaceLyapunovBasedControl.cpp \
../ManipulatorControl.cpp 

OBJS += \
./DynamicsControl.o \
./JointSpaceControl.o \
./JointSpaceLyaponovBasedControlComp.o \
./JointSpaceLyapunovBasedControl.o \
./ManipulatorControl.o 

CPP_DEPS += \
./DynamicsControl.d \
./JointSpaceControl.d \
./JointSpaceLyaponovBasedControlComp.d \
./JointSpaceLyapunovBasedControl.d \
./ManipulatorControl.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_OPROS_DEBUG_ -I/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include -I/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include/device -I/usr/local/include/kdl -I/usr/eigen -O2 -g -Wall -c -fPIC -fmessage-length=0 -o "$@" "$<" && \
	echo -n '$(@:%.o=%.d)' $(dir $@) > '$(@:%.o=%.d)' && \
	g++ -MM -MG -P -w -D_OPROS_DEBUG_ -I/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include -I/root/OPRoS_Linux/OPRoS_IDE_Linux_v2.0.8x86/OPRoS_external_package/Linux/include/device -I/usr/local/include/kdl -I/usr/eigen -O2 -g -Wall -c -fPIC -fmessage-length=0   "$<" >> '$(@:%.o=%.d)'
	@echo 'Finished building: $<'
	@echo ' '


