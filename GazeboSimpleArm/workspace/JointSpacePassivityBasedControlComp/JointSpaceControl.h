#pragma once

#include "DynamicsControl.h"

class JointSpaceControl : public DynamicsControl
{
public:
	JointSpaceControl(KDL::Chain chain, double period = 0.0001);
	virtual ~JointSpaceControl(void);

protected:
	Eigen::VectorXd q;		//	Actual Joint Position;
	Eigen::VectorXd qdot;	//	Actual Joint Velocity;
	Eigen::VectorXd q2dot;	//	Actual Joint Acceleration;
	Eigen::VectorXd dq;		//	Desired Joint Position;
	Eigen::VectorXd dqdot;	//	Desired JOint Velocity;
	Eigen::VectorXd dq2dot;	//	Desired Joint Acceleration;

	void ResetJointInfo(void);

public:
	int SetActualJntAcc(Eigen::VectorXd &actualJntAcc);
	int SetActualJntVel(Eigen::VectorXd &actualJntVel);
	int SetActualJntPos(Eigen::VectorXd &actualJntPos);
	int SetActualJntInfo(Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos);
	int SetActualJntInfo(Eigen::VectorXd &actualJntAcc, Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos);

	int GetActualJntAcc(Eigen::VectorXd &actualJntAcc);
	int GetActualJntVel(Eigen::VectorXd &actualJntVel);
	int GetActualJntPos(Eigen::VectorXd &actualJntPos);
	int GetActualJntInfo(Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos);
	int GetActualJntInfo(Eigen::VectorXd &actualJntAcc, Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos);

	int SetDesiredJntAcc(Eigen::VectorXd &desiredJntAcc);
	int SetDesiredJntVel(Eigen::VectorXd &desiredJntVel);
	int SetDesiredJntPos(Eigen::VectorXd &desiredJntPos);
	int SetDesiredJntInfo(Eigen::VectorXd &desiredJntVel, Eigen::VectorXd &desiredJntPos);
	int SetDesiredJntInfo(Eigen::VectorXd &desiredJntAcc, Eigen::VectorXd &desiredJntVel, Eigen::VectorXd &desiredJntPos);

	int GetDesiredJntAcc(Eigen::VectorXd &desiredJntAcc);
	int GetDesiredJntVel(Eigen::VectorXd &desiredJntVel);
	int GetDesiredJntPos(Eigen::VectorXd &desiredJntPos);
	int GetDesiredJntInfo(Eigen::VectorXd &desiredJntVel, Eigen::VectorXd &desiredJntPos);
	int GetDesiredJntInfo(Eigen::VectorXd &desiredJntAcc, Eigen::VectorXd &desiredJntVel, Eigen::VectorXd &desiredJntPos);
};
