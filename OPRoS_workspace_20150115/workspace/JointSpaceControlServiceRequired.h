#ifndef _JointSpaceControlService_REQUIRED_PORT_H
#define _JointSpaceControlService_REQUIRED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>

#include "ApiTypes.h"
#include "Property.h"

/*
 * 
 * JointSpaceControlService : public RequiredServicePort
 *
 */
class JointSpaceControlServiceRequired : public RequiredServicePort
{
protected:
	typedef RequiredMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef RequiredMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef RequiredMethod<ReturnType> SetActualJointInfoFuncType;
	SetActualJointInfoFuncType *SetActualJointInfoFunc;

	typedef RequiredMethod<ReturnType> SetDesiredJointInfoFuncType;
	SetDesiredJointInfoFuncType *SetDesiredJointInfoFunc;

	typedef RequiredMethod<OPRoS::Float64Array> CalculateJointTorqueFuncType;
	CalculateJointTorqueFuncType *CalculateJointTorqueFunc;

public:
	//
	// Constructor
	//
	JointSpaceControlServiceRequired()
	{
		SetPropertyFunc = NULL;
		GetPropertyFunc = NULL;
		SetActualJointInfoFunc = NULL;
		SetDesiredJointInfoFunc = NULL;
		CalculateJointTorqueFunc = NULL;
   
		setup();
	}

	// method implementation for required method
	ReturnType SetProperty(OPRoS::Property props)
	{
		opros_assert(SetPropertyFunc != NULL);

		return (*SetPropertyFunc)(props);
	}

	OPRoS::Property GetProperty()
	{
		opros_assert(GetPropertyFunc != NULL);

		return (*GetPropertyFunc)();
	}

	ReturnType SetActualJointInfo(OPRoS::Float64Array actualJointAcceleration,OPRoS::Float64Array actualJointVelocity,OPRoS::Float64Array actualJointPosition)
	{
		opros_assert(SetActualJointInfoFunc != NULL);

		return (*SetActualJointInfoFunc)(actualJointAcceleration,actualJointVelocity,actualJointPosition);
	}

	ReturnType SetDesiredJointInfo(OPRoS::Float64Array desiredJointAcceleration,OPRoS::Float64Array desiredJointVelocity,OPRoS::Float64Array desiredJointPosition)
	{
		opros_assert(SetDesiredJointInfoFunc != NULL);

		return (*SetDesiredJointInfoFunc)(desiredJointAcceleration,desiredJointVelocity,desiredJointPosition);
	}

	OPRoS::Float64Array CalculateJointTorque()
	{
		opros_assert(CalculateJointTorqueFunc != NULL);

		return (*CalculateJointTorqueFunc)();
		
	}

    // generated setup function
	virtual void setup()
	{
		Method *ptr_method;
    
		ptr_method = makeRequiredMethod(&JointSpaceControlServiceRequired::SetProperty,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeRequiredMethod(&JointSpaceControlServiceRequired::GetProperty,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&JointSpaceControlServiceRequired::SetActualJointInfo,"SetActualJointInfo");
		opros_assert(ptr_method != NULL);
		addMethod("SetActualJointInfo",ptr_method);
		SetActualJointInfoFunc = reinterpret_cast<SetActualJointInfoFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeRequiredMethod(&JointSpaceControlServiceRequired::SetDesiredJointInfo,"SetDesiredJointInfo");
		opros_assert(ptr_method != NULL);
		addMethod("SetDesiredJointInfo",ptr_method);
		SetDesiredJointInfoFunc = reinterpret_cast<SetDesiredJointInfoFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeRequiredMethod(&JointSpaceControlServiceRequired::CalculateJointTorque,"CalculateJointTorque");
		opros_assert(ptr_method != NULL);
		addMethod("CalculateJointTorque",ptr_method);
		CalculateJointTorqueFunc = reinterpret_cast<CalculateJointTorqueFuncType *>(ptr_method);
		ptr_method = NULL;
	}
};
#endif
