#pragma once

#include <chaindynparam.hpp>
#include "ManipulatorControl.h"

class DynamicsControl : public ManipulatorControl
{
public:
	DynamicsControl(KDL::Chain, double period = 0.001);
	virtual ~DynamicsControl(void);

protected:
	KDL::ChainDynParam _dynParam;

	KDL::JntSpaceInertiaMatrix H_KDL;
	KDL::JntArray C_KDL;
	KDL::JntArray G_KDL;

	Eigen::MatrixXd H;
	Eigen::VectorXd C;
	Eigen::VectorXd G;

	int SolveInertia(Eigen::VectorXd &actualJntPos);
	int SolveCoriolis(Eigen::VectorXd &actualJntVel, Eigen::VectorXd &actualJntPos);
	int SolveGravity(Eigen::VectorXd &actualJntPos);

	virtual int Solve(Eigen::VectorXd &torque);
};
