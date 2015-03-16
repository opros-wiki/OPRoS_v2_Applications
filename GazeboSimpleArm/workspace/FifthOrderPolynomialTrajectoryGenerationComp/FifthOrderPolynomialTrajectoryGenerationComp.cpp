/*************************************************************

 file: FifthOrderPolynomialTrajectoryGenerationComp.cpp
 author: E.C. Shin
 begin: January 31 2011
 copyright: (c) 2011 KITECH, OPRoS
 email: unchol@kitech.re.kr

***************************************************************

OPRoS source code is provided under a dual license mode:
 LGPL and OPRoS individually.

LGPL: You can redistribute it and/or modify it under the terms
 of the Less GNU General Public License as published by the Free
 Software Foundation, either version 3 of the License.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 Less GNU General Public License for more details.

 You should have received a copy of the Less GNU General Public
 License along with this program. If not, see
 <http://www.gnu.org/licenses/>.

OPRoS individual license: An individual license is a license for
 modifying the source code of OPRoS and distiributing it in a
 closed format for commercial purposes.

 If you are interested in this option, please see
 <http://www.opros.or.kr>.

This license policy may be changed without prior notice.

***************************************************************/

/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */
#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <OPRoSTypes.h>
#include <EventData.h>
#include <ServiceUtils.h>

#include "FifthOrderPolynomialTrajectoryGenerationComp.h"
#include "OprosPrintMessage.h"

//
// constructor declaration
//
FifthOrderPolynomialTrajectoryGenerationComp::FifthOrderPolynomialTrajectoryGenerationComp()
{
	_errorCode = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
FifthOrderPolynomialTrajectoryGenerationComp::FifthOrderPolynomialTrajectoryGenerationComp(const std::string &name):Component(name)
{
	_errorCode = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

FifthOrderPolynomialTrajectoryGenerationComp::~FifthOrderPolynomialTrajectoryGenerationComp()
{

}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::SetProperty(OPRoS::Property props)
{
	_props = props;

	return OPROS_SUCCESS;
}

OPRoS::Property FifthOrderPolynomialTrajectoryGenerationComp::GetProperty()
{
	return _props;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::GetError()
{
	return _errorCode;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::GenerateTrajectory(vector< valarray<float64_t> > path,float64_t deltaTime)
{
	vector< valarray<float64_t> > a(6);

	_acceleration.clear();
	_velocity.clear();
	_position.clear();

	if(path.size() < 2) {
		return OPROS_BAD_INPUT_PARAMETER;
	}

	for(size_t i = 1; i < path.size(); i++) {
		if(path[i - 1].size() != path[i].size()) {
			return OPROS_BAD_INPUT_PARAMETER;
		}
	}

	for(size_t i = 0; i < path.size() - 1; i++) {
		if(path[i + 1][0] - path[i][0] <= 0) {
			return OPROS_BAD_INPUT_PARAMETER;
		}
	}

	for(size_t i = 0; i < a.size(); i++) {
		a[i].resize(path[0].size() - 1);
	}

	for(size_t i = 0; i < path.size() - 1; i++) {
		int size = (int)((path[i + 1][0] - path[i][0]) / deltaTime);

		a[0] = path[i];
		a[1] = 0.0;
		a[2] = 0.0;
		a[3] = (20.0*path[i + 1] - 20.0*path[i]) / (2.0*pow(path[i + 1][0] - path[i][0], 3));
		a[4] = (30.0*path[i] - 30.0*path[i + 1]) / (2.0*pow(path[i + 1][0] - path[i][0], 4));
		a[5] = (12.0*path[i + 1] - 12.0*path[i]) / (2.0*pow(path[i + 1][0] - path[i][0], 5));

		for(int j = 1; j <= size; j++) {
			float64_t t = deltaTime * (float64_t)j;

			_position.push_back((a[0]) + (a[1] * t) + (a[2] * pow(t, 2)) + (a[3] * pow(t, 3)) + (a[4] * pow(t, 4)) + (a[5] * pow(t, 5)));
			_velocity.push_back((a[1]) + 2.0*(a[2] * t) + 3.0*(a[3] * pow(t, 2)) + 4.0*(a[4] * pow(t, 3)) + 5.0*(a[5] * pow(t, 4)));
			_acceleration.push_back(2.0*(a[2]) + 6.0*(a[3] * t) + 12.0*(a[4] * pow(t, 2)) + 20.0*(a[5] * pow(t, 3)));
		}
	}

	return OPROS_SUCCESS;
}

vector < valarray<float64_t> > FifthOrderPolynomialTrajectoryGenerationComp::GetAcceleration()
{
	return _acceleration;
}

vector < valarray<float64_t> > FifthOrderPolynomialTrajectoryGenerationComp::GetVelocity()
{
	return _velocity;
}

vector < valarray<float64_t> > FifthOrderPolynomialTrajectoryGenerationComp::GetPosition()
{
	return _position;
}

void FifthOrderPolynomialTrajectoryGenerationComp::portSetup()
{
	ProvidedServicePort *pa1;
	pa1=new TrajectoryGenerationServiceProvided(this);
	addPort("TrajectoryGenerationService",pa1);
}

// Call back Declaration
ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onInitialize()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onInitialize().\n");

	OPRoS::Property props;
	std::map<std::string, std::string> temp = getPropertyMap();
	props.SetProperty(temp);

	return SetProperty(props);
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onStart()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onStart().\n");
	return OPROS_SUCCESS;
}
	
ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onStop()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onStop().\n");
	return OPROS_SUCCESS;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onReset()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onReset().\n");
	return OPROS_SUCCESS;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onError()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onError().\n");
	return OPROS_SUCCESS;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onRecover()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onRecover().\n");
	return OPROS_SUCCESS;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onDestroy()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onDestroy().\n");
	return OPROS_SUCCESS;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onEvent(Event *evt)
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onEvent().\n");
	return OPROS_SUCCESS;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onExecute()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onExecute().\n");
	return OPROS_SUCCESS;
}
	
ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onUpdated()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onUpdated().\n");
	return OPROS_SUCCESS;
}

ReturnType FifthOrderPolynomialTrajectoryGenerationComp::onPeriodChanged()
{
	PrintMessage("INFO : FifthOrderPolynomialTrajectoryGenerationComp::onPeriodChanged().\n");
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
	return new FifthOrderPolynomialTrajectoryGenerationComp();
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
	return new FifthOrderPolynomialTrajectoryGenerationComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif
