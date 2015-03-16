#include "JointSpaceInverseDynamicsControl.h"

JointSpaceInverseDynamicsControl::JointSpaceInverseDynamicsControl(KDL::Chain chain, double period)
: JointSpaceControl(chain, period)
{
	Kp.resize(_numberOfJoints, _numberOfJoints);
	Ki.resize(_numberOfJoints, _numberOfJoints);
	Kd.resize(_numberOfJoints, _numberOfJoints);

	qErrSum.resize(_numberOfJoints);

	ResetVariables();
}

JointSpaceInverseDynamicsControl::~JointSpaceInverseDynamicsControl()
{

}

int JointSpaceInverseDynamicsControl::SetGain(Eigen::VectorXd &Kp, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd)
{
	if(((size_t)Kp.size() != _numberOfJoints) || ((size_t)Ki.size() != _numberOfJoints) || ((size_t)Kd.size() != _numberOfJoints)) {
		return -1;
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		this->Kp(i, i) = Kp(i);
		this->Ki(i, i) = Ki(i);
		this->Kd(i, i) = Kd(i);
	}

	qErrSum.setZero();

	return 0;
}

int JointSpaceInverseDynamicsControl::GetGain(Eigen::VectorXd &Kp, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd)
{
	if((size_t)Kp.size() != _numberOfJoints) {
		Kp.resize(_numberOfJoints);
	}
	if((size_t)Ki.size() != _numberOfJoints) {
			Ki.resize(_numberOfJoints);
		}
	if((size_t)Kd.size() != _numberOfJoints) {
		Kd.resize(_numberOfJoints);
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		Kp(i) = this->Kp(i, i);
		Ki(i) = this->Ki(i, i);
		Kd(i) = this->Kd(i, i);
	}

	return 0;
}

int JointSpaceInverseDynamicsControl::ResetVariables(void)
{
	ResetJointInfo();

	qErrSum.setZero();

	return 0;
}

int JointSpaceInverseDynamicsControl::Solve(Eigen::VectorXd &torque)
{
	if(SolveInertia(q) < 0)			return -1;
	if(SolveCoriolis(q, qdot) < 0)	return -1;
	if(SolveGravity(q) < 0)			return -1;

	if((size_t)torque.size() != _numberOfJoints) {
		torque.resize(_numberOfJoints);
	}

	qErrSum += (dq - q)*_period;

	torque = H*(dq2dot + Kd*(dqdot - qdot) + Kp*(dq - q) + Ki*qErrSum) + C + G;

	return 0;
}
