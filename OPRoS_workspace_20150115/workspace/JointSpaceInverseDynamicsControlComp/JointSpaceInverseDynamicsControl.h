#pragma once

#include "JointSpaceControl.h"

class JointSpaceInverseDynamicsControl : public JointSpaceControl
{
public:
	JointSpaceInverseDynamicsControl(KDL::Chain chain, double period = 0.001);
	virtual ~JointSpaceInverseDynamicsControl(void);

private:
	Eigen::MatrixXd Kp;
	Eigen::MatrixXd Ki;
	Eigen::MatrixXd Kd;
	Eigen::VectorXd qErrSum;

public:
	int SetGain(Eigen::VectorXd &Kp, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd);
	int GetGain(Eigen::VectorXd &Kp, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd);
	int ResetVariables(void);

	int Solve(Eigen::VectorXd &torque);
};
