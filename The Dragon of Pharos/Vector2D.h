/************************** Vector2D *************************
2D vector coordinate system
--------------------------------------------------------------

**************************************************************/

#pragma once

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


private:
	float mX;
	float mY;
};