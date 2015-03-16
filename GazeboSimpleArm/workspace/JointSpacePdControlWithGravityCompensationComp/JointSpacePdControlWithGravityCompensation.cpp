#include "JointSpacePdControlWithGravityCompensation.h"

JointSpacePdControlWithGravityCompensation::JointSpacePdControlWithGravityCompensation(KDL::Chain chain, double period)
: JointSpaceControl(chain, period)
{
	Kp.resize(_numberOfJoints, _numberOfJoints);
	Kd.resize(_numberOfJoints, _numberOfJoints);
}

JointSpacePdControlWithGravityCompensation::~JointSpacePdControlWithGravityCompensation()
{

}

int JointSpacePdControlWithGravityCompensation::SetGain(Eigen::VectorXd &Kp, Eigen::VectorXd &Kd)
{
	if(((size_t)Kp.size() != _numberOfJoints) || ((size_t)Kd.size() != _numberOfJoints)) {
		return -1;
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		this->Kp(i, i) = Kp(i);
		this->Kd(i, i) = Kd(i);
	}

	return 0;
}

int JointSpacePdControlWithGravityCompensation::GetGain(Eigen::VectorXd &Kp, Eigen::VectorXd &Kd)
{
	if((size_t)Kp.size() != _numberOfJoints) {
		Kp.resize(_numberOfJoints);
	}
	if((size_t)Kd.size() != _numberOfJoints) {
		Kd.resize(_numberOfJoints);
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		Kp(i) = this->Kp(i, i);
		Kd(i) = this->Kd(i, i);
	}

	return 0;
}

int JointSpacePdControlWithGravityCompensation::ResetVariables(void)
{
	ResetJointInfo();

	return 0;
}

int JointSpacePdControlWithGravityCompensation::Solve(Eigen::VectorXd &torque)
{
	if(SolveGravity(q) < 0) {
		return -1;
	}

	if((size_t)torque.size() != _numberOfJoints) {
		torque.resize(_numberOfJoints);
	}

	torque = Kp*(dq - q) - Kd*qdot + G;

	return 0;
}
