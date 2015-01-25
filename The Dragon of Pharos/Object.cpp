#include "Object.h"

/* Objects */
Object::Object()
{

}

Object::Object(std::string objectName, int verticesCount, int faceCount)
{
	name = objectName;
	vertexCount = verticesCount;
	facesCount = faceCount;
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


