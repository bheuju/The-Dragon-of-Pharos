/************************** Vector4D *************************
4D vector coordinate system
- homogeneous 3D with w coordinates
--------------------------------------------------------------

**************************************************************/

#pragma once
#include <iostream>

class Vector4D
{
public:
	Vector4D() : mX(0.0), mY(0.0), mZ(0.0), mW(1.0)
	{}

	Vector4D(float x, float y, float z, float w = 1.0)
	{
		mX = x;
		mY = y;
		mZ = z;
		mW = w;
	}

	float getX() {return mX;}
	float getY() {return mY;}
	float getZ() {return mZ;}
	float getW() {return mW;}

	void setX(float x) {mX = x;}
	void setY(float y) {mY = y;}
	void setZ(float z) {mZ = z;}
	void setW(float w) {mW = w;}

	void normalizeW()
	{
		mX = mX / mW;
		mY = mY / mW;
		mZ = mZ / mW;
		mW = mW / mW;
	}

	friend void displayVector4D(Vector4D& v, int mode  = 0)
	{
		//mode 0 - column major
		//mode 1 - row major
		std::cout.precision(3);
		if (mode == 0)
		{
			std::cout<<"===="<<std::endl;
			std::cout<<v.mX<<"\n"<<v.mY<<"\n"<<v.mZ<<"\n"<<v.mW<<std::endl;
			std::cout<<"===="<<std::endl;
		}
		else
		{
			std::cout<<"==========================="<<std::endl;
			std::cout<<v.mX<<"\t"<<v.mY<<"\t"<<v.mZ<<"\t"<<v.mW<<std::endl;
			std::cout<<"==========================="<<std::endl;
		}
	}

private:
	float mX;
	float mY;
	float mZ;
	float mW;
};