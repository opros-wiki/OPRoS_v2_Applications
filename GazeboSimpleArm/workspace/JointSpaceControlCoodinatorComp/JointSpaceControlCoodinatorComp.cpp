
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>
#include <stdio.h>
#include <sys/time.h>

#include "JointSpaceControlCoodinatorComp.h"
#include "OprosPrintMessage.h"

FILE *fp = NULL;

//
// constructor declaration
//
JointSpaceControlCoodinatorComp::JointSpaceControlCoodinatorComp()
{
	ptrTrajectoryGenerationService = NULL;
	ptrManipulatorService = NULL;
	ptrJointSpaceControlService = NULL;
	
	_numberOfTrajectory = 0;
	_indexOfTrajectory = 0;

	_isFirst = true;
	pthread_mutex_init(&_mutex, NULL);

	fp = fopen("data.txt", "w");

	portSetup();
}

//
// constructor declaration (with name)
//
JointSpaceControlCoodinatorComp::JointSpaceControlCoodinatorComp(const std::string &name):Component(name)
{
	ptrTrajectoryGenerationService = NULL;
	ptrManipulatorService = NULL;
	ptrJointSpaceControlService = NULL;

	_numberOfTrajectory = 0;
	_indexOfTrajectory = 0;

	_isFirst = true;
	pthread_mutex_init(&_mutex, NULL);
	
	fp = fopen("data.txt", "w");

	portSetup();
}

//
// destructor declaration
//

JointSpaceControlCoodinatorComp::~JointSpaceControlCoodinatorComp()
{
	pthread_mutex_destroy(&_mutex);
	onDestroy();

	fclose(fp);
}

ReturnType JointSpaceControlCoodinatorComp::Enable()
{
	return ptrManipulatorService->Enable();
}

ReturnType JointSpaceControlCoodinatorComp::Disable()
{
	return ptrManipulatorService->Disable();
}

ReturnType JointSpaceControlCoodinatorComp::SetDesiredJointPosition(OPRoS::Float64Array desiredJointPosition, float64_t time)
{
	PrintMessage("INFO : JointSpaceControlCoodinatorComp::SetDesiredJointPosition().\n");

	if(desiredJointPosition.data.size() != _numberOfJoints) {
		return OPROS_BAD_INPUT_PARAMETER;
	}

	PrintMessage("INFO : JointSpaceControlCoodinatorComp::SetDesiredJointPosition() -> desiredJointPosition : ");
	for(size_t i = 0; i < _numberOfJoints; i++) {
		PrintMessage("%.3f\t", desiredJointPosition.data[i]);
	}
	PrintMessage("\n");

	pthread_mutex_lock(&_mutex);
	_numberOfTrajectory = 0;

	std::vector< std::valarray<double> > trajectory;
	trajectory.resize(2);
	trajectory[0].resize(_numberOfJoints+1);		trajectory[0][0] = 0.0;
	trajectory[1].resize(_numberOfJoints+1);		trajectory[1][0] = time;

	for(size_t i = 0; i < _numberOfJoints; i++) {
		trajectory[0][i+1] = _actualPosition.data[i];
		trajectory[1][i+1] = desiredJointPosition.data[i];
	}
	pthread_mutex_unlock(&_mutex);

	if(ptrTrajectoryGenerationService->GenerateTrajectory(trajectory, 0.004) != OPROS_SUCCESS) {
		return OPROS_BAD_INPUT_PARAMETER;
	}

	_trajectoryAcceleration = ptrTrajectoryGenerationService->GetAcceleration();
	_trajectoryVelocity = ptrTrajectoryGenerationService->GetVelocity();
	_trajectoryPosition = ptrTrajectoryGenerationService->GetPosition();

	pthread_mutex_lock(&_mutex);

	_numberOfTrajectory = _trajectoryPosition.size();
	_indexOfTrajectory = 0;

	pthread_mutex_unlock(&_mutex);
}

OPRoS::Float64Array JointSpaceControlCoodinatorComp::GetActualJointAcceleration()
{
	return _actualAcceleration;
}

OPRoS::Float64Array JointSpaceControlCoodinatorComp::GetActualJointVelocity()
{
	return _actualVelocity;
}

OPRoS::Float64Array JointSpaceControlCoodinatorComp::GetActualJointPosition()
{
	return _actualPosition;
}

void JointSpaceControlCoodinatorComp::portSetup() {
	ProvidedServicePort *pa1;
	pa1=new JointSpaceControlCoorinatorServiceProvided(this);
	addPort("JointSpaceControlCoordinatorService",pa1);

	ptrTrajectoryGenerationService=new TrajectoryGenerationServiceRequired();
	addPort("TrajectoryGenerationService",ptrTrajectoryGenerationService);

	ptrManipulatorService=new ManipulatorServiceRequired();
	addPort("ManipulatorService",ptrManipulatorService);

	ptrJointSpaceControlService=new JointSpaceControlServiceRequired();
	addPort("JointSpaceControlService",ptrJointSpaceControlService);
}

// Call back Declaration
ReturnType JointSpaceControlCoodinatorComp::onInitialize()
{
	PrintMessage("INFO : JointSpaceControlCoodinatorComp::onInitialize().\n");

	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlCoodinatorComp::onStart()
{
	PrintMessage("INFO : JointSpaceControlCoodinatorComp::onStart().\n");

	OPRoS::Property props;
	size_t numberOfActuators;

	props = ptrManipulatorService->GetProperty();
	if(props.FindName("NumberOfActuators") == false) {
		printf("[ERROR] JointSpaceControlCoodinatorComp::onStart() -> Can't find the property(NumberOfActuators)\n");
		return OPROS_INTERNAL_FAULT;
	}
	numberOfActuators = atoi(props.GetValue("NumberOfActuators").c_str());

	props = ptrJointSpaceControlService->GetProperty();
	if(props.FindName("NumberOfJoints") == false) {
		printf("[ERROR] JointSpaceControlCoodinatorComp::onStart() -> Can't find the property(NumberOfJoints)\n");
		return OPROS_INTERNAL_FAULT;
	}
	_numberOfJoints = atoi(props.GetValue("NumberOfJoints").c_str());

	if(_numberOfJoints != numberOfActuators) {
		printf("[ERROR] JointSpaceControlCoodinatorComp::onStart() -> NumberOfActuators and NumberOfJoints are different from each other.\n");
		_numberOfJoints = 0;
		return OPROS_INTERNAL_FAULT;
	}

	_actualAcceleration.data.resize(_numberOfJoints);
	_actualVelocity.data.resize(_numberOfJoints);
	_actualPosition.data.resize(_numberOfJoints);
	_desiredAcceleration.data.resize(_numberOfJoints);
	_desiredVelocity.data.resize(_numberOfJoints);
	_desiredPosition.data.resize(_numberOfJoints);
	_desiredTorque.data.resize(_numberOfJoints);

	_numberOfTrajectory = 0;
	_indexOfTrajectory = 0;

	_isFirst = true;

	return OPROS_SUCCESS;
}
	
ReturnType JointSpaceControlCoodinatorComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlCoodinatorComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlCoodinatorComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlCoodinatorComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlCoodinatorComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlCoodinatorComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlCoodinatorComp::onExecute()
{
	struct timeval periodTv, startTimeTv, endTimeTv;
	double period, startTime, endTime;
	static double prevPeriod = 0.0;
	static int nIndex = 0;

	gettimeofday(&periodTv, NULL);

	std::vector<OPRoS::Float64> actualVelocity, actualPosition;
	std::vector<OPRoS::Float64> desiredTorque;

	pthread_mutex_lock(&_mutex);

	actualPosition = ptrManipulatorService->GetPosition();
	actualVelocity = ptrManipulatorService->GetVelocity();

	if((actualPosition.size() != _numberOfJoints) || (actualVelocity.size() != _numberOfJoints)) {
		pthread_mutex_unlock(&_mutex);
		return OPROS_INTERNAL_FAULT;
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		_actualVelocity.data[i] = actualVelocity[i].data;
		_actualPosition.data[i] = actualPosition[i].data;
	}

	if((0 < _numberOfTrajectory) && (_indexOfTrajectory < _numberOfTrajectory)) {
		for(size_t i = 0; i < _numberOfJoints; i++) {
			_desiredAcceleration.data[i] = _trajectoryAcceleration[_indexOfTrajectory][i+1];
			_desiredVelocity.data[i] = _trajectoryVelocity[_indexOfTrajectory][i+1];
			_desiredPosition.data[i] = _trajectoryPosition[_indexOfTrajectory][i+1];
		}
		_indexOfTrajectory++;
	}

	if(_isFirst == true) {
		_desiredPosition = _actualPosition;
		_isFirst = false;
	}

	gettimeofday(&startTimeTv, NULL);
	ptrJointSpaceControlService->SetActualJointInfo(_actualAcceleration, _actualVelocity, _actualPosition);
	ptrJointSpaceControlService->SetDesiredJointInfo(_desiredAcceleration, _desiredVelocity, _desiredPosition);
	_desiredTorque = ptrJointSpaceControlService->CalculateJointTorque();

	gettimeofday(&endTimeTv, NULL);

	desiredTorque.resize(_numberOfJoints);
	for(size_t i = 0; i < _numberOfJoints; i++) {
		desiredTorque[i].data = _desiredTorque.data[i];
	}

	ptrManipulatorService->SetTorque(desiredTorque);

	pthread_mutex_unlock(&_mutex);

	if(nIndex < 2000) {	//	8sec
		period = (double)periodTv.tv_sec*1000.0 + (double)periodTv.tv_usec*0.001;
		startTime = (double)startTimeTv.tv_sec*1000.0 + (double)startTimeTv.tv_usec*0.001;
		endTime = (double)endTimeTv.tv_sec*1000.0 + (double)endTimeTv.tv_usec*0.001;

		if(prevPeriod == 0.0) {
			prevPeriod = period;
		}

		fprintf(fp, "%.3f\t%.3f\t", period - prevPeriod, endTime - startTime);

		for(size_t i = 0; i < _numberOfJoints; i++) {
			fprintf(fp, "%.3f\t%.3f\t%.3f\t", _desiredPosition.data[i], _actualPosition.data[i], _desiredPosition.data[i] - _actualPosition.data[i]);
		}
		fprintf(fp, "\n");

		prevPeriod = period;

		nIndex++;
	}

	return OPROS_SUCCESS;
}
	
ReturnType JointSpaceControlCoodinatorComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlCoodinatorComp::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}

#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new JointSpaceControlCoodinatorComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new JointSpaceControlCoodinatorComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

