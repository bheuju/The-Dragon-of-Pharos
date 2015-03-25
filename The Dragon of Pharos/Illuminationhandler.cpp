#include "IlluminationHandler.h"
#include <cmath>

IlluminationHandler* IlluminationHandler::pInstance = 0;

IlluminationHandler::IlluminationHandler()
{
	lightSource = Vector3D(0, 0, 500);

	Iamb = 0.4;

	Kd = 0.9;
	If = 0.6;
	
	Ks = 0.3;
	Is = 0.6;
}

void IlluminationHandler::defineLightSource(Vector3D ls)
{
	lightSource = ls;
}

float IlluminationHandler::calcIntensity(Vector3D iN, Vector3D iL, Vector3D V)
{
	Vector3D vSum = V + iL;
	//Vector3D vSum = iL + iN;
	Vector3D iH = normalize(vSum);
	Idiff = Kd*If*(dot(iN,iL));
	Ispec = Is*Ks*pow(dot(iN,iH),2);
	//Ispec = Iamb + Kd*If*(dot(iN,iL)) + Is*Ks*pow(dot(iN,iH),4);
	return (Iamb + Idiff + Ispec);
}