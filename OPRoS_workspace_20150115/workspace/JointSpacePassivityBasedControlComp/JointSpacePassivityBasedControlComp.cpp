
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>
#include <stdio.h>

#include "JointSpacePassivityBasedControlComp.h"

//
// constructor declaration
//
JointSpacePassivityBasedControlComp::JointSpacePassivityBasedControlComp()
{
	_controller = NULL;
	
	portSetup();
}

//
// constructor declaration (with name)
//
JointSpacePassivityBasedControlComp::JointSpacePassivityBasedControlComp(const std::string &name):Component(name)
{
	_controller = NULL;
	
	portSetup();
}

//
// destructor declaration
//

JointSpacePassivityBasedControlComp::~JointSpacePassivityBasedControlComp()
{
	onDestroy();
}

ReturnType JointSpacePassivityBasedControlComp::SetProperty(OPRoS::Property props)
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
	Eigen::VectorXd K0, K1, K2, Ki, Kd;

	printf("Joint Space Passivity-Based Control\n");
	printf("Period : %f\n", period);
	printf("Number Of Joints : %d\n", numberOfJoints);
	printf("Joint Type	Joint Axis	X	Y	Z	MASS	CX	CY	CZ	IXX	IYY	IZZ	IXY	IXZ	IYZ	K0	K1	K2	Ki	Kd\n");

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

		snprintf(propertyName, sizeof(propertyName) - 1, "K0%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else {
			K0.conservativeResize(i+1, Eigen::NoChange);		K0(i) = atof(props.GetValue(propertyName).c_str());
		}

		snprintf(propertyName, sizeof(propertyName) - 1, "K1%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else {
			K1.conservativeResize(i+1, Eigen::NoChange);		K1(i) = atof(props.GetValue(propertyName).c_str());
		}

		snprintf(propertyName, sizeof(propertyName) - 1, "K2%d", i);
		if(props.FindName(propertyName) == false)		return OPROS_FIND_PROPERTY_ERROR;
		else {
			K2.conservativeResize(i+1, Eigen::NoChange);		K2(i) = atof(props.GetValue(propertyName).c_str());
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

		printf("	%d		%d	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f	%.4f\n",
				jointType, jointAxis, x, y, z, mass, cx, cy, cz, ixx, iyy, izz, ixy, ixz, iyz, K0(i), K1(i), K2(i), Ki(i), Kd(i));

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
		_controller = new JointSpacePassivityBasedControl(chain, period);
	}
	if(_controller->SetGain(K0, K1, K2, Ki, Kd) < 0) {
		return OPROS_SET_PROPERTY_ERROR;
	}

	_props = props;

	return OPROS_SUCCESS;
}

OPRoS::Property JointSpacePassivityBasedControlComp::GetProperty()
{
	return _props;
}

ReturnType JointSpacePassivityBasedControlComp::SetActualJointInfo(OPRoS::Float64Array actualJointAcceleration,OPRoS::Float64Array actualJointVelocity,OPRoS::Float64Array actualJointPosition)
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

ReturnType JointSpacePassivityBasedControlComp::SetDesiredJointInfo(OPRoS::Float64Array desiredJointAcceleration,OPRoS::Float64Array desiredJointVelocity,OPRoS::Float64Array desiredJointPosition)
{
	if(_controller == NULL) {
		return OPROS_PRECONDITION_NOT_MET;
	}

	size_t numberOfJoints = _controller->GetNumberOfJoints();

	if((desiredJointVelocity.data.size() != numberOfJoints) || (desiredJointPosition.data.size() != numberOfJoints)) {
		return OPROS_BAD_INPUT_PARAMETER;
	}

	Eigen::VectorXd velocity(numberOfJoints), position(numberOfJoints);
	for(size_t i = 0; i < numberOfJoints; i++) {
		velocity(i) = desiredJointVelocity.data[i]*KDL::deg2rad;
		position[i] = desiredJointPosition.data[i]*KDL::deg2rad;
	}

	if(_controller->SetDesiredJntInfo(velocity, position) < 0) {
		return OPROS_BAD_INPUT_PARAMETER;
	}

	return OPROS_SUCCESS;
}

OPRoS::Float64Array JointSpacePassivityBasedControlComp::CalculateJointTorque()
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

void JointSpacePassivityBasedControlComp::portSetup() {
	ProvidedServicePort *pa1;
	pa1=new JointSpaceControlServiceProvided(this);
	addPort("JointSpaceControlService",pa1);
}

// Call back Declaration
ReturnType JointSpacePassivityBasedControlComp::onInitialize()
{
	std::map<std::string, std::string> temp = getPropertyMap();
	OPRoS::Property props;
	props.SetProperty(temp);


	return SetProperty(props);
}

ReturnType JointSpacePassivityBasedControlComp::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType JointSpacePassivityBasedControlComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpacePassivityBasedControlComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpacePassivityBasedControlComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpacePassivityBasedControlComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpacePassivityBasedControlComp::onDestroy()
{
	if(_controller != NULL) {
		delete _controller;
		_controller = NULL;
	}

	return OPROS_SUCCESS;
}

ReturnType JointSpacePassivityBasedControlComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpacePassivityBasedControlComp::onExecute()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType JointSpacePassivityBasedControlComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpacePassivityBasedControlComp::onPeriodChanged()
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
	return new JointSpacePassivityBasedControlComp();
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
	return new JointSpacePassivityBasedControlComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

