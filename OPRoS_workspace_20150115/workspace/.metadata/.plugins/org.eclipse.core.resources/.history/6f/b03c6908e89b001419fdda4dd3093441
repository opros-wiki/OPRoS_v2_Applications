

#ifndef _JointSpaceControlCoorinatorService_PROVIDED_PORT_H
#define _JointSpaceControlCoorinatorService_PROVIDED_PORT_H

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
		

#ifndef _IJointSpaceControlCoorinatorService_CLASS_DEF
#define _IJointSpaceControlCoorinatorService_CLASS_DEF
/*
 * IJointSpaceControlCoorinatorService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IJointSpaceControlCoorinatorService
{
 public:
    virtual ReturnType Enable()=0;
    virtual ReturnType Disable()=0;
    virtual ReturnType SetDesiredJointPosition(OPRoS::Float64Array desiredJointPosition,float64_t time)=0;
    virtual OPRoS::Float64Array GetActualJointAcceleration()=0;
    virtual OPRoS::Float64Array GetActualJointVelocity()=0;
    virtual OPRoS::Float64Array GetActualJointPosition()=0;
 };
#endif

/*
 * 
 * JointSpaceControlCoorinatorService : public ProvidedServicePort
 *
 */
class JointSpaceControlCoorinatorServiceProvided
	:public ProvidedServicePort, public IJointSpaceControlCoorinatorService
{
protected:
    IJointSpaceControlCoorinatorService *pcom;


   typedef ProvidedMethod<ReturnType> EnableFuncType;
   EnableFuncType *EnableFunc;

   typedef ProvidedMethod<ReturnType> DisableFuncType;
   DisableFuncType *DisableFunc;

   typedef ProvidedMethod<ReturnType> SetDesiredJointPositionFuncType;
   SetDesiredJointPositionFuncType *SetDesiredJointPositionFunc;

   typedef ProvidedMethod<OPRoS::Float64Array> GetActualJointAccelerationFuncType;
   GetActualJointAccelerationFuncType *GetActualJointAccelerationFunc;

   typedef ProvidedMethod<OPRoS::Float64Array> GetActualJointVelocityFuncType;
   GetActualJointVelocityFuncType *GetActualJointVelocityFunc;

   typedef ProvidedMethod<OPRoS::Float64Array> GetActualJointPositionFuncType;
   GetActualJointPositionFuncType *GetActualJointPositionFunc;


public: // default method
   virtual ReturnType Enable()
   {
		opros_assert(EnableFunc != NULL);
		
            return (*EnableFunc)();
		
   }
   virtual ReturnType Disable()
   {
		opros_assert(DisableFunc != NULL);
		
            return (*DisableFunc)();
		
   }
   virtual ReturnType SetDesiredJointPosition(OPRoS::Float64Array desiredJointPosition,float64_t time)
   {
		opros_assert(SetDesiredJointPositionFunc != NULL);
		
            return (*SetDesiredJointPositionFunc)(desiredJointPosition,time);
		
   }
   virtual OPRoS::Float64Array GetActualJointAcceleration()
   {
		opros_assert(GetActualJointAccelerationFunc != NULL);
		
            return (*GetActualJointAccelerationFunc)();
		
   }
   virtual OPRoS::Float64Array GetActualJointVelocity()
   {
		opros_assert(GetActualJointVelocityFunc != NULL);
		
            return (*GetActualJointVelocityFunc)();
		
   }
   virtual OPRoS::Float64Array GetActualJointPosition()
   {
		opros_assert(GetActualJointPositionFunc != NULL);
		
            return (*GetActualJointPositionFunc)();
		
   }


public:
    //
    // Constructor
    //
    JointSpaceControlCoorinatorServiceProvided(IJointSpaceControlCoorinatorService *fn)
    {
        pcom = fn;

        EnableFunc = NULL;
        DisableFunc = NULL;
        SetDesiredJointPositionFunc = NULL;
        GetActualJointAccelerationFunc = NULL;
        GetActualJointVelocityFunc = NULL;
        GetActualJointPositionFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IJointSpaceControlCoorinatorService::Enable,pcom,"Enable");

        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IJointSpaceControlCoorinatorService::Disable,pcom,"Disable");

        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IJointSpaceControlCoorinatorService::SetDesiredJointPosition,pcom,"SetDesiredJointPosition");

        opros_assert(ptr_method != NULL);
        addMethod("SetDesiredJointPosition",ptr_method);
        SetDesiredJointPositionFunc = reinterpret_cast<SetDesiredJointPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IJointSpaceControlCoorinatorService::GetActualJointAcceleration,pcom,"GetActualJointAcceleration");

        opros_assert(ptr_method != NULL);
        addMethod("GetActualJointAcceleration",ptr_method);
        GetActualJointAccelerationFunc = reinterpret_cast<GetActualJointAccelerationFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IJointSpaceControlCoorinatorService::GetActualJointVelocity,pcom,"GetActualJointVelocity");

        opros_assert(ptr_method != NULL);
        addMethod("GetActualJointVelocity",ptr_method);
        GetActualJointVelocityFunc = reinterpret_cast<GetActualJointVelocityFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IJointSpaceControlCoorinatorService::GetActualJointPosition,pcom,"GetActualJointPosition");

        opros_assert(ptr_method != NULL);
        addMethod("GetActualJointPosition",ptr_method);
        GetActualJointPositionFunc = reinterpret_cast<GetActualJointPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
