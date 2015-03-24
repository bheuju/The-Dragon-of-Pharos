#include "IlluminationHandler.h"
#include<cmath>
IlluminationHandler* IlluminationHandler::pInstance = 0;

IlluminationHandler::IlluminationHandler()
{
	lightSource = Vector3D(500, 500, 500);
	Iamb = 0.2;
	//If = Xf;
	//Kd = Xd;
	//Ks = Xs;
	If = 0.4;
	Is = 1;
	Kd = 0.1;
	Ks = 0.6;
}

IlluminationHandler::IlluminationHandler(float Xf, float Xd, float Xs) : lightSource(Vector3D(1000, 1000, 1000))
{
	Iamb = 0.4;
	//If = Xf;
	//Kd = Xd;
	//Ks = Xs;
	If = 0.4;
	Kd = 0.5;
	Ks = 0.3;
	

}

void IlluminationHandler::defineLightSource(Vector3D ls)
{
	lightSource = ls;
}

float IlluminationHandler::calcIntensity(Vector3D iN, Vector3D iL)
{
	Vector3D vSum = iL + iN;
	Vector3D iH = normalize(vSum);
	//displayVector3D(iH);
	//std::cout<<"DOT"<<dot(iN, iL)<<std::endl;
	Ispec = Iamb + Kd*If*(dot(iN,iL)) + Is*Ks*pow(dot(iN,iH),4) ;
	return Ispec;
}