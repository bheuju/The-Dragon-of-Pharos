#pragma once
#include <iostream>
#include <cmath>
#include "Object.h"
#include "Vector3D.h"
class IlluminationHandler
{
public:
	static IlluminationHandler* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new IlluminationHandler();
		}
		return pInstance;
	}
	~IlluminationHandler(){}

	void defineLightSource(Vector3D ls);

	Vector3D lightSource;

	float Iamb, Idiff, Ispec;
	float Kd, Ks;
	float If,Is;
	Vector3D iN, iL;

	//Calculate intensity
	//iN : vertex normal
	//iL : vector from point to light source
	float calcIntensity(Vector3D iN, Vector3D iL, Vector3D V);

private:
	IlluminationHandler();

	static IlluminationHandler *pInstance;
};

