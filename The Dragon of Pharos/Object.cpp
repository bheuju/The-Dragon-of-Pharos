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

Object mirror(Object obj, int plane)
{
	Object image = Object(obj.name + "_image");
	//mirror vertex
	for (int i = 0; i < obj.vertex.size(); i++)
	{
		float x = obj.vertex[i]->getX();
		float y = obj.vertex[i]->getY();
		float z = obj.vertex[i]->getZ();

		switch(plane)
		{
		case XZ:
			y = -y;
			break;
		case YZ:
			x = -x;
			break;
		case XY:
			z = -z;
			break;
		}

		image.vertex.push_back(new Vector4D(x, y, z));
	}
	//mirror faces
	for (int i = 0; i < obj.face.size(); i++)
	{
		int A, B, C;

		A = obj.face[i]->v0;
		B = obj.face[i]->v1;
		C = obj.face[i]->v2;

		int temp;
		temp = A;
		A = C;
		C = temp;

		image.face.push_back(new Face(A, B, C));

		//std::cout<<A<<" "<<B<<" "<<C<<std::endl;
	}

	//Copy properties
	switch(plane)
	{
	case XZ:
		image.setTranslation(obj.tX, -obj.tY, obj.tZ);
		break;
	case YZ:
		image.setTranslation(-obj.tX, obj.tY, obj.tZ);
		break;
	case XY:
		image.setTranslation(obj.tX, obj.tY, -obj.tZ);
		break;
	}
	image.setRotation(-obj.angleX, -obj.angleY, -obj.angleZ);
	image.setScale(obj.sX, obj.sY, obj.sZ);

	return image;
}


/* Faces */
Face::Face() : v0(0), v1(0), v2(0)
{

}

Face::Face(int a, int b, int c)
{
	v0 = a;
	v1 = b;
	v2 = c;
	//v3 = d;
}


