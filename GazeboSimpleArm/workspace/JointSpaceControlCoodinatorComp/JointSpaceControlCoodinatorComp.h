
#ifndef _JointSpaceControlCoodinatorComp_COMPONENT_H
#define _JointSpaceControlCoodinatorComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include "JointSpaceControlServiceRequired.h"
#include "ManipulatorServiceRequired.h"
#include "TrajectoryGenerationServiceRequired.h"
#include "JointSpaceControlCoorinatorServiceProvided.h"

class JointSpaceControlCoodinatorComp: public Component
	,public IJointSpaceControlCoorinatorService
{
protected:
	size_t _numberOfJoints;
	bool _isFirst;
	size_t _numberOfTrajectory;
	size_t _indexOfTrajectory;
	pthread_mutex_t _mutex;

	OPRoS::Float64Array _actualAcceleration;
	OPRoS::Float64Array _actualVelocity;
	OPRoS::Float64Array _actualPosition;
	OPRoS::Float64Array _desiredAcceleration;
	OPRoS::Float64Array _desiredVelocity;
	OPRoS::Float64Array _desiredPosition;
	OPRoS::Float64Array _desiredTorque;

	std::vector< std::valarray<double> > _trajectoryAcceleration;
	std::vector< std::valarray<double> > _trajectoryVelocity;
	std::vector< std::valarray<double> > _trajectoryPosition;

	IJointSpaceControlCoorinatorService *ptrJointSpaceControlCoordinatorService;
	TrajectoryGenerationServiceRequired *ptrTrajectoryGenerationService;
	ManipulatorServiceRequired *ptrManipulatorService;
	JointSpaceControlServiceRequired *ptrJointSpaceControlService;
	
public:
	virtual ReturnType Enable();
	virtual ReturnType Disable();
	virtual ReturnType SetDesiredJointPosition(OPRoS::Float64Array desiredJointPosition,float64_t time);
	virtual OPRoS::Float64Array GetActualJointAcceleration();
	virtual OPRoS::Float64Array GetActualJointVelocity();
	virtual OPRoS::Float64Array GetActualJointPosition();

public:
	JointSpaceControlCoodinatorComp();
	JointSpaceControlCoodinatorComp(const std::string &compId);
	virtual ~JointSpaceControlCoodinatorComp();
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

