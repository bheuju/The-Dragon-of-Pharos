/************************** Vector3D *************************
3D vector coordinate system
--------------------------------------------------------------

**************************************************************/

#pragma once

class Vector3D
{
public:
	Vector3D() : mX(0.0), mY(0.0), mZ(0.0)
	{}

	Vector3D(float x, float y, float z)
	{
		mX = x;
		mY = y;
		mZ = z;
	}

	float getX() {return mX;}
	float getY() {return mY;}
	float getZ() {return mZ;}

	void setX(float x) {mX = x;}
	void setY(float y) {mY = y;}
	void setZ(float z) {mZ = z;}


private:
	float mX;
	float mY;
	float mZ;
};