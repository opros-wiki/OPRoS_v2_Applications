
#ifndef _JointSpaceControlTestComp_COMPONENT_H
#define _JointSpaceControlTestComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>
#include "JointSpaceControlCoorinatorServiceRequired.h"

class JointSpaceControlTestComp: public Component
{
protected:
	JointSpaceControlCoorinatorServiceRequired *ptrJointSpaceControlCoordinatorService;
	
public:
	JointSpaceControlTestComp();
	JointSpaceControlTestComp(const std::string &compId);
	virtual ~JointSpaceControlTestComp();
	virtual void portSetup();

protected:
	virtual ReturnType onInitialize();
	virtual ReturnType onStart();
	virtual ReturnType onStop();
	virtual ReturnType onReset();
	virtual ReturnType onError();
	virtual ReturnType onRecover();
	virtual ReturnType onDestroy();

public:
	virtual ReturnType onEvent(Event *evt);
	virtual ReturnType onExecute();
	virtual ReturnType onUpdated();
	virtual ReturnType onPeriodChanged();
};

#endif

