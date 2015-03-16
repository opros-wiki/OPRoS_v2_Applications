

#ifndef _PrintService_PROVIDED_PORT_H
#define _PrintService_PROVIDED_PORT_H

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
		

#ifndef _IPrintService_CLASS_DEF
#define _IPrintService_CLASS_DEF
/*
 * IPrintService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IPrintService
{
 public:
    virtual void PrintStr(std::string msg)=0;
 };
#endif

/*
 * 
 * PrintService : public ProvidedServicePort
 *
 */
class PrintServiceProvided
	:public ProvidedServicePort, public IPrintService
{
protected:
    IPrintService *pcom;


   typedef ProvidedMethod<void> PrintStrFuncType;
   PrintStrFuncType *PrintStrFunc;


public: // default method
   virtual void PrintStr(std::string msg)
   {
		opros_assert(PrintStrFunc != NULL);
		(*PrintStrFunc)(msg);
   }


public:
    //
    // Constructor
    //
    PrintServiceProvided(IPrintService *fn)
    {
        pcom = fn;

        PrintStrFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IPrintService::PrintStr,pcom,"PrintStr");

        opros_assert(ptr_method != NULL);
        addMethod("PrintStr",ptr_method);
        PrintStrFunc = reinterpret_cast<PrintStrFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
