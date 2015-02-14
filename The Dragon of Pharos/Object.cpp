#include "Object.h"

/* Objects */
Object::Object()
{
	tX = tY = tZ = 0;
	angleX = angleY = angleZ = 0;
	sX = sY = sZ = 1;

	shown  = true;
}

Object::Object(std::string objectName)
{
	name = objectName;

	tX = tY = tZ = 0;
	angleX = angleY = angleZ = 0;
	sX = sY = sZ = 1;

	shown  = true;
}

Object Object::setTranslation(float x, float y, float z)
{
	tX = x;
	tY = y;
	tZ = z;
	return *this;
}
Object Object::setRotation(float x, float y, float z)
{
	angleX = x;
	angleY = y;
	angleZ = z;
	return *this;
}
Object Object::setScale(float x, float y, float z)
{
	sX = x;
	sY = y;
	sZ = z;
	return *this;
}


/* Faces */
Face::Face() : v0(0), v1(0), v2(0), v3(0)
{

}

Face::Face(int a, int b, int c)
{
	v0 = a;
	v1 = b;
	v2 = c;
	//v3 = d;
}


