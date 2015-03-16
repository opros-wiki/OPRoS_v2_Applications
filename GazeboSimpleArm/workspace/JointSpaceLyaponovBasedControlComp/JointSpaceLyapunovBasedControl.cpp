#include "JointSpaceLyapunovBasedControl.h"

JointSpaceLyapunovBasedControl::JointSpaceLyapunovBasedControl(KDL::Chain chain, double period)
: JointSpaceControl(chain, period)
{
	Lambda.resize(_numberOfJoints, _numberOfJoints);
	Ki.resize(_numberOfJoints, _numberOfJoints);
	Kd.resize(_numberOfJoints, _numberOfJoints);

	zetadot.resize(_numberOfJoints);
	zetadotPrev.resize(_numberOfJoints);
	zeta2dot.resize(_numberOfJoints);

	sigma.resize(_numberOfJoints);
	sigmaSum.resize(_numberOfJoints);

	ResetVariables();
}

JointSpaceLyapunovBasedControl::~JointSpaceLyapunovBasedControl()
{

}

int JointSpaceLyapunovBasedControl::SetGain(Eigen::VectorXd &Lambda, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd)
{
	if(((size_t)Lambda.size() != _numberOfJoints) || ((size_t)Ki.size() != _numberOfJoints) || ((size_t)Kd.size() != _numberOfJoints)) {
		return -1;
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		this->Lambda(i, i) = Lambda(i);
		this->Ki(i, i) = Ki(i);
		this->Kd(i, i) = Kd(i);
	}

	sigmaSum.setZero();

	return 0;
}

int JointSpaceLyapunovBasedControl::GetGain(Eigen::VectorXd &Lambda, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd)
{
	if((size_t)Lambda.size() != _numberOfJoints) {
		Lambda.resize(_numberOfJoints);
	}
	if((size_t)Ki.size() != _numberOfJoints) {
			Ki.resize(_numberOfJoints);
		}
	if((size_t)Kd.size() != _numberOfJoints) {
		Kd.resize(_numberOfJoints);
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		Lambda(i) = this->Lambda(i, i);
		Ki(i) = this->Ki(i, i);
		Kd(i) = this->Kd(i, i);
	}

	return 0;
}

int JointSpaceLyapunovBasedControl::ResetVariables(void)
{
	ResetJointInfo();

	zetadot.setZero();
	zetadotPrev.setZero();
	zeta2dot.setZero();

	sigma.setZero();
	sigmaSum.setZero();

	return 0;
}

int JointSpaceLyapunovBasedControl::Solve(Eigen::VectorXd &torque)
{
	if(SolveInertia(q) < 0)			return -1;
	if(SolveCoriolis(q, qdot) < 0)	return -1;
	if(SolveGravity(q) < 0)			return -1;

	if((size_t)torque.size() != _numberOfJoints) {
		torque.resize(_numberOfJoints);
	}

	zetadot = dqdot - Lambda*(q - dq);
	zeta2dot = (zetadot - zetadotPrev)/_period;
	zetadotPrev = zetadot;

	sigma = qdot - zetadot;
	sigmaSum += sigma*_period;

	torque = H*zeta2dot - Kd*sigma - Ki*sigmaSum + C + G;

	return 0;
}
