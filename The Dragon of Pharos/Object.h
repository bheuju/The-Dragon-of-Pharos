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
class Vertex;

enum plane
{
	XY = 0,
	YZ = 1,
	XZ = 2

};

class Object
{
public:
	Object();
	Object(std::string objectName);
	~Object() {}

	std::string name;
	std::vector<Vertex*> vertex;
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

	//Calculate face normals
	void calcFaceNormals();
	void calcVertexNormals();

	//Mirror object through specified plane: XY, YZ, XZ(default)
	friend Object mirror(Object obj, int plane = XZ);
};

class Vertex
{
public:
	Vertex();
	Vertex(float x = 0, float y = 0, float z = 0);
	~Vertex() {}

	Vector4D vertexCoordinates;
	Vector3D vertexNormal;
	int adjFacesCount;
};

class Face
{
public:
	Face();
	Face(int a, int b, int c);
	~Face() {}

	int v0, v1, v2;

	Vector3D faceNormal;
	//v3;
};