
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "TwoComp.h"

//
// constructor declaration
//
TwoComp::TwoComp()
	:intDataIn(OPROS_LAST,1)
	,personDataIn(OPROS_LAST,1)
{
	portSetup();
}

//
// constructor declaration (with name)
//
TwoComp::TwoComp(const std::string &name):Component(name)
	,intDataIn(OPROS_LAST,1)
	,personDataIn(OPROS_LAST,1)
{

	
	portSetup();
}

//
// destructor declaration
//

TwoComp::~TwoComp() {
}

void TwoComp::PrintStr(std::string msg)
{
	//user code hear
	std::cout << "TwoComp::PrintStr " << msg << std::endl;
}


void TwoComp::strEventInCallback(const std::string &indata)
{
	std::cout << "strEventInCallback : " << indata << std::endl;
}

void TwoComp::portSetup() {
//event port setup
	addPort("strEventIn", &strEventIn);

	strEventIn.setOwner(this);
	SET_EVENT_CALLBACK(strEventIn, TwoComp::strEventInCallback, this);

//data port setup
	addPort("personDataIn", &personDataIn);

//data port setup
	addPort("intDataIn", &intDataIn);

	ProvidedServicePort *pa1;
	pa1=new PrintServiceProvided(this);
	addPort("PrintService",pa1);




	// export variable setup


}

// Call back Declaration
ReturnType TwoComp::onInitialize()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType TwoComp::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType TwoComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType TwoComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType TwoComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType TwoComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType TwoComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType TwoComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType TwoComp::onExecute()
{
	// user code here
	static int index = 0;
	std::cout << "Two Component : " << index++ << std::endl;

	opros_any *pData = personDataIn.pop();
	if(pData != NULL) {
		PersonData human = personDataIn.getContent(*pData);
		std::cout << "Person Name : " << human.getName() << std::endl;
		std::cout << "Person Age : " << human.getAge() << std::endl;
		delete pData;
		pData = NULL;
	}

	return OPROS_SUCCESS;
}
	
ReturnType TwoComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType TwoComp::onPeriodChanged()
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
	return new TwoComp();
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
	return new TwoComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

