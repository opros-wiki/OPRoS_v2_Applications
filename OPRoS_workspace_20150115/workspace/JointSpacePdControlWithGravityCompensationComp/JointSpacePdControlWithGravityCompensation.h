#pragma once

#include "JointSpaceControl.h"

class JointSpacePdControlWithGravityCompensation : public JointSpaceControl
{
public:
	JointSpacePdControlWithGravityCompensation(KDL::Chain chain, double period = 0.001);
	virtual ~JointSpacePdControlWithGravityCompensation(void);

private:
	Eigen::MatrixXd Kp;
	Eigen::MatrixXd Kd;

public:
	int SetGain(Eigen::VectorXd &Kp, Eigen::VectorXd &Kd);
	int GetGain(Eigen::VectorXd &Kp, Eigen::VectorXd &Kd);
	int ResetVariables(void);

	int Solve(Eigen::VectorXd &torque);
};
