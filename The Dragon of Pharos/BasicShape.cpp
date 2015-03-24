#include "BasicShape.h"


BasicShape::BasicShape()
{}

Object BasicShape::createCube()
{
	Object cube("cube");
	{
		cube.vertex.push_back(new Vertex(Vector4D(-1, 1, 1)));		//0
		cube.vertex.push_back(new Vertex(Vector4D(-1, -1, 1)));		//1
		cube.vertex.push_back(new Vertex(Vector4D(1, -1, 1)));		//2
		cube.vertex.push_back(new Vertex(Vector4D(1, 1, 1)));		//3
		cube.vertex.push_back(new Vertex(Vector4D(-1, 1, -1)));		//4
		cube.vertex.push_back(new Vertex(Vector4D(-1, -1, -1)));	//5
		cube.vertex.push_back(new Vertex(Vector4D(1, -1, -1)));		//6
		cube.vertex.push_back(new Vertex(Vector4D(1, 1, -1)));		//7

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
		octahedron.vertex.push_back(new Vertex(Vector4D(1, 0, 0)));
		octahedron.vertex.push_back(new Vertex(Vector4D(0, -1, 0)));
		octahedron.vertex.push_back(new Vertex(Vector4D(-1, 0, 0)));
		octahedron.vertex.push_back(new Vertex(Vector4D(0, 1, 0)));
		octahedron.vertex.push_back(new Vertex(Vector4D(0, 0, 1)));
		octahedron.vertex.push_back(new Vertex(Vector4D(0, 0, -1)));
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
		tailFin.vertex.push_back(new Vertex(Vector4D(35, 0, 0)));	//0
		tailFin.vertex.push_back(new Vertex(Vector4D(65, 20, 0)));	//1
		tailFin.vertex.push_back(new Vertex(Vector4D(73, 57, 0)));	//2
		tailFin.vertex.push_back(new Vertex(Vector4D(26, 0, 0)));	//3
		tailFin.vertex.push_back(new Vertex(Vector4D(55, 65, 0)));	//4
		tailFin.vertex.push_back(new Vertex(Vector4D(20, 0, 0)));	//5
		tailFin.vertex.push_back(new Vertex(Vector4D(28, 55, 0)));	//6
		tailFin.vertex.push_back(new Vertex(Vector4D(12, 0, 0)));	//7
		tailFin.vertex.push_back(new Vertex(Vector4D(5, 25, 0)));	//8
		tailFin.vertex.push_back(new Vertex(Vector4D(0, 0, 0)));	//9

		tailFin.vertex.push_back(new Vertex(Vector4D(35, 0, 5)));	//10
		tailFin.vertex.push_back(new Vertex(Vector4D(65, 20, 3.46)));//11
		tailFin.vertex.push_back(new Vertex(Vector4D(73, 57, 0.61)));//12
		tailFin.vertex.push_back(new Vertex(Vector4D(26, 0, 5)));	//13
		tailFin.vertex.push_back(new Vertex(Vector4D(55, 65, 0)));	//14
		tailFin.vertex.push_back(new Vertex(Vector4D(20, 0, 5)));	//15
		tailFin.vertex.push_back(new Vertex(Vector4D(28, 55, 0.76)));//16
		tailFin.vertex.push_back(new Vertex(Vector4D(12, 0, 5)));	//17
		tailFin.vertex.push_back(new Vertex(Vector4D(5, 25, 3.07)));	//18
		tailFin.vertex.push_back(new Vertex(Vector4D(0, 0, 5)));	//19

		//top face
		tailFin.face.push_back(new Face(0, 1, 2));
		tailFin.face.push_back(new Face(0, 2, 3));
		tailFin.face.push_back(new Face(3, 2, 4));
		tailFin.face.push_back(new Face(3, 4, 5));
		tailFin.face.push_back(new Face(5, 4, 6));
		tailFin.face.push_back(new Face(5, 6, 7));
		tailFin.face.push_back(new Face(7, 6, 8));
		tailFin.face.push_back(new Face(7, 8, 9));

		//bottom face
		tailFin.face.push_back(new Face(10, 11, 12));
		tailFin.face.push_back(new Face(10, 12, 13));
		tailFin.face.push_back(new Face(13, 12, 14));
		tailFin.face.push_back(new Face(13, 14, 15));
		tailFin.face.push_back(new Face(15, 14, 16));
		tailFin.face.push_back(new Face(15, 16, 17));
		tailFin.face.push_back(new Face(17, 16, 18));
		tailFin.face.push_back(new Face(17, 18, 19));

		tailFin.face.push_back(new Face(4, 2, 12));

		tailFin.face.push_back(new Face(4, 16, 6));

		tailFin.face.push_back(new Face(2, 1, 11));
		tailFin.face.push_back(new Face(11, 12, 2));

		tailFin.face.push_back(new Face(1, 0, 10));
		tailFin.face.push_back(new Face(10, 11, 1));

		tailFin.face.push_back(new Face(8, 6, 16));
		tailFin.face.push_back(new Face(16, 18, 8));

		tailFin.face.push_back(new Face(9, 8, 18));
		tailFin.face.push_back(new Face(18, 19, 9));

		tailFin.face.push_back(new Face(0, 9, 19));
		tailFin.face.push_back(new Face(19, 10, 0));
	}
	return tailFin;
}

Object BasicShape::createBodyFin()
{
	Object bodyFin("Body Fin");
	{
		bodyFin.vertex.push_back(new Vertex(Vector4D(0, -5, 0)));		//0

		bodyFin.vertex.push_back(new Vertex(Vector4D(40, -35, 0)));		//1
		{
			bodyFin.vertex.push_back(new Vertex(Vector4D(40, -31, 0)));		//2
			bodyFin.vertex.push_back(new Vertex(Vector4D(42, -27, 0)));		//1
		}
		bodyFin.vertex.push_back(new Vertex(Vector4D(45, -25, 0)));		//3
		{
			bodyFin.vertex.push_back(new Vertex(Vector4D(45, -21, 0)));		//4
			bodyFin.vertex.push_back(new Vertex(Vector4D(47, -17, 0)));		//1
		}
		bodyFin.vertex.push_back(new Vertex(Vector4D(50, -15, 0)));		//5
		{
			bodyFin.vertex.push_back(new Vertex(Vector4D(51, -8, 0)));		//6
			bodyFin.vertex.push_back(new Vertex(Vector4D(55, -3, 0)));		//6
		}
		bodyFin.vertex.push_back(new Vertex(Vector4D(60, 0, 0)));		//7

		for (int i = 0; i < bodyFin.vertex.size() - 2; i++)
		{
			bodyFin.face.push_back(new Face(0, i+1, i+2));
		}

		//bodyFin.face.push_back(new Face(0, 1, 2));
		//bodyFin.face.push_back(new Face(0, 2, 3));
		//bodyFin.face.push_back(new Face(0, 3, 4));
	}
	return bodyFin;
}

Object BasicShape::createWing()
{
	Object wing("Wing");
	{
		wing.vertex.push_back(new Vertex(Vector4D(53, 0)));		//0
		wing.vertex.push_back(new Vertex(Vector4D(-35, 0)));	//1
		wing.vertex.push_back(new Vertex(Vector4D(45, -20)));	//2
		wing.vertex.push_back(new Vertex(Vector4D(-20, -30)));	//3
		wing.vertex.push_back(new Vertex(Vector4D(45, -40)));	//4
		wing.vertex.push_back(new Vertex(Vector4D(-25, -50)));	//5
		wing.vertex.push_back(new Vertex(Vector4D(58, -67)));	//6
		wing.vertex.push_back(new Vertex(Vector4D(0, -80)));	//7
		wing.vertex.push_back(new Vertex(Vector4D(52, -80)));	//8
		wing.vertex.push_back(new Vertex(Vector4D(52, -90)));	//9
		wing.vertex.push_back(new Vertex(Vector4D(3, -107)));	//10
		wing.vertex.push_back(new Vertex(Vector4D(60, -105)));	//11
		wing.vertex.push_back(new Vertex(Vector4D(50, -120)));	//12
		wing.vertex.push_back(new Vertex(Vector4D(0, -135)));	//13
		wing.vertex.push_back(new Vertex(Vector4D(50, -135)));	//14
		wing.vertex.push_back(new Vertex(Vector4D(60, -153)));	//15
		wing.vertex.push_back(new Vertex(Vector4D(50, -160)));	//16
		wing.vertex.push_back(new Vertex(Vector4D(-3, -158)));	//17
		wing.vertex.push_back(new Vertex(Vector4D(47, -172)));	//18
		wing.vertex.push_back(new Vertex(Vector4D(53, -185)));	//19
		wing.vertex.push_back(new Vertex(Vector4D(40, -190)));	//20
		wing.vertex.push_back(new Vertex(Vector4D(32, -200)));	//21
		wing.vertex.push_back(new Vertex(Vector4D(-18, -180)));	//22
		wing.vertex.push_back(new Vertex(Vector4D(30, -215)));	//23
		wing.vertex.push_back(new Vertex(Vector4D(33, -230)));	//24
		wing.vertex.push_back(new Vertex(Vector4D(16, -235)));	//25
		wing.vertex.push_back(new Vertex(Vector4D(5, -245)));	//26
		wing.vertex.push_back(new Vertex(Vector4D(-2, -265)));	//27
		wing.vertex.push_back(new Vertex(Vector4D(-40, -198)));	//28
		wing.vertex.push_back(new Vertex(Vector4D(-45, -110)));	//29

		//Interpolate value of z with curve (maybe spline or beizer)
		//according to value of |y|
		for (int i = 0; i < wing.vertex.size(); i++)
		{
			wing.vertex[i]->vertexCoordinates.setZ(0);	//interpolated value
		}

		//Group 0
		wing.face.push_back(new Face(0, 1, 2));
		wing.face.push_back(new Face(2, 1, 3));
		wing.face.push_back(new Face(2, 3, 4));
		wing.face.push_back(new Face(4, 3, 5));
		wing.face.push_back(new Face(4, 5, 6));
		wing.face.push_back(new Face(6, 5, 7));
		wing.face.push_back(new Face(7, 5, 29));
		//Group 1
		wing.face.push_back(new Face(6, 7, 8));
		wing.face.push_back(new Face(8, 7, 9));
		wing.face.push_back(new Face(9, 7, 10));
		wing.face.push_back(new Face(9, 10, 11));
		wing.face.push_back(new Face(10, 7, 29));
		//Group 2
		wing.face.push_back(new Face(11, 10, 12));
		wing.face.push_back(new Face(12, 10, 13));
		wing.face.push_back(new Face(12, 13, 14));
		wing.face.push_back(new Face(14, 13, 15));
		wing.face.push_back(new Face(13, 10, 29));
		//Group 3
		wing.face.push_back(new Face(15, 13, 16));
		wing.face.push_back(new Face(16, 13, 17));
		wing.face.push_back(new Face(16, 17, 18));
		wing.face.push_back(new Face(18, 17, 19));
		wing.face.push_back(new Face(17, 13, 29));
		//Group 4
		wing.face.push_back(new Face(19, 17, 20));
		wing.face.push_back(new Face(20, 17, 22));
		wing.face.push_back(new Face(20, 22, 21));
		wing.face.push_back(new Face(21, 22, 23));
		wing.face.push_back(new Face(23, 22, 24));
		wing.face.push_back(new Face(22, 17, 29));
		//Group 5
		wing.face.push_back(new Face(24, 22, 25));
		wing.face.push_back(new Face(25, 22, 28));
		wing.face.push_back(new Face(25, 28, 26));
		wing.face.push_back(new Face(26, 28, 27));
		wing.face.push_back(new Face(28, 22, 29));

	}
	return wing;
}

Object BasicShape::createHead()
{
	Object head("Head");
	{
		head.vertex.push_back(new Vertex(Vector4D(0, -33, -4)));	//0
		head.vertex.push_back(new Vertex(Vector4D(0, -27, -2)));	//1
		head.vertex.push_back(new Vertex(Vector4D(0, -25, -2)));	//2
		head.vertex.push_back(new Vertex(Vector4D(30, -20, -3)));	//3
		head.vertex.push_back(new Vertex(Vector4D(14, -17, -4)));	//4
		head.vertex.push_back(new Vertex(Vector4D(24, -17, -4)));	//5
		head.vertex.push_back(new Vertex(Vector4D(7, -16, 0)));	//6
		head.vertex.push_back(new Vertex(Vector4D(14, -13, -3)));	//7
		head.vertex.push_back(new Vertex(Vector4D(34, -25, -3)));	//8
		head.vertex.push_back(new Vertex(Vector4D(42, -16, -15)));	//9
		head.vertex.push_back(new Vertex(Vector4D(39, -13, -8)));	//10
		head.vertex.push_back(new Vertex(Vector4D(19, -9, -4)));	//11
		head.vertex.push_back(new Vertex(Vector4D(23, -5, -7)));	//12
		head.vertex.push_back(new Vertex(Vector4D(29, -8, -7)));	//13
		head.vertex.push_back(new Vertex(Vector4D(35, -7, -7)));	//14
		head.vertex.push_back(new Vertex(Vector4D(40, -3, -9)));	//15
		head.vertex.push_back(new Vertex(Vector4D(15, -9, -5)));	//16
		head.vertex.push_back(new Vertex(Vector4D(19, -1, -6)));	//17
		head.vertex.push_back(new Vertex(Vector4D(22, -1, -7)));	//18
		head.vertex.push_back(new Vertex(Vector4D(6, 0, 0)));	//19
		head.vertex.push_back(new Vertex(Vector4D(12, 0, -3)));	//20
		head.vertex.push_back(new Vertex(Vector4D(15, 5, -5)));	//21
		head.vertex.push_back(new Vertex(Vector4D(20, 5, -5)));	//22
		head.vertex.push_back(new Vertex(Vector4D(26, 7, -5)));	//23
		head.vertex.push_back(new Vertex(Vector4D(38, 8, -9)));	//24
		head.vertex.push_back(new Vertex(Vector4D(38, 10, -7)));	//25
		head.vertex.push_back(new Vertex(Vector4D(31, 9, -5)));	//26
		head.vertex.push_back(new Vertex(Vector4D(10, 10, -3)));	//27
		head.vertex.push_back(new Vertex(Vector4D(24, 8, -6)));	//28
		head.vertex.push_back(new Vertex(Vector4D(21, 11, -7)));	//29
		head.vertex.push_back(new Vertex(Vector4D(29, 12, -5)));	//30
		head.vertex.push_back(new Vertex(Vector4D(33, 13, -8)));	//31
		head.vertex.push_back(new Vertex(Vector4D(37, 14, -15)));	//32
		head.vertex.push_back(new Vertex(Vector4D(15, 15, -2)));	//33
		head.vertex.push_back(new Vertex(Vector4D(25, 14, -3)));	//34
		head.vertex.push_back(new Vertex(Vector4D(28, 16, -4)));	//35
		head.vertex.push_back(new Vertex(Vector4D(32, 18, -5)));	//36
		head.vertex.push_back(new Vertex(Vector4D(37, 20, -9)));	//37
		head.vertex.push_back(new Vertex(Vector4D(9, 19, -3)));	//38
		head.vertex.push_back(new Vertex(Vector4D(0, 20, -2)));	//39
		head.vertex.push_back(new Vertex(Vector4D(19, 20, -9)));	//40
		head.vertex.push_back(new Vertex(Vector4D(26, 23, -11)));	//41
		head.vertex.push_back(new Vertex(Vector4D(31, 25, -13)));	//42
		head.vertex.push_back(new Vertex(Vector4D(36, 25, -15)));	//43
		head.vertex.push_back(new Vertex(Vector4D(0, 30, -18)));	//44
		head.vertex.push_back(new Vertex(Vector4D(9, 30, -18)));	//45
		head.vertex.push_back(new Vertex(Vector4D(17, 30, -18)));	//46
		head.vertex.push_back(new Vertex(Vector4D(21, 32, -19)));	//47
		head.vertex.push_back(new Vertex(Vector4D(27, 33, -19)));	//48
		head.vertex.push_back(new Vertex(Vector4D(36, 31, -18)));	//49
		head.vertex.push_back(new Vertex(Vector4D(33, 34, -20)));	//50
		head.vertex.push_back(new Vertex(Vector4D(0, 40 -30)));	//51
		head.vertex.push_back(new Vertex(Vector4D(5, 40 -30)));	//52
		head.vertex.push_back(new Vertex(Vector4D(14, 40 -30)));	//53
		head.vertex.push_back(new Vertex(Vector4D(21, 41, -30)));	//54
		head.vertex.push_back(new Vertex(Vector4D(0, 43, -38)));	//55
		head.vertex.push_back(new Vertex(Vector4D(3, 43, -38)));	//56
		head.vertex.push_back(new Vertex(Vector4D(13, 42, -38)));	//57
		head.vertex.push_back(new Vertex(Vector4D(0, -17, 0)));	//58
		head.vertex.push_back(new Vertex(Vector4D(0, 0, 0)));	//59
		head.vertex.push_back(new Vertex(Vector4D(38, -17, -5)));	//60
		head.vertex.push_back(new Vertex(Vector4D(28, -22, -3)));	//61
		
		//Group a
		head.face.push_back(new Face(0, 8, 1));
		head.face.push_back(new Face(8, 61, 1));
		head.face.push_back(new Face(8, 60, 61));
		head.face.push_back(new Face(8, 9, 60));
		head.face.push_back(new Face(9, 10, 60));
		head.face.push_back(new Face(9, 15, 10));
		head.face.push_back(new Face(10, 15, 14));
		head.face.push_back(new Face(10, 14, 60));
		head.face.push_back(new Face(60, 14, 3));
		head.face.push_back(new Face(60, 3, 61));
		head.face.push_back(new Face(61, 3, 2));
		head.face.push_back(new Face(61, 2, 1));
		//Group b
		head.face.push_back(new Face(2, 3, 5));
		head.face.push_back(new Face(3, 14, 5));
		head.face.push_back(new Face(14, 13, 5));
		head.face.push_back(new Face(2, 5, 4));
		head.face.push_back(new Face(5, 11, 4));
		head.face.push_back(new Face(4, 11, 7));
		head.face.push_back(new Face(5, 13, 11));
		head.face.push_back(new Face(13, 12, 11));
		//Group c
		head.face.push_back(new Face(2, 4, 6));
		head.face.push_back(new Face(2, 6, 58));
		head.face.push_back(new Face(6, 4, 7));
		//Group d
		head.face.push_back(new Face(6, 7, 20));
		head.face.push_back(new Face(6, 20, 19));
		head.face.push_back(new Face(6, 19, 59));
		head.face.push_back(new Face(6, 59, 58));
		//Group e
		head.face.push_back(new Face(7, 11, 16));
		head.face.push_back(new Face(7, 16, 20));
		head.face.push_back(new Face(20, 16, 21));
		//Group f
		head.face.push_back(new Face(11, 12, 18));
		head.face.push_back(new Face(11, 18, 17));
		head.face.push_back(new Face(11, 17, 16));
		head.face.push_back(new Face(16, 17, 21));
		head.face.push_back(new Face(17, 22, 21));
		head.face.push_back(new Face(17, 18, 22));
		head.face.push_back(new Face(18, 23, 22));
		head.face.push_back(new Face(22, 23, 28));
		head.face.push_back(new Face(22, 28, 29));
		head.face.push_back(new Face(22, 29, 21));
		//Group g
		head.face.push_back(new Face(23, 24, 26));
		head.face.push_back(new Face(24, 25, 26));
		head.face.push_back(new Face(26, 25, 32));
		head.face.push_back(new Face(26, 32, 31));
		head.face.push_back(new Face(26, 31, 30));
		head.face.push_back(new Face(26, 30, 28));
		head.face.push_back(new Face(26, 28, 23));
		//Group h
		head.face.push_back(new Face(28, 34, 29));
		head.face.push_back(new Face(28, 30, 34));
		head.face.push_back(new Face(30, 35, 34));
		head.face.push_back(new Face(30, 36, 35));
		head.face.push_back(new Face(30, 31, 36));
		head.face.push_back(new Face(31, 32, 36));
		head.face.push_back(new Face(32, 37, 36));
		//Group i
		head.face.push_back(new Face(21, 33, 27));
		head.face.push_back(new Face(21, 29, 33));
		head.face.push_back(new Face(29, 40, 33));
		head.face.push_back(new Face(29, 34, 40));
		head.face.push_back(new Face(34, 41, 40));
		head.face.push_back(new Face(34, 35, 41));
		head.face.push_back(new Face(35, 42, 41));
		head.face.push_back(new Face(35, 36, 42));
		head.face.push_back(new Face(36, 43, 42));
		head.face.push_back(new Face(36, 37, 43));
		//Group j
		head.face.push_back(new Face(27, 59, 19));
		head.face.push_back(new Face(27, 19, 20));
		head.face.push_back(new Face(27, 20, 21));
		head.face.push_back(new Face(27, 33, 38));
		head.face.push_back(new Face(27, 38, 39));
		head.face.push_back(new Face(27, 39, 59));
		//Group k
		head.face.push_back(new Face(42, 43, 49));
		head.face.push_back(new Face(42, 49, 50));
		head.face.push_back(new Face(42, 50, 48));
		head.face.push_back(new Face(42, 48, 41));
		head.face.push_back(new Face(41, 48, 47));
		head.face.push_back(new Face(41, 47, 46));
		head.face.push_back(new Face(41, 46, 40));
		head.face.push_back(new Face(40, 46, 45));
		head.face.push_back(new Face(40, 45, 33));
		head.face.push_back(new Face(33, 45, 38));
		head.face.push_back(new Face(38, 45, 39));
		head.face.push_back(new Face(39, 45, 44));
		//Group l
		head.face.push_back(new Face(50, 54, 48));
		head.face.push_back(new Face(48, 54, 47));
		head.face.push_back(new Face(47, 54, 53));
		head.face.push_back(new Face(47, 53, 46));
		head.face.push_back(new Face(46, 53, 45));
		head.face.push_back(new Face(45, 53, 52));
		head.face.push_back(new Face(45, 52, 44));
		head.face.push_back(new Face(44, 52, 51));
		//Group m
		head.face.push_back(new Face(54, 57, 53));
		head.face.push_back(new Face(53, 57, 52));
		head.face.push_back(new Face(52, 57, 56));
		head.face.push_back(new Face(52, 56, 51));
		head.face.push_back(new Face(51, 56, 55));
		//Group n
		head.face.push_back(new Face(15, 24, 23));
		head.face.push_back(new Face(15, 23, 14));
		head.face.push_back(new Face(14, 23, 18));
		head.face.push_back(new Face(14, 18, 13));
		head.face.push_back(new Face(13, 18, 12));
		
	}
	return head;
}

Object BasicShape::createTower(float h)
{
	Object tower("tower");
	{
		tower.vertex.push_back(new Vertex(Vector4D(10,0,0)));   //0
		tower.vertex.push_back(new Vertex(Vector4D(8,0,6)));	//1
		tower.vertex.push_back(new Vertex(Vector4D(3,0,10)));   //2
		tower.vertex.push_back(new Vertex(Vector4D(-3,0,10)));	//3
		tower.vertex.push_back(new Vertex(Vector4D(-8,0,6)));	//4
		tower.vertex.push_back(new Vertex(Vector4D(-10,0,0)));	//5
		tower.vertex.push_back(new Vertex(Vector4D(-8,0,-6)));	//6
		tower.vertex.push_back(new Vertex(Vector4D(-3,0,-10)));	//7
		tower.vertex.push_back(new Vertex(Vector4D(3,0,-10)));	//8
		tower.vertex.push_back(new Vertex(Vector4D(8,0,-6)));	//9

		tower.vertex.push_back(new Vertex(Vector4D(7,h,0)));	//10
		tower.vertex.push_back(new Vertex(Vector4D(6,h,4)));	//11
		tower.vertex.push_back(new Vertex(Vector4D(2,h,7)));	//12
		tower.vertex.push_back(new Vertex(Vector4D(-2,h,7)));	//13
		tower.vertex.push_back(new Vertex(Vector4D(-6,h,4)));	//14
		tower.vertex.push_back(new Vertex(Vector4D(-7,h,0)));	//15
		tower.vertex.push_back(new Vertex(Vector4D(-6,h,-4)));	//16
		tower.vertex.push_back(new Vertex(Vector4D(-2,h,-7)));	//17
		tower.vertex.push_back(new Vertex(Vector4D(2,h,-7)));	//18
		tower.vertex.push_back(new Vertex(Vector4D(6,h,-4)));	//19

		tower.face.push_back(new Face(0,10,1));
		tower.face.push_back(new Face(1,11,2));
		tower.face.push_back(new Face(2,12,3));
		tower.face.push_back(new Face(3,13,4));
		tower.face.push_back(new Face(4,14,5));

		tower.face.push_back(new Face(10,1,11));
		tower.face.push_back(new Face(11,2,12));
		tower.face.push_back(new Face(12,3,13));
		tower.face.push_back(new Face(13,4,14));
		tower.face.push_back(new Face(14,5,15));

		tower.face.push_back(new Face(5,15,6));
		tower.face.push_back(new Face(6,16,7));
		tower.face.push_back(new Face(7,17,8));
		tower.face.push_back(new Face(8,18,9));
		tower.face.push_back(new Face(9,19,0));

		tower.face.push_back(new Face(15,6,16));
		tower.face.push_back(new Face(16,7,17));
		tower.face.push_back(new Face(17,8,18));
		tower.face.push_back(new Face(18,9,19));
		tower.face.push_back(new Face(19,10,0));
	}
	return tower;
}

Object BasicShape::createHemiSphere()
{
	Object hemiSphere("hemiSphere");
	{
		float org = 35;
		hemiSphere.vertex.push_back(new Vertex(Vector4D(7,35-org,0)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(6,35-org,4)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(2,35-org,7)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-2,35-org,7)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-6,35-org,4)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-7,35-org,0)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-6,35-org,-4)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-2,35-org,-7)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(2,35-org,-7)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(6,35-org,-4)));

		hemiSphere.vertex.push_back(new Vertex(Vector4D(6,38.6-org,0)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(5,38.6-org,4)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(2,38.6-org,6)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-2,38.6-org,6)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-5,38.6-org,4)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-6,38.6-org,0)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-5,38.6-org,-4)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(-2,38.6-org,-6)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(2,38.6-org,-6)));
		hemiSphere.vertex.push_back(new Vertex(Vector4D(5,38.6-org,-4)));

		hemiSphere.vertex.push_back(new  Vertex(Vector4D(5,39.9-org,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(4,39.9-org,3)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(2,39.9-org,5)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-2,39.9-org,5)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-4,39.9-org,3)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-5,39.9-org,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-4,39.9-org,-3)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-2,39.9-org,-5)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(2,39.9-org,-5)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(4,39.9-org,-3)));

		hemiSphere.vertex.push_back(new  Vertex(Vector4D(4,40.7-org,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(3,40.7-org,2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(1,40.7-org,4)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-1,40.7-org,4)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-3,40.7-org,2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-4,40.7-org,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-3,40.7-org,-2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-1,40.7-org,-4)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(1,40.7-org,-4)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(3,40.7-org,-2)));

		hemiSphere.vertex.push_back(new  Vertex(Vector4D(3,41.3-org,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(2,41.3-org,2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(1,41.3-org,3)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-1,41.3-org,3)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-2,41.3-org,2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-3,41.3-org,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-2,41.3-org,-2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-1,41.3-org,-3)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(1,41.3-org,-3)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(2,41.3-org,-2)));

		hemiSphere.vertex.push_back(new  Vertex(Vector4D(2,41.7-org,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(1.7,41.7-org,1.2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(.6,41.7-org,2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-.6,41.7-org,2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-1.7,41.7-org,1.2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-2,41.7-org,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-1.7,41.7-org,-1.2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-0.6,41.7-org,-2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(0.6,41.7-org,-2)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(1.7,41.7-org,-1.2)));

		/*	hemiSphere.vertex.push_back(new  Vertex(Vector4D(1,41.9,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(.8,41.9,.6)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(.3,41.9,1)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-.3,41.9,1)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-.8,41.9,.6)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-1,41.9,0)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-.8,41.9,-.6)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(-.3,41.9,-1)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(.3,41.9,-1)));
		hemiSphere.vertex.push_back(new  Vertex(Vector4D(.8,41.9,-.6)));*/

		hemiSphere.vertex.push_back(new  Vertex(Vector4D(0,42-org,0)));

		hemiSphere.face.push_back(new Face(1,10,0));
		hemiSphere.face.push_back(new Face(2,11,1));
		hemiSphere.face.push_back(new Face(3,12,2));
		hemiSphere.face.push_back(new Face(4,13,3));
		hemiSphere.face.push_back(new Face(5,14,4));
		hemiSphere.face.push_back(new Face(6,15,5));
        hemiSphere.face.push_back(new Face(7,16,6));
		hemiSphere.face.push_back(new Face(8,17,7));
		hemiSphere.face.push_back(new Face(9,18,8));
		hemiSphere.face.push_back(new Face(0,19,9));

		hemiSphere.face.push_back(new Face(11,20,10));
		hemiSphere.face.push_back(new Face(12,21,11));
		hemiSphere.face.push_back(new Face(13,22,12));
		hemiSphere.face.push_back(new Face(14,23,13));
		hemiSphere.face.push_back(new Face(15,24,14));
		hemiSphere.face.push_back(new Face(16,25,15));
		hemiSphere.face.push_back(new Face(17,26,16));
		hemiSphere.face.push_back(new Face(18,27,17));
		hemiSphere.face.push_back(new Face(19,28,18));
		hemiSphere.face.push_back(new Face(10,29,19));

		hemiSphere.face.push_back(new Face(21,30,20));
		hemiSphere.face.push_back(new Face(22,31,21));
		hemiSphere.face.push_back(new Face(23,32,22));
		hemiSphere.face.push_back(new Face(24,33,23));
		hemiSphere.face.push_back(new Face(25,34,24));
		hemiSphere.face.push_back(new Face(26,35,25));
		hemiSphere.face.push_back(new Face(27,36,26));
		hemiSphere.face.push_back(new Face(28,37,27));
		hemiSphere.face.push_back(new Face(29,38,28));
		hemiSphere.face.push_back(new Face(20,39,29));

		hemiSphere.face.push_back(new Face(31,40,30));
		hemiSphere.face.push_back(new Face(32,41,31));
		hemiSphere.face.push_back(new Face(33,42,32));
		hemiSphere.face.push_back(new Face(34,43,33));
		hemiSphere.face.push_back(new Face(35,44,34));
		hemiSphere.face.push_back(new Face(36,45,35));
		hemiSphere.face.push_back(new Face(37,46,36));
		hemiSphere.face.push_back(new Face(38,47,37));
		hemiSphere.face.push_back(new Face(39,48,38));
		hemiSphere.face.push_back(new Face(30,49,39));

		hemiSphere.face.push_back(new Face(41,50,40));
		hemiSphere.face.push_back(new Face(42,51,41));
		hemiSphere.face.push_back(new Face(43,52,42));
		hemiSphere.face.push_back(new Face(44,53,43));
		hemiSphere.face.push_back(new Face(45,54,44));
		hemiSphere.face.push_back(new Face(46,55,45));
		hemiSphere.face.push_back(new Face(47,56,46));
		hemiSphere.face.push_back(new Face(48,57,47));
		hemiSphere.face.push_back(new Face(49,58,48));
		hemiSphere.face.push_back(new Face(40,59,49));

		hemiSphere.face.push_back(new Face(51,60,50));
		hemiSphere.face.push_back(new Face(52,60,51));
		hemiSphere.face.push_back(new Face(53,60,52));
		hemiSphere.face.push_back(new Face(54,60,53));
		hemiSphere.face.push_back(new Face(55,60,54));
		hemiSphere.face.push_back(new Face(56,60,55));
		hemiSphere.face.push_back(new Face(57,60,56));
		hemiSphere.face.push_back(new Face(58,60,57));
		hemiSphere.face.push_back(new Face(59,60,58));
		hemiSphere.face.push_back(new Face(50,60,59));

		hemiSphere.face.push_back(new Face(10,1,11));
		hemiSphere.face.push_back(new Face(11,2,12));
		hemiSphere.face.push_back(new Face(12,3,13));
		hemiSphere.face.push_back(new Face(13,4,14));
		hemiSphere.face.push_back(new Face(14,5,15));
		hemiSphere.face.push_back(new Face(15,6,16));
		hemiSphere.face.push_back(new Face(16,7,17));
		hemiSphere.face.push_back(new Face(17,8,18));
		hemiSphere.face.push_back(new Face(18,9,19));
		hemiSphere.face.push_back(new Face(19,0,10)); 

		hemiSphere.face.push_back(new Face(20,11,21));
		hemiSphere.face.push_back(new Face(21,12,22));
		hemiSphere.face.push_back(new Face(22,13,23));
		hemiSphere.face.push_back(new Face(23,14,24));
		hemiSphere.face.push_back(new Face(24,15,25));
		hemiSphere.face.push_back(new Face(25,16,26));
		hemiSphere.face.push_back(new Face(26,17,27));
		hemiSphere.face.push_back(new Face(27,18,28));
		hemiSphere.face.push_back(new Face(28,19,29));
		hemiSphere.face.push_back(new Face(29,10,20));

		hemiSphere.face.push_back(new Face(30,21,31));
		hemiSphere.face.push_back(new Face(31,22,32));
		hemiSphere.face.push_back(new Face(32,23,33));
		hemiSphere.face.push_back(new Face(33,24,34));
		hemiSphere.face.push_back(new Face(34,25,35));
		hemiSphere.face.push_back(new Face(35,26,36));
		hemiSphere.face.push_back(new Face(36,27,37));
		hemiSphere.face.push_back(new Face(37,28,38));
		hemiSphere.face.push_back(new Face(38,29,39));
		hemiSphere.face.push_back(new Face(39,20,30));

		hemiSphere.face.push_back(new Face(40,31,41));
		hemiSphere.face.push_back(new Face(41,32,42));
		hemiSphere.face.push_back(new Face(42,33,43));
		hemiSphere.face.push_back(new Face(43,34,44));
		hemiSphere.face.push_back(new Face(44,35,45));
		hemiSphere.face.push_back(new Face(45,36,46));
		hemiSphere.face.push_back(new Face(46,37,47));
		hemiSphere.face.push_back(new Face(47,38,48));
		hemiSphere.face.push_back(new Face(48,39,49));
		hemiSphere.face.push_back(new Face(49,30,40));

		hemiSphere.face.push_back(new Face(50,41,51));
		hemiSphere.face.push_back(new Face(51,42,52));
		hemiSphere.face.push_back(new Face(52,43,53));
		hemiSphere.face.push_back(new Face(53,44,54));
		hemiSphere.face.push_back(new Face(54,45,55));
		hemiSphere.face.push_back(new Face(55,46,56));
		hemiSphere.face.push_back(new Face(56,47,57));
		hemiSphere.face.push_back(new Face(57,48,58));
		hemiSphere.face.push_back(new Face(58,49,59));
		hemiSphere.face.push_back(new Face(59,40,50));
	}
	return hemiSphere;
}

Object BasicShape::createTorus()
{
	Object torus("torus");
	{
		torus.vertex.push_back(new Vertex(Vector4D(8,2,0)));
		torus.vertex.push_back(new Vertex(Vector4D(6,2,5)));
		torus.vertex.push_back(new Vertex(Vector4D(2,2,8)));
		torus.vertex.push_back(new Vertex(Vector4D(-2,2,8)));
		torus.vertex.push_back(new Vertex(Vector4D(-6,2,5)));
		torus.vertex.push_back(new Vertex(Vector4D(-8,2,0)));
		torus.vertex.push_back(new Vertex(Vector4D(-6,2,-5)));
		torus.vertex.push_back(new Vertex(Vector4D(-2,2,-8)));
		torus.vertex.push_back(new Vertex(Vector4D(2,2,-8)));
		torus.vertex.push_back(new Vertex(Vector4D(6,2,-5)));

		torus.vertex.push_back(new Vertex(Vector4D(8.3,1.8,0)));
		torus.vertex.push_back(new Vertex(Vector4D(6.7,1.8,4.9)));
		torus.vertex.push_back(new Vertex(Vector4D(2.6,1.8,7.9)));
		torus.vertex.push_back(new Vertex(Vector4D(-2.6,1.8,7.9)));
		torus.vertex.push_back(new Vertex(Vector4D(-6.7,1.8,4.9)));
		torus.vertex.push_back(new Vertex(Vector4D(-8.3,1.8,0)));
		torus.vertex.push_back(new Vertex(Vector4D(-6.7,1.8,-4.9)));
		torus.vertex.push_back(new Vertex(Vector4D(-2.6,1.8,-7.9)));
		torus.vertex.push_back(new Vertex(Vector4D(2.8,1.8,-7.9)));
		torus.vertex.push_back(new Vertex(Vector4D(6.7,1.8,-4.9)));


		torus.vertex.push_back(new Vertex(Vector4D(9,1,0)));
		torus.vertex.push_back(new Vertex(Vector4D(7,1,5)));
		torus.vertex.push_back(new Vertex(Vector4D(3,1,9)));
		torus.vertex.push_back(new Vertex(Vector4D(-3,1,9)));
		torus.vertex.push_back(new Vertex(Vector4D(-7,1,5)));
		torus.vertex.push_back(new Vertex(Vector4D(-9,1,0)));
		torus.vertex.push_back(new Vertex(Vector4D(-7,1,-5)));
		torus.vertex.push_back(new Vertex(Vector4D(-3,1,-9)));
		torus.vertex.push_back(new Vertex(Vector4D(3,1,-9)));
		torus.vertex.push_back(new Vertex(Vector4D(7,1,-5)));

		torus.vertex.push_back(new Vertex(Vector4D(8.3,.3,0)));
		torus.vertex.push_back(new Vertex(Vector4D(6.7,.3,4.9)));
		torus.vertex.push_back(new Vertex(Vector4D(2.6,.3,7.9)));
		torus.vertex.push_back(new Vertex(Vector4D(-2.6,.3,7.9)));
		torus.vertex.push_back(new Vertex(Vector4D(-6.7,.3,4.9)));
		torus.vertex.push_back(new Vertex(Vector4D(-8.3,.3,0)));
		torus.vertex.push_back(new Vertex(Vector4D(-6.7,.3,-4.9)));
		torus.vertex.push_back(new Vertex(Vector4D(-2.6,.3,-7.9)));
		torus.vertex.push_back(new Vertex(Vector4D(2.8,.3,-7.9)));
		torus.vertex.push_back(new Vertex(Vector4D(6.7,.3,-4.9)));


		torus.vertex.push_back(new Vertex(Vector4D(8,0,0)));
		torus.vertex.push_back(new Vertex(Vector4D(6,0,5)));
		torus.vertex.push_back(new Vertex(Vector4D(2,0,8)));
		torus.vertex.push_back(new Vertex(Vector4D(-2,0,8)));
		torus.vertex.push_back(new Vertex(Vector4D(-6,0,5)));
		torus.vertex.push_back(new Vertex(Vector4D(-8,0,0)));
		torus.vertex.push_back(new Vertex(Vector4D(-6,0,-5)));
		torus.vertex.push_back(new Vertex(Vector4D(-2,0,-8)));
		torus.vertex.push_back(new Vertex(Vector4D(2,0,-8)));
		torus.vertex.push_back(new Vertex(Vector4D(6,0,-5)));


		torus.face.push_back(new Face(1,10,0));
		torus.face.push_back(new Face(2,11,1));
		torus.face.push_back(new Face(3,12,2));
		torus.face.push_back(new Face(4,13,3));
		torus.face.push_back(new Face(5,14,4));
		torus.face.push_back(new Face(6,15,5));
        torus.face.push_back(new Face(7,16,6));
		torus.face.push_back(new Face(8,17,7));
		torus.face.push_back(new Face(9,18,8));
		torus.face.push_back(new Face(0,19,9));

		torus.face.push_back(new Face(11,20,10));
		torus.face.push_back(new Face(12,21,11));
		torus.face.push_back(new Face(13,22,12));
		torus.face.push_back(new Face(14,23,13));
		torus.face.push_back(new Face(15,24,14));
		torus.face.push_back(new Face(16,25,15));
		torus.face.push_back(new Face(17,26,16));
		torus.face.push_back(new Face(18,27,17));
		torus.face.push_back(new Face(19,28,18));
		torus.face.push_back(new Face(10,29,19));

		torus.face.push_back(new Face(21,30,20));
		torus.face.push_back(new Face(22,31,21));
		torus.face.push_back(new Face(23,32,22));
		torus.face.push_back(new Face(24,33,23));
		torus.face.push_back(new Face(25,34,24));
		torus.face.push_back(new Face(26,35,25));
		torus.face.push_back(new Face(27,36,26));
		torus.face.push_back(new Face(28,37,27));
		torus.face.push_back(new Face(29,38,28));
		torus.face.push_back(new Face(20,39,29));

		torus.face.push_back(new Face(10,1,11));
		torus.face.push_back(new Face(11,2,12));
		torus.face.push_back(new Face(12,3,13));
		torus.face.push_back(new Face(13,4,14));
		torus.face.push_back(new Face(14,5,15));
		torus.face.push_back(new Face(15,6,16));
		torus.face.push_back(new Face(16,7,17));
		torus.face.push_back(new Face(17,8,18));
		torus.face.push_back(new Face(18,9,19));
		torus.face.push_back(new Face(19,0,10)); 

		torus.face.push_back(new Face(20,11,21));
		torus.face.push_back(new Face(21,12,22));
		torus.face.push_back(new Face(22,13,23));
		torus.face.push_back(new Face(23,14,24));
		torus.face.push_back(new Face(24,15,25));
		torus.face.push_back(new Face(25,16,26));
		torus.face.push_back(new Face(26,17,27));
		torus.face.push_back(new Face(27,18,28));
		torus.face.push_back(new Face(28,19,29));
		torus.face.push_back(new Face(29,10,20));

		torus.face.push_back(new Face(30,21,31));
		torus.face.push_back(new Face(31,22,32));
		torus.face.push_back(new Face(32,23,33));
		torus.face.push_back(new Face(33,24,34));
		torus.face.push_back(new Face(34,25,35));
		torus.face.push_back(new Face(35,26,36));
		torus.face.push_back(new Face(36,27,37));
		torus.face.push_back(new Face(37,28,38));
		torus.face.push_back(new Face(38,29,39));
		torus.face.push_back(new Face(39,20,30));
	}
	return torus;
}