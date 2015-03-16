#pragma once

#undef min
#undef	max

#include <Eigen/Core>
#include <Eigen/LU>

#include <chain.hpp>

class ManipulatorControl
{
public:
	ManipulatorControl(KDL::Chain chain, double period = 0.001);
	virtual ~ManipulatorControl(void);

protected:
	KDL::Chain _chain;
	size_t _numberOfJoints;
	double _period;

public:
	KDL::Chain GetChain(void);
	size_t GetNumberOfJoints(void);
	double GetPeriod(void);
	virtual int ResetVariables(void);
};
