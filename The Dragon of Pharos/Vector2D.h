/************************** Vector2D *************************
2D vector coordinate system
--------------------------------------------------------------

**************************************************************/

#pragma once
#include <iostream>
#include <string>

class Vector2D
{
public:
	Vector2D() : mX(0.0), mY(0.0)
	{}

	Vector2D(float x, float y)
	{
		mX = x;
		mY = y;
	}

	float getX() {return mX;}
	float getY() {return mY;}

	void setX(float x) {mX = x;}
	void setY(float y) {mY = y;}

	friend void displayVector2D(Vector2D& v, std::string name = "")
	{
		std::cout.precision(3);

		std::cout<<"================="<<std::endl;
		std::cout<<"\t"<<name<<std::endl;
		std::cout<<"-----------------"<<std::endl;
		std::cout<<v.mX<<"\t"<<v.mY<<std::endl;
		std::cout<<"================="<<std::endl;
	}

private:
	float mX;
	float mY;
};