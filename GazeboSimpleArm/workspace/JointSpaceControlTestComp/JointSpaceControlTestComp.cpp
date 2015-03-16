
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>
#include "JointSpaceControlTestComp.h"
#include "OprosPrintMessage.h"

//
// constructor declaration
//
JointSpaceControlTestComp::JointSpaceControlTestComp()
{
	ptrJointSpaceControlCoordinatorService = NULL;

	portSetup();
}

//
// constructor declaration (with name)
//
JointSpaceControlTestComp::JointSpaceControlTestComp(const std::string &name):Component(name)
{
	ptrJointSpaceControlCoordinatorService = NULL;

	portSetup();
}

//
// destructor declaration
//

JointSpaceControlTestComp::~JointSpaceControlTestComp()
{
}

void JointSpaceControlTestComp::portSetup()
{
	ptrJointSpaceControlCoordinatorService=new JointSpaceControlCoorinatorServiceRequired();
	addPort("JointSpaceControlCoordinatorService",ptrJointSpaceControlCoordinatorService);
}

// Call back Declaration
ReturnType JointSpaceControlTestComp::onInitialize()
{
	PrintMessage("INFO : JointSpaceControlTestComp::onInitialize().\n");
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlTestComp::onStart()
{
	PrintMessage("INFO : JointSpaceControlTestComp::onStart().\n");
	return OPROS_SUCCESS;
}
	
ReturnType JointSpaceControlTestComp::onStop()
{
	PrintMessage("INFO : JointSpaceControlTestComp::onStop().\n");
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlTestComp::onReset()
{
	PrintMessage("INFO : JointSpaceControlTestComp::onReset().\n");
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlTestComp::onError()
{
	PrintMessage("INFO : JointSpaceControlTestComp::onError().\n");
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlTestComp::onRecover()
{
	PrintMessage("INFO : JointSpaceControlTestComp::onRecover().\n");
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlTestComp::onDestroy()
{
	PrintMessage("INFO : JointSpaceControlTestComp::onDestroy().\n");
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlTestComp::onEvent(Event *evt)
{
	PrintMessage("INFO : JointSpaceControlTestComp::onEvent().\n");
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlTestComp::onExecute()
{
	static int nIndex = 0;

	if(nIndex++ == 2) {	//	2sec
		PrintMessage("INFO : JointSpaceControlTestComp::onExecute() -> Send the desired position.\n");

		OPRoS::Float64Array  desiredPosition;
		desiredPosition.data.push_back(10.0);
		desiredPosition.data.push_back(10.0);
		desiredPosition.data.push_back(-35.0);
		desiredPosition.data.push_back(10.0);

		ptrJointSpaceControlCoordinatorService->SetDesiredJointPosition(desiredPosition, 1.0);
	}
	else if(nIndex++ == 6) {	//	4sec
		PrintMessage("INFO : JointSpaceControlTestComp::onExecute() -> Send the desired position.\n");

		OPRoS::Float64Array  desiredPosition;
		desiredPosition.data.push_back(0.0);
		desiredPosition.data.push_back(0.0);
		desiredPosition.data.push_back(-45.0);
		desiredPosition.data.push_back(0.0);

		ptrJointSpaceControlCoordinatorService->SetDesiredJointPosition(desiredPosition, 1.0);
	}

	return OPROS_SUCCESS;
}
	
ReturnType JointSpaceControlTestComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType JointSpaceControlTestComp::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}

#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new JointSpaceControlTestComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new JointSpaceControlTestComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

