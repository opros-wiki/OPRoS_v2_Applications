#include "JointSpaceControl.h"

JointSpaceControl::JointSpaceControl(KDL::Chain chain, double period)
: DynamicsControl(chain, period)
{
	q.resize(_numberOfJoints);
	qdot.resize(_numberOfJoints);
	q2dot.resize(_numberOfJoints);
	dq.resize(_numberOfJoints);
	dqdot.resize(_numberOfJoints);
	dq2dot.resize(_numberOfJoints);
}

JointSpaceControl::~JointSpaceControl()
{

}

void JointSpaceControl::ResetJointInfo(void)
{
	q.setZero();
	qdot.setZero();
	q2dot.setZero();
	dq.setZero();
	dqdot.setZero();
	dq2dot.setZero();
}

int JointSpaceControl::SetActualJntAcc(Eigen::VectorXd &actualJntAcc)
{
	if(actualJntAcc.size() != _numberOfJoints) {
		return -1;
	}

	q2dot = actualJntAcc;

	return 0;
}

int JointSpaceControl::SetActualJntVel(Eigen::VectorXd &actualJntVel)
{
	if(actualJntVel.size() != _numberOfJoints) {
		return -1;
	}

	qdot = actualJntVel;

	return 0;
}

int JointSpaceControl::SetActualJntPos(Eigen::VectorXd &actualJntPos)
{
	if(actualJntPos.size() != _numberOfJoints) {
		return -1;
	}

	q = actualJntPos;

	return 0;
}

int JointSpaceControl::SetActualJntInfo(Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos)
{
	if((actualJntVel.size() != _numberOfJoints) || (actualJntPos.size() != _numberOfJoints)) {
		return -1;
	}

	qdot = actualJntVel;
	q = actualJntPos;

	return 0;
}

int JointSpaceControl::SetActualJntInfo(Eigen::VectorXd &actualJntAcc, Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos)
{
	if((actualJntAcc.size() != _numberOfJoints) || (actualJntVel.size() != _numberOfJoints) || (actualJntPos.size() != _numberOfJoints)) {
		return -1;
	}

	q2dot = actualJntAcc;
	qdot = actualJntVel;
	q = actualJntPos;

	return 0;
}

int JointSpaceControl::GetActualJntAcc(Eigen::VectorXd &actualJntAcc)
{
	actualJntAcc = q2dot;

	return 0;
}

int JointSpaceControl::GetActualJntVel(Eigen::VectorXd &actualJntVel)
{
	actualJntVel = qdot;

	return 0;
}

int JointSpaceControl::GetActualJntPos(Eigen::VectorXd &actualJntPos)
{
	actualJntPos = q;

	return 0;
}

int JointSpaceControl::GetActualJntInfo(Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos)
{
	actualJntVel = qdot;
	actualJntPos = q;

	return 0;
}

int JointSpaceControl::GetActualJntInfo(Eigen::VectorXd &actualJntAcc, Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos)
{
	actualJntAcc = q2dot;
	actualJntVel = qdot;
	actualJntPos = q;

	return 0;
}

int JointSpaceControl::SetDesiredJntAcc(Eigen::VectorXd &desiredJntAcc)
{
	if(desiredJntAcc.size() != _numberOfJoints) {
		return -1;
	}

	dq2dot = desiredJntAcc;

	return 0;
}

int JointSpaceControl::SetDesiredJntVel(Eigen::VectorXd &desiredJntVel)
{
	if(desiredJntVel.size() != _numberOfJoints) {
		return -1;
	}

	dqdot = desiredJntVel;

	return 0;
}

int JointSpaceControl::SetDesiredJntPos(Eigen::VectorXd &desiredJntPos)
{
	if(desiredJntPos.size() != _numberOfJoints) {
		return -1;
	}

	dq = desiredJntPos;

	return 0;
}

int JointSpaceControl::SetDesiredJntInfo(Eigen::VectorXd &desiredJntVel, Eigen::VectorXd &desiredJntPos)
{
	if((desiredJntVel.size() != _numberOfJoints) || (desiredJntPos.size() != _numberOfJoints)) {
		return -1;
	}

	dqdot = desiredJntVel;
	dq = desiredJntPos;

	return 0;
}

int JointSpaceControl::SetDesiredJntInfo(Eigen::VectorXd &desiredJntAcc, Eigen::VectorXd &desiredJntVel, Eigen::VectorXd &desiredJntPos)
{
	if((desiredJntAcc.size() != _numberOfJoints) || (desiredJntVel.size() != _numberOfJoints) || (desiredJntPos.size() != _numberOfJoints)) {
		return -1;
	}

	dq2dot = desiredJntAcc;
	dqdot = desiredJntVel;
	dq = desiredJntPos;

	return 0;
}

int JointSpaceControl::GetDesiredJntAcc(Eigen::VectorXd &desiredJntAcc)
{
	desiredJntAcc = dq2dot;

	return 0;
}

int JointSpaceControl::GetDesiredJntVel(Eigen::VectorXd &desiredJntVel)
{
	desiredJntVel = dqdot;

	return 0;
}

int JointSpaceControl::GetDesiredJntPos(Eigen::VectorXd &desiredJntPos)
{
	desiredJntPos = dq;

	return 0;
}

int JointSpaceControl::GetDesiredJntInfo(Eigen::VectorXd &desiredJntVel, Eigen::VectorXd &desiredJntPos)
{
	desiredJntVel = dqdot;
	desiredJntPos = dq;

	return 0;
}

int JointSpaceControl::GetDesiredJntInfo(Eigen::VectorXd &desiredJntAcc, Eigen::VectorXd &desiredJntVel, Eigen::VectorXd &desiredJntPos)
{
	desiredJntAcc = dq2dot;
	desiredJntVel = dqdot;
	desiredJntPos = dq;

	return 0;
}


