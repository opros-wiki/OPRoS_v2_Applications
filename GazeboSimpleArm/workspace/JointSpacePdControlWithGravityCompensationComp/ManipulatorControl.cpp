#include "ManipulatorControl.h"

ManipulatorControl::ManipulatorControl(KDL::Chain chain, double period)
: _chain(chain), _numberOfJoints(chain.getNrOfJoints()), _period(period)
{

}

ManipulatorControl::~ManipulatorControl(void)
{

}

KDL::Chain ManipulatorControl::GetChain(void)
{
	return _chain;
}

size_t ManipulatorControl::GetNumberOfJoints(void)
{
	return _numberOfJoints;
}

double ManipulatorControl::GetPeriod(void)
{
	return _period;
}

int ManipulatorControl::ResetVariables(void)
{
	return -1;
}
