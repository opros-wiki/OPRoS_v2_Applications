

#ifndef _TrajectoryGenerationService_REQUIRED_PORT_H
#define _TrajectoryGenerationService_REQUIRED_PORT_H

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

#include <vector>
#include <valarray>

using namespace std;

/*
 * 
 * TrajectoryGenerationService : public RequiredServicePort
 *
 */
class TrajectoryGenerationServiceRequired : public RequiredServicePort
{
protected:
	typedef RequiredMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef RequiredMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef RequiredMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef RequiredMethod<ReturnType> GenerateTrajectoryFuncType;
	GenerateTrajectoryFuncType *GenerateTrajectoryFunc;

	typedef RequiredMethod<vector < valarray<float64_t> > > GetAccelerationFuncType;
	GetAccelerationFuncType *GetAccelerationFunc;

	typedef RequiredMethod<vector < valarray<float64_t> > > GetVelocityFuncType;
	GetVelocityFuncType *GetVelocityFunc;

	typedef RequiredMethod<vector < valarray<float64_t> > > GetPositionFuncType;
	GetPositionFuncType *GetPositionFunc;

public:
	//
	// Constructor
	//
	TrajectoryGenerationServiceRequired()
	{
		SetPropertyFunc = NULL;
		GetPropertyFunc = NULL;
		GetErrorFunc = NULL;
		GenerateTrajectoryFunc = NULL;
		GetAccelerationFunc = NULL;
		GetVelocityFunc = NULL;
		GetPositionFunc = NULL;

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

	ReturnType GetError()
	{
		opros_assert(GetErrorFunc != NULL);

		return (*GetErrorFunc)();
	}

	ReturnType GenerateTrajectory(vector< valarray<float64_t> > path,float64_t deltaTime)
	{
		opros_assert(GenerateTrajectoryFunc != NULL);

		return (*GenerateTrajectoryFunc)(path,deltaTime);
	}

	vector < valarray<float64_t> > GetAcceleration()
	{
		opros_assert(GetAccelerationFunc != NULL);

		return (*GetAccelerationFunc)();
	}

	vector < valarray<float64_t> > GetVelocity()
	{
		opros_assert(GetVelocityFunc != NULL);

		return (*GetVelocityFunc)();
	}

	vector < valarray<float64_t> > GetPosition()
	{
		opros_assert(GetPositionFunc != NULL);

		return (*GetPositionFunc)();
	}

	// generated setup function
	virtual void setup()
	{
		Method *ptr_method;

		ptr_method = makeRequiredMethod(&TrajectoryGenerationServiceRequired::SetProperty,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeRequiredMethod(&TrajectoryGenerationServiceRequired::GetProperty,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&TrajectoryGenerationServiceRequired::GetError,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&TrajectoryGenerationServiceRequired::GenerateTrajectory,"GenerateTrajectory");
		opros_assert(ptr_method != NULL);
		addMethod("GenerateTrajectory",ptr_method);
		GenerateTrajectoryFunc = reinterpret_cast<GenerateTrajectoryFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&TrajectoryGenerationServiceRequired::GetAcceleration,"GetAcceleration");
		opros_assert(ptr_method != NULL);
		addMethod("GetAcceleration",ptr_method);
		GetAccelerationFunc = reinterpret_cast<GetAccelerationFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeRequiredMethod(&TrajectoryGenerationServiceRequired::GetVelocity,"GetVelocity");
		opros_assert(ptr_method != NULL);
		addMethod("GetVelocity",ptr_method);
		GetVelocityFunc = reinterpret_cast<GetVelocityFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeRequiredMethod(&TrajectoryGenerationServiceRequired::GetPosition,"GetPosition");
		opros_assert(ptr_method != NULL);
		addMethod("GetPosition",ptr_method);
		GetPositionFunc = reinterpret_cast<GetPositionFuncType *>(ptr_method);
		ptr_method = NULL;
    }
};
#endif
