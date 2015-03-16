#ifndef _JointSpaceControlService_PROVIDED_PORT_H
#define _JointSpaceControlService_PROVIDED_PORT_H

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

#ifndef _IJointSpaceControlService_CLASS_DEF
#define _IJointSpaceControlService_CLASS_DEF
/*
 * IJointSpaceControlService
 *
 *  The comonent inherits this class and implements methods.
 */
class IJointSpaceControlService
{
public:
	virtual ReturnType SetProperty(OPRoS::Property props)=0;
	virtual OPRoS::Property GetProperty()=0;
	virtual ReturnType SetActualJointInfo(OPRoS::Float64Array actualJointAcceleration,OPRoS::Float64Array actualJointVelocity,OPRoS::Float64Array actualJointPosition)=0;
	virtual ReturnType SetDesiredJointInfo(OPRoS::Float64Array desiredJointAcceleration,OPRoS::Float64Array desiredJointVelocity,OPRoS::Float64Array desiredJointPosition)=0;
	virtual OPRoS::Float64Array CalculateJointTorque()=0;
};
#endif

/*
 *
 * JointSpaceControlService : public ProvidedServicePort
 *
 */
class JointSpaceControlServiceProvided : public ProvidedServicePort, public IJointSpaceControlService
{
protected:
	IJointSpaceControlService *pcom;

	typedef ProvidedMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef ProvidedMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef ProvidedMethod<ReturnType> SetActualJointInfoFuncType;
	SetActualJointInfoFuncType *SetActualJointInfoFunc;

	typedef ProvidedMethod<ReturnType> SetDesiredJointInfoFuncType;
	SetDesiredJointInfoFuncType *SetDesiredJointInfoFunc;

	typedef ProvidedMethod<OPRoS::Float64Array> CalculateJointTorqueFuncType;
	CalculateJointTorqueFuncType *CalculateJointTorqueFunc;

public: // default method
	virtual ReturnType SetProperty(OPRoS::Property props)
	{
		opros_assert(SetPropertyFunc != NULL);

		return (*SetPropertyFunc)(props);
	}

	virtual OPRoS::Property GetProperty()
	{
		opros_assert(GetPropertyFunc != NULL);

		return (*GetPropertyFunc)();
	}

	virtual ReturnType SetActualJointInfo(OPRoS::Float64Array actualJointAcceleration,OPRoS::Float64Array actualJointVelocity,OPRoS::Float64Array actualJointPosition)
	{
		opros_assert(SetActualJointInfoFunc != NULL);

		return (*SetActualJointInfoFunc)(actualJointAcceleration,actualJointVelocity,actualJointPosition);
	}

	virtual ReturnType SetDesiredJointInfo(OPRoS::Float64Array desiredJointAcceleration,OPRoS::Float64Array desiredJointVelocity,OPRoS::Float64Array desiredJointPosition)
	{
		opros_assert(SetDesiredJointInfoFunc != NULL);

		return (*SetDesiredJointInfoFunc)(desiredJointAcceleration,desiredJointVelocity,desiredJointPosition);
	}

	virtual OPRoS::Float64Array CalculateJointTorque()
	{
		opros_assert(CalculateJointTorqueFunc != NULL);

		return (*CalculateJointTorqueFunc)();
	}

public:
    //
    // Constructor
    //
	JointSpaceControlServiceProvided(IJointSpaceControlService *fn)
	{
		pcom = fn;

		SetPropertyFunc = NULL;
		GetPropertyFunc = NULL;
		SetActualJointInfoFunc = NULL;
		SetDesiredJointInfoFunc = NULL;
		CalculateJointTorqueFunc = NULL;

		setup();
	}

	// generated setup function
	virtual void setup()
	{
		Method *ptr_method;

		ptr_method = makeProvidedMethod(&IJointSpaceControlService::SetProperty,pcom,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IJointSpaceControlService::GetProperty,pcom,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IJointSpaceControlService::SetActualJointInfo,pcom,"SetActualJointInfo");
		opros_assert(ptr_method != NULL);
		addMethod("SetActualJointInfo",ptr_method);
		SetActualJointInfoFunc = reinterpret_cast<SetActualJointInfoFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IJointSpaceControlService::SetDesiredJointInfo,pcom,"SetDesiredJointInfo");
		opros_assert(ptr_method != NULL);
		addMethod("SetDesiredJointInfo",ptr_method);
		SetDesiredJointInfoFunc = reinterpret_cast<SetDesiredJointInfoFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IJointSpaceControlService::CalculateJointTorque,pcom,"CalculateJointTorque");
		opros_assert(ptr_method != NULL);
		addMethod("CalculateJointTorque",ptr_method);
		CalculateJointTorqueFunc = reinterpret_cast<CalculateJointTorqueFuncType *>(ptr_method);
		ptr_method = NULL;
	}
};
#endif
