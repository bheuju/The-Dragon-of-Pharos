#include "BasicShape.h"


BasicShape::BasicShape()
{}

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
		tailFin.vertex.push_back(new Vector4D(35, 0, 0));	//0
		tailFin.vertex.push_back(new Vector4D(65, 20, 0));	//1
		tailFin.vertex.push_back(new Vector4D(73, 57, 0));	//2
		tailFin.vertex.push_back(new Vector4D(26, 0, 0));	//3
		tailFin.vertex.push_back(new Vector4D(55, 65, 0));	//4
		tailFin.vertex.push_back(new Vector4D(20, 0, 0));	//5
		tailFin.vertex.push_back(new Vector4D(28, 55, 0));	//6
		tailFin.vertex.push_back(new Vector4D(12, 0, 0));	//7
		tailFin.vertex.push_back(new Vector4D(5, 25, 0));	//8
		tailFin.vertex.push_back(new Vector4D(0, 0, 0));	//9

		tailFin.vertex.push_back(new Vector4D(35, 0, 5));	//10
		tailFin.vertex.push_back(new Vector4D(65, 20, 3.46));//11
		tailFin.vertex.push_back(new Vector4D(73, 57, 0.61));//12
		tailFin.vertex.push_back(new Vector4D(26, 0, 5));	//13
		tailFin.vertex.push_back(new Vector4D(55, 65, 0));	//14
		tailFin.vertex.push_back(new Vector4D(20, 0, 5));	//15
		tailFin.vertex.push_back(new Vector4D(28, 55, 0.76));//16
		tailFin.vertex.push_back(new Vector4D(12, 0, 5));	//17
		tailFin.vertex.push_back(new Vector4D(5, 25, 3.07));	//18
		tailFin.vertex.push_back(new Vector4D(0, 0, 5));	//19

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
		bodyFin.vertex.push_back(new Vector4D(0, -5, 0));		//0

		bodyFin.vertex.push_back(new Vector4D(40, -35, 0));		//1
		{
			bodyFin.vertex.push_back(new Vector4D(40, -31, 0));		//2
			bodyFin.vertex.push_back(new Vector4D(42, -27, 0));		//1
		}
		bodyFin.vertex.push_back(new Vector4D(45, -25, 0));		//3
		{
			bodyFin.vertex.push_back(new Vector4D(45, -21, 0));		//4
			bodyFin.vertex.push_back(new Vector4D(47, -17, 0));		//1
		}
		bodyFin.vertex.push_back(new Vector4D(50, -15, 0));		//5
		{
			bodyFin.vertex.push_back(new Vector4D(51, -8, 0));		//6
			bodyFin.vertex.push_back(new Vector4D(55, -3, 0));		//6
		}
		bodyFin.vertex.push_back(new Vector4D(60, 0, 0));		//7

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
		wing.vertex.push_back(new Vector4D(53, 0));		//0
		wing.vertex.push_back(new Vector4D(-35, 0));	//1
		wing.vertex.push_back(new Vector4D(45, -20));	//2
		wing.vertex.push_back(new Vector4D(-20, -30));	//3
		wing.vertex.push_back(new Vector4D(45, -40));	//4
		wing.vertex.push_back(new Vector4D(-25, -50));	//5
		wing.vertex.push_back(new Vector4D(58, -67));	//6
		wing.vertex.push_back(new Vector4D(0, -80));	//7
		wing.vertex.push_back(new Vector4D(52, -80));	//8
		wing.vertex.push_back(new Vector4D(52, -90));	//9
		wing.vertex.push_back(new Vector4D(3, -107));	//10
		wing.vertex.push_back(new Vector4D(60, -105));	//11
		wing.vertex.push_back(new Vector4D(50, -120));	//12
		wing.vertex.push_back(new Vector4D(0, -135));	//13
		wing.vertex.push_back(new Vector4D(50, -135));	//14
		wing.vertex.push_back(new Vector4D(60, -153));	//15
		wing.vertex.push_back(new Vector4D(50, -160));	//16
		wing.vertex.push_back(new Vector4D(-3, -158));	//17
		wing.vertex.push_back(new Vector4D(47, -172));	//18
		wing.vertex.push_back(new Vector4D(53, -185));	//19
		wing.vertex.push_back(new Vector4D(40, -190));	//20
		wing.vertex.push_back(new Vector4D(32, -200));	//21
		wing.vertex.push_back(new Vector4D(-18, -180));	//22
		wing.vertex.push_back(new Vector4D(30, -215));	//23
		wing.vertex.push_back(new Vector4D(33, -230));	//24
		wing.vertex.push_back(new Vector4D(16, -235));	//25
		wing.vertex.push_back(new Vector4D(5, -245));	//26
		wing.vertex.push_back(new Vector4D(-2, -265));	//27
		wing.vertex.push_back(new Vector4D(-40, -198));	//28
		wing.vertex.push_back(new Vector4D(-45, -110));	//29

		//Interpolate value of z with curve (maybe spline or beizer)
		//according to value of |y|
		for (int i = 0; i < wing.vertex.size(); i++)
		{
			wing.vertex[i]->setZ(0);	//interpolated value
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

Object BasicShape::createTower(float h)
{
	Object tower("tower");
	{
		tower.vertex.push_back(new Vector4D(10,0,0));   //0
		tower.vertex.push_back(new Vector4D(8,0,6));	//1
		tower.vertex.push_back(new Vector4D(3,0,10));   //2
		tower.vertex.push_back(new Vector4D(-3,0,10));	//3
		tower.vertex.push_back(new Vector4D(-8,0,6));	//4
		tower.vertex.push_back(new Vector4D(-10,0,0));	//5
		tower.vertex.push_back(new Vector4D(-8,0,-6));	//6
		tower.vertex.push_back(new Vector4D(-3,0,-10));	//7
		tower.vertex.push_back(new Vector4D(3,0,-10));	//8
		tower.vertex.push_back(new Vector4D(8,0,-6));	//9

		tower.vertex.push_back(new Vector4D(7,h,0));	//10
		tower.vertex.push_back(new Vector4D(6,h,4));	//11
		tower.vertex.push_back(new Vector4D(2,h,7));	//12
		tower.vertex.push_back(new Vector4D(-2,h,7));	//13
		tower.vertex.push_back(new Vector4D(-6,h,4));	//14
		tower.vertex.push_back(new Vector4D(-7,h,0));	//15
		tower.vertex.push_back(new Vector4D(-6,h,-4));	//16
		tower.vertex.push_back(new Vector4D(-2,h,-7));	//17
		tower.vertex.push_back(new Vector4D(2,h,-7));	//18
		tower.vertex.push_back(new Vector4D(6,h,-4));	//19

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
		hemiSphere.vertex.push_back(new Vector4D(7,35-org,0));
		hemiSphere.vertex.push_back(new Vector4D(6,35-org,4));
		hemiSphere.vertex.push_back(new Vector4D(2,35-org,7));
		hemiSphere.vertex.push_back(new Vector4D(-2,35-org,7));
		hemiSphere.vertex.push_back(new Vector4D(-6,35-org,4));
		hemiSphere.vertex.push_back(new Vector4D(-7,35-org,0));
		hemiSphere.vertex.push_back(new Vector4D(-6,35-org,-4));
		hemiSphere.vertex.push_back(new Vector4D(-2,35-org,-7));
		hemiSphere.vertex.push_back(new Vector4D(2,35-org,-7));
		hemiSphere.vertex.push_back(new Vector4D(6,35-org,-4));

		hemiSphere.vertex.push_back(new Vector4D(6,38.6-org,0));
		hemiSphere.vertex.push_back(new Vector4D(5,38.6-org,4));
		hemiSphere.vertex.push_back(new Vector4D(2,38.6-org,6));
		hemiSphere.vertex.push_back(new Vector4D(-2,38.6-org,6));
		hemiSphere.vertex.push_back(new Vector4D(-5,38.6-org,4));
		hemiSphere.vertex.push_back(new Vector4D(-6,38.6-org,0));
		hemiSphere.vertex.push_back(new Vector4D(-5,38.6-org,-4));
		hemiSphere.vertex.push_back(new Vector4D(-2,38.6-org,-6));
		hemiSphere.vertex.push_back(new Vector4D(2,38.6-org,-6));
		hemiSphere.vertex.push_back(new Vector4D(5,38.6-org,-4));

		hemiSphere.vertex.push_back(new  Vector4D(5,39.9-org,0));
		hemiSphere.vertex.push_back(new  Vector4D(4,39.9-org,3));
		hemiSphere.vertex.push_back(new  Vector4D(2,39.9-org,5));
		hemiSphere.vertex.push_back(new  Vector4D(-2,39.9-org,5));
		hemiSphere.vertex.push_back(new  Vector4D(-4,39.9-org,3));
		hemiSphere.vertex.push_back(new  Vector4D(-5,39.9-org,0));
		hemiSphere.vertex.push_back(new  Vector4D(-4,39.9-org,-3));
		hemiSphere.vertex.push_back(new  Vector4D(-2,39.9-org,-5));
		hemiSphere.vertex.push_back(new  Vector4D(2,39.9-org,-5));
		hemiSphere.vertex.push_back(new  Vector4D(4,39.9-org,-3));

		hemiSphere.vertex.push_back(new  Vector4D(4,40.7-org,0));
		hemiSphere.vertex.push_back(new  Vector4D(3,40.7-org,2));
		hemiSphere.vertex.push_back(new  Vector4D(1,40.7-org,4));
		hemiSphere.vertex.push_back(new  Vector4D(-1,40.7-org,4));
		hemiSphere.vertex.push_back(new  Vector4D(-3,40.7-org,2));
		hemiSphere.vertex.push_back(new  Vector4D(-4,40.7-org,0));
		hemiSphere.vertex.push_back(new  Vector4D(-3,40.7-org,-2));
		hemiSphere.vertex.push_back(new  Vector4D(-1,40.7-org,-4));
		hemiSphere.vertex.push_back(new  Vector4D(1,40.7-org,-4));
		hemiSphere.vertex.push_back(new  Vector4D(3,40.7-org,-2));

		hemiSphere.vertex.push_back(new  Vector4D(3,41.3-org,0));
		hemiSphere.vertex.push_back(new  Vector4D(2,41.3-org,2));
		hemiSphere.vertex.push_back(new  Vector4D(1,41.3-org,3));
		hemiSphere.vertex.push_back(new  Vector4D(-1,41.3-org,3));
		hemiSphere.vertex.push_back(new  Vector4D(-2,41.3-org,2));
		hemiSphere.vertex.push_back(new  Vector4D(-3,41.3-org,0));
		hemiSphere.vertex.push_back(new  Vector4D(-2,41.3-org,-2));
		hemiSphere.vertex.push_back(new  Vector4D(-1,41.3-org,-3));
		hemiSphere.vertex.push_back(new  Vector4D(1,41.3-org,-3));
		hemiSphere.vertex.push_back(new  Vector4D(2,41.3-org,-2));

		hemiSphere.vertex.push_back(new  Vector4D(2,41.7-org,0));
		hemiSphere.vertex.push_back(new  Vector4D(1.7,41.7-org,1.2));
		hemiSphere.vertex.push_back(new  Vector4D(.6,41.7-org,2));
		hemiSphere.vertex.push_back(new  Vector4D(-.6,41.7-org,2));
		hemiSphere.vertex.push_back(new  Vector4D(-1.7,41.7-org,1.2));
		hemiSphere.vertex.push_back(new  Vector4D(-2,41.7-org,0));
		hemiSphere.vertex.push_back(new  Vector4D(-1.7,41.7-org,-1.2));
		hemiSphere.vertex.push_back(new  Vector4D(-0.6,41.7-org,-2));
		hemiSphere.vertex.push_back(new  Vector4D(0.6,41.7-org,-2));
		hemiSphere.vertex.push_back(new  Vector4D(1.7,41.7-org,-1.2));

		/*	hemiSphere.vertex.push_back(new  Vector4D(1,41.9,0));
		hemiSphere.vertex.push_back(new  Vector4D(.8,41.9,.6));
		hemiSphere.vertex.push_back(new  Vector4D(.3,41.9,1));
		hemiSphere.vertex.push_back(new  Vector4D(-.3,41.9,1));
		hemiSphere.vertex.push_back(new  Vector4D(-.8,41.9,.6));
		hemiSphere.vertex.push_back(new  Vector4D(-1,41.9,0));
		hemiSphere.vertex.push_back(new  Vector4D(-.8,41.9,-.6));
		hemiSphere.vertex.push_back(new  Vector4D(-.3,41.9,-1));
		hemiSphere.vertex.push_back(new  Vector4D(.3,41.9,-1));
		hemiSphere.vertex.push_back(new  Vector4D(.8,41.9,-.6));*/

		hemiSphere.vertex.push_back(new  Vector4D(0,42-org,0));

		hemiSphere.face.push_back(new Face(0,10,1));
		hemiSphere.face.push_back(new Face(1,11,2));
		hemiSphere.face.push_back(new Face(2,12,3));
		hemiSphere.face.push_back(new Face(3,13,4));
		hemiSphere.face.push_back(new Face(4,14,5));
		hemiSphere.face.push_back(new Face(5,15,6));
		hemiSphere.face.push_back(new Face(6,16,7));
		hemiSphere.face.push_back(new Face(7,17,8));
		hemiSphere.face.push_back(new Face(8,18,9));
		hemiSphere.face.push_back(new Face(9,19,0));

		hemiSphere.face.push_back(new Face(10,0,11));
		hemiSphere.face.push_back(new Face(11,1,12));
		hemiSphere.face.push_back(new Face(12,2,13));
		hemiSphere.face.push_back(new Face(13,3,14));
		hemiSphere.face.push_back(new Face(14,4,15));
		hemiSphere.face.push_back(new Face(15,5,16));
		hemiSphere.face.push_back(new Face(16,6,17));
		hemiSphere.face.push_back(new Face(17,7,18));
		hemiSphere.face.push_back(new Face(18,8,19));
		hemiSphere.face.push_back(new Face(19,9,10));

		hemiSphere.face.push_back(new Face(20,10,21));
		hemiSphere.face.push_back(new Face(21,11,22));
		hemiSphere.face.push_back(new Face(22,12,23));
		hemiSphere.face.push_back(new Face(23,13,24));
		hemiSphere.face.push_back(new Face(24,14,25));
		hemiSphere.face.push_back(new Face(25,15,26));
		hemiSphere.face.push_back(new Face(26,16,27));
		hemiSphere.face.push_back(new Face(27,17,28));
		hemiSphere.face.push_back(new Face(28,18,29));
		hemiSphere.face.push_back(new Face(29,19,20));

		hemiSphere.face.push_back(new Face(30,20,31));
		hemiSphere.face.push_back(new Face(31,21,32));
		hemiSphere.face.push_back(new Face(32,22,33));
		hemiSphere.face.push_back(new Face(33,23,34));
		hemiSphere.face.push_back(new Face(34,24,35));
		hemiSphere.face.push_back(new Face(35,25,36));
		hemiSphere.face.push_back(new Face(36,26,37));
		hemiSphere.face.push_back(new Face(37,27,38));
		hemiSphere.face.push_back(new Face(38,28,39));
		hemiSphere.face.push_back(new Face(39,29,30));

		hemiSphere.face.push_back(new Face(40,30,41));
		hemiSphere.face.push_back(new Face(41,41,42));
		hemiSphere.face.push_back(new Face(42,32,43));
		hemiSphere.face.push_back(new Face(43,33,44));
		hemiSphere.face.push_back(new Face(44,34,45));
		hemiSphere.face.push_back(new Face(45,35,46));
		hemiSphere.face.push_back(new Face(46,36,47));
		hemiSphere.face.push_back(new Face(47,37,48));
		hemiSphere.face.push_back(new Face(48,38,49));
		hemiSphere.face.push_back(new Face(49,39,40));



		hemiSphere.face.push_back(new Face(50,40,51));
		hemiSphere.face.push_back(new Face(51,41,52));
		hemiSphere.face.push_back(new Face(52,42,53));
		hemiSphere.face.push_back(new Face(53,43,54));
		hemiSphere.face.push_back(new Face(54,44,55));
		hemiSphere.face.push_back(new Face(55,45,56));
		hemiSphere.face.push_back(new Face(56,46,57));
		hemiSphere.face.push_back(new Face(57,47,58));
		hemiSphere.face.push_back(new Face(58,48,59));
		hemiSphere.face.push_back(new Face(59,49,50));

		hemiSphere.face.push_back(new Face(50,60,51));
		hemiSphere.face.push_back(new Face(51,60,52));
		hemiSphere.face.push_back(new Face(52,60,53));
		hemiSphere.face.push_back(new Face(53,60,54));
		hemiSphere.face.push_back(new Face(54,60,55));
		hemiSphere.face.push_back(new Face(55,60,56));
		hemiSphere.face.push_back(new Face(56,60,57));
		hemiSphere.face.push_back(new Face(57,60,58));
		hemiSphere.face.push_back(new Face(58,60,59));
		hemiSphere.face.push_back(new Face(59,60,50));

		/*	hemiSphere.face.push_back(new Face(60,50,61));
		hemiSphere.face.push_back(new Face(61,51,62));
		hemiSphere.face.push_back(new Face(62,52,63));
		hemiSphere.face.push_back(new Face(63,53,64));
		hemiSphere.face.push_back(new Face(64,54,65));
		hemiSphere.face.push_back(new Face(65,55,66));
		hemiSphere.face.push_back(new Face(66,56,67));
		hemiSphere.face.push_back(new Face(67,57,68));
		hemiSphere.face.push_back(new Face(68,58,69));
		hemiSphere.face.push_back(new Face(69,59,60));

		hemiSphere.face.push_back(new Face(60,70,61));
		hemiSphere.face.push_back(new Face(61,70,62));
		hemiSphere.face.push_back(new Face(62,70,63));
		hemiSphere.face.push_back(new Face(63,70,64));
		hemiSphere.face.push_back(new Face(64,70,65));
		hemiSphere.face.push_back(new Face(65,70,66));
		hemiSphere.face.push_back(new Face(66,70,67));
		hemiSphere.face.push_back(new Face(67,70,68));
		hemiSphere.face.push_back(new Face(68,70,69));
		hemiSphere.face.push_back(new Face(69,70,60));
		*/
	}
	return hemiSphere;
}

Object BasicShape::createTorus()
{
	Object torus("torus");
	{
		torus.vertex.push_back(new Vector4D(8,2,0));
		torus.vertex.push_back(new Vector4D(6,2,5));
		torus.vertex.push_back(new Vector4D(2,2,8));
		torus.vertex.push_back(new Vector4D(-2,2,8));
		torus.vertex.push_back(new Vector4D(-6,2,5));
		torus.vertex.push_back(new Vector4D(-8,2,0));
		torus.vertex.push_back(new Vector4D(-6,2,-5));
		torus.vertex.push_back(new Vector4D(-2,2,-8));
		torus.vertex.push_back(new Vector4D(2,2,-8));
		torus.vertex.push_back(new Vector4D(6,2,-5));

		torus.vertex.push_back(new Vector4D(8.3,1.8,0));
		torus.vertex.push_back(new Vector4D(6.7,1.8,4.9));
		torus.vertex.push_back(new Vector4D(2.6,1.8,7.9));
		torus.vertex.push_back(new Vector4D(-2.6,1.8,7.9));
		torus.vertex.push_back(new Vector4D(-6.7,1.8,4.9));
		torus.vertex.push_back(new Vector4D(-8.3,1.8,0));
		torus.vertex.push_back(new Vector4D(-6.7,1.8,-4.9));
		torus.vertex.push_back(new Vector4D(-2.6,1.8,-7.9));
		torus.vertex.push_back(new Vector4D(2.8,1.8,-7.9));
		torus.vertex.push_back(new Vector4D(6.7,1.8,-4.9));


		torus.vertex.push_back(new Vector4D(9,1,0));
		torus.vertex.push_back(new Vector4D(7,1,5));
		torus.vertex.push_back(new Vector4D(3,1,9));
		torus.vertex.push_back(new Vector4D(-3,1,9));
		torus.vertex.push_back(new Vector4D(-7,1,5));
		torus.vertex.push_back(new Vector4D(-9,1,0));
		torus.vertex.push_back(new Vector4D(-7,1,-5));
		torus.vertex.push_back(new Vector4D(-3,1,-9));
		torus.vertex.push_back(new Vector4D(3,1,-9));
		torus.vertex.push_back(new Vector4D(7,1,-5));

		torus.vertex.push_back(new Vector4D(8.3,.3,0));
		torus.vertex.push_back(new Vector4D(6.7,.3,4.9));
		torus.vertex.push_back(new Vector4D(2.6,.3,7.9));
		torus.vertex.push_back(new Vector4D(-2.6,.3,7.9));
		torus.vertex.push_back(new Vector4D(-6.7,.3,4.9));
		torus.vertex.push_back(new Vector4D(-8.3,.3,0));
		torus.vertex.push_back(new Vector4D(-6.7,.3,-4.9));
		torus.vertex.push_back(new Vector4D(-2.6,.3,-7.9));
		torus.vertex.push_back(new Vector4D(2.8,.3,-7.9));
		torus.vertex.push_back(new Vector4D(6.7,.3,-4.9));


		torus.vertex.push_back(new Vector4D(8,0,0));
		torus.vertex.push_back(new Vector4D(6,0,5));
		torus.vertex.push_back(new Vector4D(2,0,8));
		torus.vertex.push_back(new Vector4D(-2,0,8));
		torus.vertex.push_back(new Vector4D(-6,0,5));
		torus.vertex.push_back(new Vector4D(-8,0,0));
		torus.vertex.push_back(new Vector4D(-6,0,-5));
		torus.vertex.push_back(new Vector4D(-2,0,-8));
		torus.vertex.push_back(new Vector4D(2,0,-8));
		torus.vertex.push_back(new Vector4D(6,0,-5));

		/*	torus.vertex.push_back(new Vector4D(7,1,0));
		torus.vertex.push_back(new Vector4D(6,1,4));
		torus.vertex.push_back(new Vector4D(2,1,7));
		torus.vertex.push_back(new Vector4D(-2,1,7));
		torus.vertex.push_back(new Vector4D(-6,1,4));
		torus.vertex.push_back(new Vector4D(-7,1,0));
		torus.vertex.push_back(new Vector4D(-6,1,-4));
		torus.vertex.push_back(new Vector4D(-2,1,-7));
		torus.vertex.push_back(new Vector4D(2,1,-7));
		torus.vertex.push_back(new Vector4D(6,1,4));
		*/


		torus.face.push_back(new Face(0,10,1));
		torus.face.push_back(new Face(1,11,2));
		torus.face.push_back(new Face(2,12,3));
		torus.face.push_back(new Face(3,13,4));
		torus.face.push_back(new Face(4,14,5));
		torus.face.push_back(new Face(5,15,6));
		torus.face.push_back(new Face(6,16,7));
		torus.face.push_back(new Face(7,17,8));
		torus.face.push_back(new Face(8,18,9));
		torus.face.push_back(new Face(9,19,0));

		torus.face.push_back(new Face(10,20,11));
		torus.face.push_back(new Face(11,21,12));
		torus.face.push_back(new Face(12,22,13));
		torus.face.push_back(new Face(13,23,14));
		torus.face.push_back(new Face(14,24,15));
		torus.face.push_back(new Face(15,25,16));
		torus.face.push_back(new Face(16,26,17));
		torus.face.push_back(new Face(17,27,18));
		torus.face.push_back(new Face(18,28,19));
		torus.face.push_back(new Face(19,29,10));

		torus.face.push_back(new Face(20,10,21));
		torus.face.push_back(new Face(21,11,22));
		torus.face.push_back(new Face(22,12,23));
		torus.face.push_back(new Face(23,13,24));
		torus.face.push_back(new Face(24,14,25));
		torus.face.push_back(new Face(25,15,26));
		torus.face.push_back(new Face(26,16,27));
		torus.face.push_back(new Face(27,17,28));
		torus.face.push_back(new Face(28,18,29));
		torus.face.push_back(new Face(29,19,20));

		torus.face.push_back(new Face(30,20,31));
		torus.face.push_back(new Face(31,21,32));
		torus.face.push_back(new Face(32,22,33));
		torus.face.push_back(new Face(33,23,34));
		torus.face.push_back(new Face(34,24,35));
		torus.face.push_back(new Face(35,25,36));
		torus.face.push_back(new Face(36,26,37));
		torus.face.push_back(new Face(37,27,38));
		torus.face.push_back(new Face(38,28,39));
		torus.face.push_back(new Face(39,29,30));


		torus.face.push_back(new Face(10,0,11));
		torus.face.push_back(new Face(11,1,12));
		torus.face.push_back(new Face(12,2,13));
		torus.face.push_back(new Face(13,3,14));
		torus.face.push_back(new Face(14,4,15));
		torus.face.push_back(new Face(15,5,16));
		torus.face.push_back(new Face(16,6,17));
		torus.face.push_back(new Face(17,7,18));
		torus.face.push_back(new Face(18,8,19));
		torus.face.push_back(new Face(19,9,10));

		torus.face.push_back(new Face(20,10,21));
		torus.face.push_back(new Face(21,11,22));
		torus.face.push_back(new Face(22,12,23));
		torus.face.push_back(new Face(23,13,24));
		torus.face.push_back(new Face(24,14,25));
		torus.face.push_back(new Face(25,15,26));
		torus.face.push_back(new Face(26,16,27));
		torus.face.push_back(new Face(27,17,28));
		torus.face.push_back(new Face(28,18,29));
		torus.face.push_back(new Face(29,19,20));
	}
	return torus;
}