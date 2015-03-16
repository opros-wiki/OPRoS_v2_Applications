
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>
#include <stdio.h>

#include "JointSpaceInverseDynamicsControlComp.h"

//
// constructor declaration
//
JointSpaceInverseDynamicsControlComp::JointSpaceInverseDynamicsControlComp()
{
	_controller = NULL;
	
	portSetup();
}

//
// constructor declaration (with name)
//
JointSpaceInverseDynamicsControlComp::JointSpaceInverseDynamicsControlComp(const std::string &name):Component(name)
{
	_controller = NULL;
	
	portSetup();
}

//
// destructor declaration
//

JointSpaceInverseDynamicsControlComp::~JointSpaceInverseDynamicsControlComp()
{
	onDestroy();
}

ReturnType JointSpaceInverseDynamicsControlComp::SetProperty(OPRoS::Property props)
{
	double period;
	if(props.FindName("Period") == false) return OPROS_FIND_PROPERTY_ERROR;
	period = atof(props.GetValue("Period").c_str());

	size_t numberOfJoints;
	if(props.FindName("NumberOfJoints") == false) return OPROS_FIND_PROPERTY_ERROR;
	numberOfJoints = atoi(props.GetValue("NumberOfJoints").c_str());

	KDL::Chain chain;
	char propertyName[128];
	int jointType, jointAxis;
	double x, y, z;
	double mass;
	double cx, cy, cz;
	double ixx, iyy, izz, ixy, ixz, iyz;
	Eigen::VectorXd Kp, Ki, Kd;

	printf("Joint Space Inverse Dynamics Control Control\n");
	printf("Period : %f\n", period);
	printf("Number Of Joints : %d\n", numberOfJoints);
	printf("Joint Type	Joint Axis	X	Y	Z	MASS	CX	CY	CZ	IXX	IYY	IZZ	IXY	IXZ	IYZ	Kp	Ki	Kd\n");

	for(size_t i = 0; i < numberOfJoints; i++) {
		snprintf(propertyName, sizeof(propertyName) - 1, "JointType%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												jointType = atoi(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "JointAxis%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												jointAxis = atoi(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "X%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												x = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "Y%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												y = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "Z%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												z = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "Mass%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												mass = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "CX%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												cx = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "CY%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												cy = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "CZ%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												cz = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "IXX%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												ixx = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "IYY%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												iyy = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "IZZ%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												izz = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "IXY%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												ixy = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "IXZ%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												ixz = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "IYZ%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else												iyz = atof(props.GetValue(propertyName).c_str());

		snprintf(propertyName, sizeof(propertyName) - 1, "Kp%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else {
			Kp.conservativeResize(i+1, Eigen::NoChange);		Kp(i) = atof(props.GetValue(propertyName).c_str());
		}

		snprintf(propertyName, sizeof(propertyName) - 1, "Ki%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else {
			Ki.conservativeResize(i+1, Eigen::NoChange);		Ki(i) = atof(props.GetValue(propertyName).c_str());
		}

		snprintf(propertyName, sizeof(propertyName) - 1, "Kd%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else {
			Kd.conservativeResize(i+1, Eigen::NoChange);		Kd(i) = atof(props.GetValue(propertyName).c_str());
		}

		printf("	%d		%d	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f\n",
				jointType, jointAxis, x, y, z, mass, cx, cy, cz, ixx, iyy, izz, ixy, ixz, iyz, Kp(i), Ki(i), Kd(i));

		if(jointType == 0) {
			chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::None), KDL::Frame(KDL::Vector(x, y, z)), KDL::RigidBodyInertia(mass, KDL::Vector(cx, cy, cz), KDL::RotationalInertia(ixx, iyy, izz, ixy, ixz, iyz))));
		}
		else if(jointType == 1) {	//	Revolute Joint
			if(jointAxis == 0)		chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotX), KDL::Frame(KDL::Vector(x, y, z)), KDL::RigidBodyInertia(mass, KDL::Vector(cx, cy, cz), KDL::RotationalInertia(ixx, iyy, izz, ixy, ixz, iyz))));
			else if(jointAxis == 1)	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotY), KDL::Frame(KDL::Vector(x, y, z)), KDL::RigidBodyInertia(mass, KDL::Vector(cx, cy, cz), KDL::RotationalInertia(ixx, iyy, izz, ixy, ixz, iyz))));
			else if(jointAxis == 2)	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ), KDL::Frame(KDL::Vector(x, y, z)), KDL::RigidBodyInertia(mass, KDL::Vector(cx, cy, cz), KDL::RotationalInertia(ixx, iyy, izz, ixy, ixz, iyz))));
		}
		else if(jointType == 2) {	//	Prismatic Joint
			if(jointAxis == 0)		chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::TransX), KDL::Frame(KDL::Vector(x, y, z)), KDL::RigidBodyInertia(mass, KDL::Vector(cx, cy, cz), KDL::RotationalInertia(ixx, iyy, izz, ixy, ixz, iyz))));
			else if(jointAxis == 1)	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::TransY), KDL::Frame(KDL::Vector(x, y, z)), KDL::RigidBodyInertia(mass, KDL::Vector(cx, cy, cz), KDL::RotationalInertia(ixx, iyy, izz, ixy, ixz, iyz))));
			else if(jointAxis == 2)	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::TransZ), KDL::Frame(KDL::Vector(x, y, z)), KDL::RigidBodyInertia(mass, KDL::Vector(cx, cy, cz), KDL::RotationalInertia(ixx, iyy, izz, ixy, ixz, iyz))));
		}
	}

	if(_controller == NULL) {
		_controller = new JointSpaceInverseDynamicsControl(chain, period);
	}
	if(_controller->SetGain(Kp, Ki, Kd) < 0) {
		return OPROS_SET_PROPERTY_ERROR;
	}

	_props = props;

	return OPROS_SUCCESS;
}

OPRoS::Property JointSpaceInverseDynamicsControlComp::GetProperty()
{
	return _props;
}

ReturnType JointSpaceInverseDynamicsControlComp::SetActualJointInfo(OPRoS::Float64Array actualJointAcceleration,OPRoS::Float64Array actualJointVelocity,OPRoS::Float64Array actualJointPosition)
{
	if(_controller == NULL) {
			return OPROS_PRECONDITION_NOT_MET;
		}

		size_t numberOfJoints = _controller->GetNumberOfJoints();

		if((actualJointVelocity.data.size() != numberOfJoints) || (actualJointPosition.data.size() != numberOfJoints)) {
			return OPROS_BAD_INPUT_PARAMETER;
		}

		Eigen::VectorXd velocity(numberOfJoints), position(numberOfJoints);
		for(size_t i = 0; i < numberOfJoints; i++) {
			velocity(i) = actualJointVelocity.data[i]*KDL::deg2rad;
			position[i] = actualJointPosition.data[i]*KDL::deg2rad;
		}

		if(_controller->SetActualJntInfo(velocity, position) < 0) {
			return OPROS_BAD_INPUT_PARAMETER;
		}

		return OPROS_SUCCESS;
}

ReturnType JointSpaceInverseDynamicsControlComp::SetDesiredJointInfo(OPRoS::Float64Array desiredJointAcceleration,OPRoS::Float64Array desiredJointVelocity,OPRoS::Float64Array desiredJointPosition)
{
	if(_controller == NULL) {
		return OPROS_PRECONDITION_NOT_MET;
	}

	size_t numberOfJoints = _controller->GetNumberOfJoints();

	if((desiredJointAcceleration.data.size() != numberOfJoints) || (desiredJointVelocity.data.size() != numberOfJoints) || (desiredJointPosition.data.size() != numberOfJoints)) {
		return OPROS_BAD_INPUT_PARAMETER;
	}

	Eigen::VectorXd acceleration(numberOfJoints), velocity(numberOfJoints), position(numberOfJoints);
	for(size_t i = 0; i < numberOfJoints; i++) {
		acceleration[i] = desiredJointAcceleration.data[i]*KDL::deg2rad;
		velocity(i) = desiredJointVelocity.data[i]*KDL::deg2rad;
		position[i] = desiredJointPosition.data[i]*KDL::deg2rad;
	}

	if(_controller->SetDesiredJntInfo(acceleration, velocity, position) < 0) {
		return OPROS_BAD_INPUT_PARAMETER;
	}

	return OPROS_SUCCESS;
}

OPRoS::Float64Array JointSpaceInverseDynamicsControlComp::CalculateJointTorque()
{
	size_t numberOfJoints = _controller->GetNumberOfJoints();
		OPRoS::Float64Array ret;
		ret.status = OPROS_SUCCESS;
		ret.data.resize(numberOfJoints);

		if(_controller == NULL) {
			ret.status = OPROS_PRECONDITION_NOT_MET;
			return ret;
		}

		Eigen::VectorXd torque(numberOfJoints);

		if(_controller->Solve(torque) < 0) {
			ret.status = OPROS_INTERNAL_FAULT;
			return ret;
		}

		memcpy(&ret.data[0], &torque(0), numberOfJoints*sizeof(double));

		return ret;
}

void JointSpaceInverseDynamicsControlComp::portSetup()
{
	ProvidedServicePort *pa1;
	pa1=new JointSpaceControlServiceProvided(this);
	addPort("JointSpaceControlService",pa1);
}

// Call back Declaration
ReturnType JointSpaceInverseDynamicsControlComp::onInitialize()
{
	std::map<std::string, std::string> temp = getPropertyMap();
	OPRoS::Property props;
	props.SetProperty(temp);

	return SetProperty(props);
}

ReturnType JointSpaceInverseDynamicsControlComp::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType JointSpaceInverseDynamicsControlComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceInverseDynamicsControlComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceInverseDynamicsControlComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceInverseDynamicsControlComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceInverseDynamicsControlComp::onDestroy()
{
	if(_controller != NULL) {
		delete _controller;
		_controller = NULL;
	}

	return OPROS_SUCCESS;
}

ReturnType JointSpaceInverseDynamicsControlComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceInverseDynamicsControlComp::onExecute()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType JointSpaceInverseDynamicsControlComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceInverseDynamicsControlComp::onPeriodChanged()
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
	return new JointSpaceInverseDynamicsControlComp();
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
	return new JointSpaceInverseDynamicsControlComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

