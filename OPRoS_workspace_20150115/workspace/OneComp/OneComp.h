
#ifndef _OneComp_COMPONENT_H
#define _OneComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>



#include "PrintServiceRequired.h"


#include "PersonData.h"

class OneComp: public Component
{
protected:
// monitor variables
	int m_count;

protected:
// event
	OutputEventPort<std::string, EVENT_OPROS> strEventOut;

protected:
//data
	OutputDataPort< PersonData > personDataOut;

protected:
//data
	OutputDataPort< int > intDataOut;

protected:
// service
// method for required
	PrintServiceRequired *ptrPrintService;

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	OneComp();
	OneComp(const std::string &compId);
	virtual ~OneComp();
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

