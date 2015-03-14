/************************** Vector3D *************************
3D vector coordinate system
--------------------------------------------------------------

**************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Vector3D
{
public:
	Vector3D() : mX(0.0), mY(0.0), mZ(0.0)
	{}

	//Vector3D(Vector4D v)
	//{
	//	mX = v.getX();
	//	mY = v.getY();
	//	mZ = v.getZ();
	//}

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

	//calculate length of vector
	float length() {return sqrt(mX*mX + mY*mY + mZ*mZ);}
	friend Vector3D normalize(Vector3D& v)
	{
		float len = v.length();
		if (len != 0)
		{
			return Vector3D(v.mX/len, v.mY/len, v.mZ/len);
		}
		return v;
	}

	Vector3D operator-(Vector3D& v2)
	{
		return Vector3D(mX - v2.mX, mY - v2.mY, mZ - v2.mZ);
	}

	Vector3D operator+(Vector3D& v2)
	{
		return Vector3D(mX + v2.mX, mY + v2.mY, mZ + v2.mZ);
	}

	Vector3D operator/(int n)
	{
		return Vector3D(mX / n, mY / n, mZ / n);
	}

	friend float dot(Vector3D& v1, Vector3D& v2)
	{
		return ((v1.mX * v2.mX) + (v1.mY * v2.mY) + (v1.mZ *v2.mZ));
	}

	friend Vector3D cross(Vector3D& v1, Vector3D& v2)
	{
		Vector3D v;
		v.mX = (v1.mY * v2.mZ) - (v2.mY * v1.mZ);
		v.mY = -(v1.mX * v2.mZ) + (v2.mX * v1.mZ);
		v.mZ = (v1.mX * v2.mY) - (v2.mX * v1.mY);
		return v;
	}

	friend void displayVector3D(Vector3D& v, std::string name = "", int mode  = 0)
	{
		//mode 0 - column major
		//mode 1 - row major
		std::cout.precision(5);
		if (mode == 0)
		{
			std::cout<<"===="<<std::endl;
			std::cout<<name<<std::endl;
			std::cout<<"----"<<std::endl;
			std::cout<<v.mX<<"\n"<<v.mY<<"\n"<<v.mZ<<std::endl;
			std::cout<<"===="<<std::endl;
		}
		else
		{
			std::cout<<"=============================="<<std::endl;
			std::cout<<"\t"<<name<<std::endl;
			std::cout<<"------------------------------"<<std::endl;
			std::cout<<v.mX<<"\t"<<v.mY<<"\t"<<v.mZ<<std::endl;
			std::cout<<"=============================="<<std::endl;
		}
	}

private:
	float mX;
	float mY;
	float mZ;
};