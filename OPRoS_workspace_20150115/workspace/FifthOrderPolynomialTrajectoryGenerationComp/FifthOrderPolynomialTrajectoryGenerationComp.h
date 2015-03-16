
#ifndef _FifthOrderPolynomialTrajectoryGenerationComp_COMPONENT_H
#define _FifthOrderPolynomialTrajectoryGenerationComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include "TrajectoryGenerationServiceProvided.h"

class FifthOrderPolynomialTrajectoryGenerationComp: public Component, public ITrajectoryGenerationService
{
protected:
	//	Service Port
	ITrajectoryGenerationService *ptrTrajectoryGenerationService;

	OPRoS::Property _props;
	ReturnType _errorCode;

	vector< valarray<float64_t> > _acceleration;
	vector< valarray<float64_t> > _velocity;
	vector< valarray<float64_t> > _position;

public:
	virtual ReturnType SetProperty(OPRoS::Property props);
	virtual OPRoS::Property GetProperty();
	virtual ReturnType GetError();
	virtual ReturnType GenerateTrajectory(vector< valarray<float64_t> > path,float64_t deltaTime);
	virtual vector < valarray<float64_t> > GetAcceleration();
	virtual vector < valarray<float64_t> > GetVelocity();
	virtual vector < valarray<float64_t> > GetPosition();

public:
	FifthOrderPolynomialTrajectoryGenerationComp();
	FifthOrderPolynomialTrajectoryGenerationComp(const std::string &compId);
	virtual ~FifthOrderPolynomialTrajectoryGenerationComp();
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

