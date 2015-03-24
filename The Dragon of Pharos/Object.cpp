#include "Object.h"
#include "IlluminationHandler.h"

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

void Object::calcFaceNormals()
{
	for (int i = 0; i < face.size(); i++)
	{
		Vector3D a = to3D(vertex[face[i]->v0]->vertexCoordinates);
		Vector3D b = to3D(vertex[face[i]->v1]->vertexCoordinates);
		Vector3D c = to3D(vertex[face[i]->v2]->vertexCoordinates);

		vertex[face[i]->v0]->adjFacesCount++;
		vertex[face[i]->v1]->adjFacesCount++;
		vertex[face[i]->v2]->adjFacesCount++;

		Vector3D u = b-a;
		Vector3D v = c-a;

		Vector3D fn = normalize(cross(u, v));

		//store face normals to respective face object
		face[i]->faceNormal = fn;
	}
}

void Object::calcVectorLightSource()
{
	Vector3D ls = IlluminationHandler::Instance()->lightSource;
	for (int i = 0; i < face.size(); i++)
	{
		Vector3D o = to3D(vertex[face[i]->v0]->vertexCoordinates);
		Vector3D L = normalize(ls-o);

	}
}


void Object::calcVertexNormals()
{
	//sum normals if vertex repeats in face
	for (int i = 0; i < face.size(); i++)
	{
		Vector3D fn = face[i]->faceNormal;
		Vector3D vn0 = vertex[face[i]->v0]->vertexNormal;
		Vector3D vn1 = vertex[face[i]->v1]->vertexNormal;
		Vector3D vn2 = vertex[face[i]->v2]->vertexNormal;

		vn0 = vn0 + fn;
		vn1 = vn1 + fn;
		vn2 = vn2 + fn;

		vertex[face[i]->v0]->vertexNormal = (vn0);
		vertex[face[i]->v1]->vertexNormal = (vn1);
		vertex[face[i]->v2]->vertexNormal = (vn2);

		//vertex[face[i]->v0]->vertexNormal = normalize(vn0);
		//vertex[face[i]->v1]->vertexNormal = normalize(vn1);
		//vertex[face[i]->v2]->vertexNormal = normalize(vn2);

		//int testVertex = 1;
		//if (face[i]->v0 == testVertex || face[i]->v1 == testVertex || face[i]->v2 == testVertex)
		//{
		//	std::cout<<"----- Vertex "<<testVertex<<" with Face "<<i<<std::endl;
		//	if (face[i]->v0 == testVertex)
		//		displayVector3D(vn0, "", 1);
		//	if (face[i]->v1 == testVertex)
		//		displayVector3D(vn1, "", 1);
		//	if (face[i]->v2 == testVertex)
		//		displayVector3D(vn2, "", 1);
		//}

		//std::cout<<"\nFace "<<i<<std::endl;
		//std::cout<<"Calculated"<<std::endl;
		//displayVector3D(vn0, "", 1);
		//std::cout<<"Stored"<<std::endl;
		//displayVector3D(vertex[face[i]->v0]->vertexNormal, "", 1);
	}

	//normalize vertex normals after calculation has ended
	//std::cout<<"\n\nNormalizing\n\n";
	for (int i = 0; i < vertex.size(); i++)
	{
		//std::cout<<"Vertex "<<i<<std::endl;
		//displayVector3D(vertex[i]->vertexNormal, "Non-Normalized", 1);

		//std::cout<<"Faces Count: "<<vertex[i]->adjFacesCount<<std::endl;

		//vertex[i]->vertexNormal = normalize(vertex[i]->vertexNormal / vertex[i]->adjFacesCount);
		vertex[i]->vertexNormal = normalize(vertex[i]->vertexNormal);

		//displayVector3D(vertex[i]->vertexNormal, "Normalized", 1);
	}
}

Object mirror(Object obj, int plane)
{
	Object image = Object(obj.name + "_image");
	//mirror vertex
	for (int i = 0; i < obj.vertex.size(); i++)
	{
		float x = obj.vertex[i]->vertexCoordinates.getX();
		float y = obj.vertex[i]->vertexCoordinates.getY();
		float z = obj.vertex[i]->vertexCoordinates.getZ();

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

		image.vertex.push_back(new Vertex(Vector4D(x, y, z)));
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

/* Vertex */
Vertex::Vertex() : vertexCoordinates(Vector4D()), vertexNormal(Vector3D()), vertexWorldCoordinates(Vector4D())
{

}

Vertex::Vertex(Vector4D vertexCoordinates, Vector4D vertexWorldCoordinates, Vector3D vertexNormal)
{
	this->vertexCoordinates = vertexCoordinates;
	this->vertexWorldCoordinates = vertexWorldCoordinates;
	this->vertexNormal = vertexNormal;
}

/* Faces */
Face::Face() : v0(0), v1(0), v2(0), faceNormal(Vector3D())
{

}

Face::Face(int a, int b, int c)
{
	v0 = a;
	v1 = b;
	v2 = c;
	//v3 = d;
}


