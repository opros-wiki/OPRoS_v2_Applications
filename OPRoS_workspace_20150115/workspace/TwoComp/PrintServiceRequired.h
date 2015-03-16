

#ifndef _PrintService_REQUIRED_PORT_H
#define _PrintService_REQUIRED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>
#include <device/ApiTypes.h>


#include <string>
		



/*
 * 
 * PrintService : public RequiredServicePort
 *
 */
class PrintServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<void> PrintStrFuncType;
	PrintStrFuncType *PrintStrFunc;

public:
	//
	// Constructor
	//
	PrintServiceRequired()
	{
            PrintStrFunc = NULL;
            
	   setup();
	}

	// method implementation for required method
	void PrintStr(std::string msg)
	{
            opros_assert(PrintStrFunc != NULL);
	
            (*PrintStrFunc)(msg);
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&PrintServiceRequired::PrintStr,"PrintStr");
        opros_assert(ptr_method != NULL);
        addMethod("PrintStr",ptr_method);
        PrintStrFunc = reinterpret_cast<PrintStrFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
