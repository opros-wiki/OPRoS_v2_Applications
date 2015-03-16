#include "JointSpacePassivityBasedControl.h"

JointSpacePassivityBasedControl::JointSpacePassivityBasedControl(KDL::Chain chain, double period)
: JointSpaceControl(chain, period)
{
	K0.resize(_numberOfJoints, _numberOfJoints);
	K1.resize(_numberOfJoints, _numberOfJoints);
	K2.resize(_numberOfJoints, _numberOfJoints);
	Ki.resize(_numberOfJoints, _numberOfJoints);
	Kd.resize(_numberOfJoints, _numberOfJoints);

	zetadot.resize(_numberOfJoints);
	zetadotPrev.resize(_numberOfJoints);
	zeta2dot.resize(_numberOfJoints);

	sigma.resize(_numberOfJoints);
	sigmaSum.resize(_numberOfJoints);

	K.resize(_numberOfJoints, _numberOfJoints);
	F.resize(_numberOfJoints, _numberOfJoints);
	I.resize(_numberOfJoints, _numberOfJoints);

	time = 0.0;

	ResetVariables();
}

JointSpacePassivityBasedControl::~JointSpacePassivityBasedControl()
{

}

int JointSpacePassivityBasedControl::SetGain(Eigen::VectorXd &K0, Eigen::VectorXd &K1, Eigen::VectorXd &K2, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd)
{
	if(((size_t)K0.size() != _numberOfJoints) || ((size_t)K1.size() != _numberOfJoints) || ((size_t)K2.size() != _numberOfJoints) || ((size_t)Ki.size() != _numberOfJoints) || ((size_t)Kd.size() != _numberOfJoints)) {
		return -1;
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		this->K0(i, i) = K0(i);
		this->K1(i, i) = K1(i);
		this->K2(i, i) = K2(i);
		this->Ki(i, i) = Ki(i);
		this->Kd(i, i) = Kd(i);
	}

	sigmaSum.setZero();

	return 0;
}

int JointSpacePassivityBasedControl::GetGain(Eigen::VectorXd &K0, Eigen::VectorXd &K1, Eigen::VectorXd &K2, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd)
{
	if((size_t)K0.size() != _numberOfJoints) {
		K0.resize(_numberOfJoints);
	}
	if((size_t)K1.size() != _numberOfJoints) {
			K1.resize(_numberOfJoints);
		}
	if((size_t)K2.size() != _numberOfJoints) {
			K2.resize(_numberOfJoints);
		}
	if((size_t)Ki.size() != _numberOfJoints) {
			Ki.resize(_numberOfJoints);
		}
	if((size_t)Kd.size() != _numberOfJoints) {
		Kd.resize(_numberOfJoints);
	}

	for(size_t i = 0; i < _numberOfJoints; i++) {
		K0(i) = this->K0(i, i);
		K1(i) = this->K1(i, i);
		K2(i) = this->K2(i, i);
		Ki(i) = this->Ki(i, i);
		Kd(i) = this->Kd(i, i);
	}

	return 0;
}

int JointSpacePassivityBasedControl::ResetVariables(void)
{
	ResetJointInfo();

	zetadot.setZero();
	zetadotPrev.setZero();
	zeta2dot.setZero();

	sigma.setZero();
	sigmaSum.setZero();

	K.setZero();
	F.setZero();
	I.setIdentity();

	return 0;
}

int JointSpacePassivityBasedControl::Solve(Eigen::VectorXd &torque)
{
	if(SolveInertia(q) < 0)			return -1;
	if(SolveCoriolis(q, qdot) < 0)	return -1;
	if(SolveGravity(q) < 0)			return -1;

	if((size_t)torque.size() != _numberOfJoints) {
		torque.resize(_numberOfJoints);
	}

	K = K0 + K1*time + K2*(time*time);
	F = (I*time + K).inverse();

	zetadot = dqdot - K*(q - dq);
	zeta2dot = (zetadot - zetadotPrev)/_period;
	zetadotPrev = zetadot;

	sigma = (F.inverse()) * (q - dq);
	sigmaSum += sigma*_period;

	torque = H*zeta2dot - Kd*sigma - Ki*sigmaSum + C + G;

	return 0;
}
