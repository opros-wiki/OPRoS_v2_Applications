
#ifndef _JointSpaceInverseDynamicsControlComp_COMPONENT_H
#define _JointSpaceInverseDynamicsControlComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include "JointSpaceInverseDynamicsControl.h"
#include "JointSpaceControlServiceProvided.h"

class JointSpaceInverseDynamicsControlComp: public Component
	,public IJointSpaceControlService
{
protected:
	IJointSpaceControlService *ptrJointSpaceControlService;
	JointSpaceInverseDynamicsControl *_controller;
	OPRoS::Property _props;

public:
	virtual ReturnType SetProperty(OPRoS::Property props);
	virtual OPRoS::Property GetProperty();
	virtual ReturnType SetActualJointInfo(OPRoS::Float64Array actualJointAcceleration,OPRoS::Float64Array actualJointVelocity,OPRoS::Float64Array actualJointPosition);
	virtual ReturnType SetDesiredJointInfo(OPRoS::Float64Array desiredJointAcceleration,OPRoS::Float64Array desiredJointVelocity,OPRoS::Float64Array desiredJointPosition);
	virtual OPRoS::Float64Array CalculateJointTorque();

public:
	JointSpaceInverseDynamicsControlComp();
	JointSpaceInverseDynamicsControlComp(const std::string &compId);
	virtual ~JointSpaceInverseDynamicsControlComp();
	virtual void portSetup();

protected:
	virtual ReturnType onInitialize();
	virtual ReturnType onStart();
	virtual ReturnType onStop();
	virtual ReturnType onReset();
	virtual ReturnType onError();
	virtual ReturnType onRecover();
	virtual ReturnType onDestroy();

public:
	virtual ReturnType onEvent(Event *evt);
	virtual ReturnType onExecute();
	virtual ReturnType onUpdated();
	virtual ReturnType onPeriodChanged();


};

#endif

