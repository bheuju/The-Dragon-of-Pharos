/************************** Vector4D *************************
4D vector coordinate system
- homogeneous 3D with w coordinates
--------------------------------------------------------------

**************************************************************/

#pragma once

class Vector4D
{
public:
	Vector4D() : mX(0.0), mY(0.0), mZ(0.0), mW(1.0)
	{}

	Vector4D(float x, float y, float z, float w = 1)
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


private:
	float mX;
	float mY;
	float mZ;
	float mW;
};