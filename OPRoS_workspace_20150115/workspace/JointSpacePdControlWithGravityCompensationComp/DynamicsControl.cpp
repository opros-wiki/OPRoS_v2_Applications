#include "DynamicsControl.h"

DynamicsControl::DynamicsControl(KDL::Chain chain, double period)
: ManipulatorControl(chain, period), _dynParam(chain, KDL::Vector(0.0, 0.0, -9.81))
{
	H_KDL.resize(_numberOfJoints);
	C_KDL.resize(_numberOfJoints);
	G_KDL.resize(_numberOfJoints);

	H.resize(_numberOfJoints, _numberOfJoints);
	C.resize(_numberOfJoints);
	G.resize(_numberOfJoints);
}

DynamicsControl::~DynamicsControl(void)
{

}

int DynamicsControl::SolveInertia(Eigen::VectorXd &actualJntPos)
{
	if(actualJntPos.size() != (int)_numberOfJoints) {
		return -1;
	}

	KDL::JntArray jntPos;

	jntPos.data = actualJntPos;
	_dynParam.JntToMass(jntPos, H_KDL);

	H = H_KDL.data;

	return 0;
}

int DynamicsControl::SolveCoriolis(Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos)
{
	if((actualJntVel.size() != (int)_numberOfJoints) || (actualJntPos.size() != (int)_numberOfJoints)) {
		return -1;
	}

	KDL::JntArray jntVel, jntPos;

	jntVel.data = actualJntVel;
	jntPos.data = actualJntPos;

	_dynParam.JntToCoriolis(jntPos, jntVel, C_KDL);

	memcpy(&C(0), &C_KDL(0), _numberOfJoints*sizeof(double));

	return 0;
}

int DynamicsControl::SolveGravity(Eigen::VectorXd &actualJntPos)
{
	if(actualJntPos.size() != (int)_numberOfJoints) {
		return -1;
	}

	KDL::JntArray jntPos;

	jntPos.data = actualJntPos;

	_dynParam.JntToGravity(jntPos, G_KDL);

	memcpy(&G(0), &G_KDL(0), _numberOfJoints*sizeof(double));

	return 0;
}

int DynamicsControl::Solve(Eigen::VectorXd &torque)
{
	return -1;
}
