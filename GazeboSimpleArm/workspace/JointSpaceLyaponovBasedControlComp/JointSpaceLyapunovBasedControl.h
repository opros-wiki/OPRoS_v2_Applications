#pragma once

#include "JointSpaceControl.h"

class JointSpaceLyapunovBasedControl : public JointSpaceControl
{
public:
	JointSpaceLyapunovBasedControl(KDL::Chain chain, double period = 0.001);
	virtual ~JointSpaceLyapunovBasedControl(void);

private:
	Eigen::MatrixXd Lambda;
	Eigen::MatrixXd Ki;
	Eigen::MatrixXd Kd;

	Eigen::VectorXd zetadot;
	Eigen::VectorXd zetadotPrev;
	Eigen::VectorXd zeta2dot;
	Eigen::VectorXd sigma;
	Eigen::VectorXd sigmaSum;

public:
	int SetGain(Eigen::VectorXd &Lambda, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd);
	int GetGain(Eigen::VectorXd &Lambda, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd);
	int ResetVariables(void);

	int Solve(Eigen::VectorXd &torque);
};
