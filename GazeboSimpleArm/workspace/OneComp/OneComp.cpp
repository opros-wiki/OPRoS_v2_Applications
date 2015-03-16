
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "OneComp.h"

//
// constructor declaration
//
OneComp::OneComp()
{
	ptrPrintService = NULL;
	
	portSetup();
}

//
// constructor declaration (with name)
//
OneComp::OneComp(const std::string &name):Component(name)
{
	ptrPrintService = NULL;


	
	portSetup();
}

//
// destructor declaration
//

OneComp::~OneComp() {
}

void OneComp::portSetup() {
	// export variable setup
	EXPORT_VARIABLE("count", m_count);

	//event port setup
	addPort("strEventOut", &strEventOut);

	//data port setup
	addPort("personDataOut", &personDataOut);

	//data port setup
	addPort("intDataOut", &intDataOut);

	ptrPrintService=new PrintServiceRequired();
	addPort("PrintService",ptrPrintService);
}

// Call back Declaration
ReturnType OneComp::onInitialize()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType OneComp::onStart()
{
	// user code here
	m_count = 0;

	return OPROS_SUCCESS;
}
	
ReturnType OneComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType OneComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType OneComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType OneComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType OneComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType OneComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType OneComp::onExecute()
{
	// user code here
	static int index = 0;
	std::cout << "One Component : " << index++ << std::endl;

	std::string msg = getProperty("Msg");
	ptrPrintService->PrintStr(msg);

	PersonData human;
	human.setAge(m_count++);
	human.setName(msg);

	personDataOut.push(human);

	strEventOut.push(msg);

	return OPROS_SUCCESS;
}

ReturnType OneComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType OneComp::onPeriodChanged()
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
	return new OneComp();
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
	return new OneComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

