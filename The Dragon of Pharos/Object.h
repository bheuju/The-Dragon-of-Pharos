/************************** Object **************************
Objects
- Defines objects with points
- Similar to opengl's glBegin() - glEnd()
--------------------------------------------------------------

**************************************************************/

#pragma once
#include "Vector4D.h"
#include <string>
#include <vector>
#include "Matrix4.h"

class Face;

class Object
{
public:
	Object();
	Object(std::string objectName);
	~Object() {}

	std::string name;
	std::vector<Vector4D*> vertex;
	std::vector<Face*> face;
	
	Object setTranslation(float x, float y, float z);
	Object setRotation(float x, float y, float z);
	Object setScale(float x, float y, float z);

	Matrix4 translation, rotation, scale;
	Matrix4 modelMatrix;

	float tX, tY, tZ;
	float sX, sY, sZ;
	float angleX, angleY, angleZ;

	bool shown;
};

class Face
{
public:
	Face();
	Face(int a, int b, int c);
	~Face() {}

	int v0, v1, v2, v3;
};