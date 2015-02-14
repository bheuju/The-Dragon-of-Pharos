#include "BasicShape.h"


BasicShape::BasicShape()
{

}

Object BasicShape::createCube()
{
	Object cube("cube");
	{
		cube.vertex.push_back(new Vector4D(-1, 1, 1));
		cube.vertex.push_back(new Vector4D(-1, -1, 1));
		cube.vertex.push_back(new Vector4D(1, -1, 1));
		cube.vertex.push_back(new Vector4D(1, 1, 1));
		cube.vertex.push_back(new Vector4D(-1, 1, -1));
		cube.vertex.push_back(new Vector4D(-1, -1, -1));
		cube.vertex.push_back(new Vector4D(1, -1, -1));
		cube.vertex.push_back(new Vector4D(1, 1, -1));
		cube.face.push_back(new Face(0, 1, 2));
		cube.face.push_back(new Face(2, 3, 0));
		cube.face.push_back(new Face(4, 7, 6));
		cube.face.push_back(new Face(6 ,5, 4));
		cube.face.push_back(new Face(0, 4, 5));
		cube.face.push_back(new Face(5, 1, 0));
		cube.face.push_back(new Face(7, 3, 2));
		cube.face.push_back(new Face(2, 6, 7));
		cube.face.push_back(new Face(0, 3, 7));
		cube.face.push_back(new Face(7, 4, 0));
		cube.face.push_back(new Face(1, 5, 6));
		cube.face.push_back(new Face(6, 2, 1));
	}
	return cube;
}

Object BasicShape::createOctahedron()
{
	Object octahedron("Octahedron");
	{
		octahedron.vertex.push_back(new Vector4D(1, 0, 0));
		octahedron.vertex.push_back(new Vector4D(0, -1, 0));
		octahedron.vertex.push_back(new Vector4D(-1, 0, 0));
		octahedron.vertex.push_back(new Vector4D(0, 1, 0));
		octahedron.vertex.push_back(new Vector4D(0, 0, 1));
		octahedron.vertex.push_back(new Vector4D(0, 0, -1));
		octahedron.face.push_back(new Face(1, 0, 4));
		octahedron.face.push_back(new Face(2, 1, 4));
		octahedron.face.push_back(new Face(3, 2, 4));
		octahedron.face.push_back(new Face(0, 3, 4));
		octahedron.face.push_back(new Face(0, 1, 5));
		octahedron.face.push_back(new Face(1, 2, 5));
		octahedron.face.push_back(new Face(2, 3, 5));
		octahedron.face.push_back(new Face(3, 0, 5));
	}
	return octahedron;
}

Object BasicShape::createTailFin()
{
	Object tailFin("Tail Fin");
	{
		tailFin.vertex.push_back(new Vector4D(-200, 0, 0));	//0
		tailFin.vertex.push_back(new Vector4D(-160, 15, 0));	//1
		tailFin.vertex.push_back(new Vector4D(-120, 64, 0));	//2
		tailFin.vertex.push_back(new Vector4D(-80, 64, 0));	//3
		tailFin.vertex.push_back(new Vector4D(-55, 71, 0));	//4
		tailFin.vertex.push_back(new Vector4D(-40, 82, 0));	//5
		tailFin.vertex.push_back(new Vector4D(-5, 70, 0));	//6
		tailFin.vertex.push_back(new Vector4D(30, 65, 0));	//7
		tailFin.vertex.push_back(new Vector4D(60, 69, 0));	//8
		tailFin.vertex.push_back(new Vector4D(45, 41, 0));	//9
		tailFin.vertex.push_back(new Vector4D(43, 29, 0));	//10
		tailFin.vertex.push_back(new Vector4D(45, 17, 0));	//11
		tailFin.vertex.push_back(new Vector4D(-18, 0, 0));	//12
		tailFin.vertex.push_back(new Vector4D(-200, 0, -10));	//13
		tailFin.vertex.push_back(new Vector4D(-18, 0, -10));	//14
		tailFin.face.push_back(new Face(0, 1, 2));
		tailFin.face.push_back(new Face(0, 2, 3));
		tailFin.face.push_back(new Face(0, 3, 4));
		tailFin.face.push_back(new Face(0, 4, 5));
		tailFin.face.push_back(new Face(0, 5, 6));
		tailFin.face.push_back(new Face(0, 6, 7));
		tailFin.face.push_back(new Face(0, 7, 8));
		tailFin.face.push_back(new Face(0, 8, 9));
		tailFin.face.push_back(new Face(0, 9, 10));
		tailFin.face.push_back(new Face(0, 10, 11));
		tailFin.face.push_back(new Face(0, 11, 12));
		tailFin.face.push_back(new Face(0, 12, 13));
		tailFin.face.push_back(new Face(12, 13, 14));
	}
	return tailFin;
}