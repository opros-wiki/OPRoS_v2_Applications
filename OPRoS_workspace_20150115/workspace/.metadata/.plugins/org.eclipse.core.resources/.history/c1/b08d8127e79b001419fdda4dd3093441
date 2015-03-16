

#ifndef _JointSpaceControlCoorinatorService_REQUIRED_PORT_H
#define _JointSpaceControlCoorinatorService_REQUIRED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>
#include <device/ApiTypes.h>


#include "OPRoS::Float64Array.h"
		
#include "float64_t.h"
		



/*
 * 
 * JointSpaceControlCoorinatorService : public RequiredServicePort
 *
 */
class JointSpaceControlCoorinatorServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<ReturnType> EnableFuncType;
	EnableFuncType *EnableFunc;

	typedef RequiredMethod<ReturnType> DisableFuncType;
	DisableFuncType *DisableFunc;

	typedef RequiredMethod<ReturnType> SetDesiredJointPositionFuncType;
	SetDesiredJointPositionFuncType *SetDesiredJointPositionFunc;

	typedef RequiredMethod<OPRoS::Float64Array> GetActualJointAccelerationFuncType;
	GetActualJointAccelerationFuncType *GetActualJointAccelerationFunc;

	typedef RequiredMethod<OPRoS::Float64Array> GetActualJointVelocityFuncType;
	GetActualJointVelocityFuncType *GetActualJointVelocityFunc;

	typedef RequiredMethod<OPRoS::Float64Array> GetActualJointPositionFuncType;
	GetActualJointPositionFuncType *GetActualJointPositionFunc;

public:
	//
	// Constructor
	//
	JointSpaceControlCoorinatorServiceRequired()
	{
            EnableFunc = NULL;
            DisableFunc = NULL;
            SetDesiredJointPositionFunc = NULL;
            GetActualJointAccelerationFunc = NULL;
            GetActualJointVelocityFunc = NULL;
            GetActualJointPositionFunc = NULL;
            
	   setup();
	}

	// method implementation for required method
	ReturnType Enable()
	{
            opros_assert(EnableFunc != NULL);
	
            return (*EnableFunc)();
		
	}

	ReturnType Disable()
	{
            opros_assert(DisableFunc != NULL);
	
            return (*DisableFunc)();
		
	}

	ReturnType SetDesiredJointPosition(OPRoS::Float64Array desiredJointPosition,float64_t time)
	{
            opros_assert(SetDesiredJointPositionFunc != NULL);
	
            return (*SetDesiredJointPositionFunc)(desiredJointPosition,time);
		
	}

	OPRoS::Float64Array GetActualJointAcceleration()
	{
            opros_assert(GetActualJointAccelerationFunc != NULL);
	
            return (*GetActualJointAccelerationFunc)();
		
	}

	OPRoS::Float64Array GetActualJointVelocity()
	{
            opros_assert(GetActualJointVelocityFunc != NULL);
	
            return (*GetActualJointVelocityFunc)();
		
	}

	OPRoS::Float64Array GetActualJointPosition()
	{
            opros_assert(GetActualJointPositionFunc != NULL);
	
            return (*GetActualJointPositionFunc)();
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&JointSpaceControlCoorinatorServiceRequired::Enable,"Enable");
        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&JointSpaceControlCoorinatorServiceRequired::Disable,"Disable");
        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&JointSpaceControlCoorinatorServiceRequired::SetDesiredJointPosition,"SetDesiredJointPosition");
        opros_assert(ptr_method != NULL);
        addMethod("SetDesiredJointPosition",ptr_method);
        SetDesiredJointPositionFunc = reinterpret_cast<SetDesiredJointPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&JointSpaceControlCoorinatorServiceRequired::GetActualJointAcceleration,"GetActualJointAcceleration");
        opros_assert(ptr_method != NULL);
        addMethod("GetActualJointAcceleration",ptr_method);
        GetActualJointAccelerationFunc = reinterpret_cast<GetActualJointAccelerationFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&JointSpaceControlCoorinatorServiceRequired::GetActualJointVelocity,"GetActualJointVelocity");
        opros_assert(ptr_method != NULL);
        addMethod("GetActualJointVelocity",ptr_method);
        GetActualJointVelocityFunc = reinterpret_cast<GetActualJointVelocityFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&JointSpaceControlCoorinatorServiceRequired::GetActualJointPosition,"GetActualJointPosition");
        opros_assert(ptr_method != NULL);
        addMethod("GetActualJointPosition",ptr_method);
        GetActualJointPositionFunc = reinterpret_cast<GetActualJointPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
