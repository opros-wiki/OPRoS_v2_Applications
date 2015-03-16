
#ifndef _TwoComp_COMPONENT_H
#define _TwoComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>


#include "PersonData.h"

#include "PrintServiceProvided.h"

class TwoComp: public Component
	,public IPrintService
{
protected:
// service
// method for provider
	IPrintService *ptrPrintService;

protected:
//data
	InputDataPort< int > intDataIn;

protected:
//data
	InputDataPort< PersonData > personDataIn;

protected:
// event
	InputEventPort<std::string, EVENT_OPROS> strEventIn;

public:
virtual void PrintStr(std::string msg);

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	TwoComp();
	TwoComp(const std::string &compId);
	virtual ~TwoComp();
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


public:
	void strEventInCallback(const std::string &indata);

};

#endif

