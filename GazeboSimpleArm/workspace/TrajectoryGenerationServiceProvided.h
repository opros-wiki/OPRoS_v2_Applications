#ifndef _TrajectoryGenerationService_PROVIDED_PORT_H
#define _TrajectoryGenerationService_PROVIDED_PORT_H

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
		

#ifndef _ITrajectoryGenerationService_CLASS_DEF
#define _ITrajectoryGenerationService_CLASS_DEF
/*
 * ITrajectoryGenerationService
 *
 *  The comonent inherits this class and implements methods. 
 */
class ITrajectoryGenerationService
{
public:
	virtual ReturnType SetProperty(OPRoS::Property props)=0;
	virtual OPRoS::Property GetProperty()=0;
	virtual ReturnType GetError()=0;
	virtual ReturnType GenerateTrajectory(vector< valarray<float64_t> > path,float64_t deltaTime)=0;
	virtual vector < valarray<float64_t> > GetAcceleration()=0;
	virtual vector < valarray<float64_t> > GetVelocity()=0;
	virtual vector < valarray<float64_t> > GetPosition()=0;
};
#endif

/*
 * 
 * TrajectoryGenerationService : public ProvidedServicePort
 *
 */
class TrajectoryGenerationServiceProvided : public ProvidedServicePort, public ITrajectoryGenerationService
{
protected:
	ITrajectoryGenerationService *pcom;

	typedef ProvidedMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef ProvidedMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef ProvidedMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef ProvidedMethod<ReturnType> GenerateTrajectoryFuncType;
	GenerateTrajectoryFuncType *GenerateTrajectoryFunc;

	typedef ProvidedMethod<vector < valarray<float64_t> > > GetAccelerationFuncType;
	GetAccelerationFuncType *GetAccelerationFunc;

	typedef ProvidedMethod<vector < valarray<float64_t> > > GetVelocityFuncType;
	GetVelocityFuncType *GetVelocityFunc;

	typedef ProvidedMethod<vector < valarray<float64_t> > > GetPositionFuncType;
	GetPositionFuncType *GetPositionFunc;


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

	virtual ReturnType GetError()
	{
		opros_assert(GetErrorFunc != NULL);

		return (*GetErrorFunc)();
	}

	virtual ReturnType GenerateTrajectory(vector< valarray<float64_t> > path,float64_t deltaTime)
	{
		opros_assert(GenerateTrajectoryFunc != NULL);

		return (*GenerateTrajectoryFunc)(path,deltaTime);
	}

	virtual vector < valarray<float64_t> > GetAcceleration()
	{
		opros_assert(GetAccelerationFunc != NULL);

		return (*GetAccelerationFunc)();
	}
	
	virtual vector < valarray<float64_t> > GetVelocity()
	{
		opros_assert(GetVelocityFunc != NULL);

		return (*GetVelocityFunc)();
	}

	virtual vector < valarray<float64_t> > GetPosition()
	{
		opros_assert(GetPositionFunc != NULL);

		return (*GetPositionFunc)();
	}

public:
	//
	// Constructor
	//
	TrajectoryGenerationServiceProvided(ITrajectoryGenerationService *fn)
	{
		pcom = fn;

		SetPropertyFunc = NULL;
		GetPropertyFunc = NULL;
		GetErrorFunc = NULL;
		GenerateTrajectoryFunc = NULL;
		GetAccelerationFunc = NULL;
		GetVelocityFunc = NULL;
		GetPositionFunc = NULL;

		setup();
	}

	// generated setup function
	virtual void setup()
	{
		Method *ptr_method;

		ptr_method = makeProvidedMethod(&ITrajectoryGenerationService::SetProperty,pcom,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeProvidedMethod(&ITrajectoryGenerationService::GetProperty,pcom,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeProvidedMethod(&ITrajectoryGenerationService::GetError,pcom,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeProvidedMethod(&ITrajectoryGenerationService::GenerateTrajectory,pcom,"GenerateTrajectory");
		opros_assert(ptr_method != NULL);
		addMethod("GenerateTrajectory",ptr_method);
		GenerateTrajectoryFunc = reinterpret_cast<GenerateTrajectoryFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeProvidedMethod(&ITrajectoryGenerationService::GetAcceleration,pcom,"GetAcceleration");
		opros_assert(ptr_method != NULL);
		addMethod("GetAcceleration",ptr_method);
		GetAccelerationFunc = reinterpret_cast<GetAccelerationFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeProvidedMethod(&ITrajectoryGenerationService::GetVelocity,pcom,"GetVelocity");
		opros_assert(ptr_method != NULL);
		addMethod("GetVelocity",ptr_method);
		GetVelocityFunc = reinterpret_cast<GetVelocityFuncType *>(ptr_method);
		ptr_method = NULL;
    
		ptr_method = makeProvidedMethod(&ITrajectoryGenerationService::GetPosition,pcom,"GetPosition");
		opros_assert(ptr_method != NULL);
		addMethod("GetPosition",ptr_method);
		GetPositionFunc = reinterpret_cast<GetPositionFuncType *>(ptr_method);
		ptr_method = NULL;
	}
};
#endif
