#pragma once

#include "JointSpaceControl.h"

class JointSpacePassivityBasedControl : public JointSpaceControl
{
public:
	JointSpacePassivityBasedControl(KDL::Chain chain, double period = 0.001);
	virtual ~JointSpacePassivityBasedControl(void);

private:
	Eigen::MatrixXd K0;
	Eigen::MatrixXd K1;
	Eigen::MatrixXd K2;
	Eigen::MatrixXd Ki;
	Eigen::MatrixXd Kd;

	Eigen::VectorXd zetadot;
	Eigen::VectorXd zetadotPrev;
	Eigen::VectorXd zeta2dot;

	Eigen::VectorXd sigma;
	Eigen::VectorXd sigmaSum;

	Eigen::MatrixXd K;
	Eigen::MatrixXd F;
	Eigen::MatrixXd I;

	double time;

public:
	int SetGain(Eigen::VectorXd &K0, Eigen::VectorXd &K1, Eigen::VectorXd &K2, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd);
	int GetGain(Eigen::VectorXd &K0, Eigen::VectorXd &K1, Eigen::VectorXd &K2, Eigen::VectorXd &Ki, Eigen::VectorXd &Kd);
	int ResetVariables(void);

	int Solve(Eigen::VectorXd &torque);
};
