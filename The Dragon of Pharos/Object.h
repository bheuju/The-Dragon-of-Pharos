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
	Object(std::string objectName, int verticesCount, int faceCount);
	~Object() {}

	std::string name;
	int vertexCount, facesCount;
	std::vector<Vector4D*> vertex;
	std::vector<Face*> face;
	
	Matrix4 translation, rotation, scale;
	Matrix4 modelMatrix;
};

class Face
{
public:
	Face();
	Face(int a, int b, int c, int d);
	~Face() {}

	int v0, v1, v2, v3;
};