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

Object BasicShape::createTower()
{
	Object tower ("tower");
	{
		tower.vertex.push_back(new Vector4D(10,0,0));   //0
		tower.vertex.push_back(new Vector4D(8,0,6));        //1
		tower.vertex.push_back(new Vector4D(3,0,10));   //2
		tower.vertex.push_back(new Vector4D(-3,0,10));//3
		tower.vertex.push_back(new Vector4D(-8,0,6));//4
		tower.vertex.push_back(new Vector4D(-10,0,0));//5
		tower.vertex.push_back(new Vector4D(-8,0,-6));//6
		tower.vertex.push_back(new Vector4D(-3,0,-10));//7
		tower.vertex.push_back(new Vector4D(3,0,-10));//8
		tower.vertex.push_back(new Vector4D(8,0,-6));//9

		tower.vertex.push_back(new Vector4D(7,35,0));//10
		tower.vertex.push_back(new Vector4D(6,35,4));//11
		tower.vertex.push_back(new Vector4D(2,35,7));//12
		tower.vertex.push_back(new Vector4D(-2,35,7));//13
		tower.vertex.push_back(new Vector4D(-6,35,4));//14
		tower.vertex.push_back(new Vector4D(-7,35,0));//15
		tower.vertex.push_back(new Vector4D(-6,35,-4));//16
		tower.vertex.push_back(new Vector4D(-2,35,-7));//17
		tower.vertex.push_back(new Vector4D(2,35,-7));//18
		tower.vertex.push_back(new Vector4D(6,35,-4));//19

		tower.face.push_back(new Face(0,10,1));
		tower.face.push_back(new Face(1,11,2));
		tower.face.push_back(new Face(2,12,3));
		tower.face.push_back(new Face(3,13,4));
		tower.face.push_back(new Face(4,14,5));

		tower.face.push_back(new Face(10,0,11));
		tower.face.push_back(new Face(11,1,12));
		tower.face.push_back(new Face(12,2,13));
		tower.face.push_back(new Face(13,3,14));
		tower.face.push_back(new Face(14,4,15));

		tower.face.push_back(new Face(5,15,6));
		tower.face.push_back(new Face(6,16,7));
		tower.face.push_back(new Face(7,17,8));
		tower.face.push_back(new Face(8,18,9));
		tower.face.push_back(new Face(9,19,0));

		tower.face.push_back(new Face(15,5,16));
		tower.face.push_back(new Face(16,6,17));
		tower.face.push_back(new Face(17,7,18));
		tower.face.push_back(new Face(18,8,19));
		tower.face.push_back(new Face(19,9,10));
	}
	return tower;
}

Object BasicShape::createHemiSphere()
{
	Object hemiSphere("hemiSphere");
	{
		hemiSphere.vertex.push_back(new Vector4D(7,35,0));
		hemiSphere.vertex.push_back(new Vector4D(6,35,4));
		hemiSphere.vertex.push_back(new Vector4D(2,35,7));
		hemiSphere.vertex.push_back(new Vector4D(-2,35,7));
		hemiSphere.vertex.push_back(new Vector4D(-6,35,4));
		hemiSphere.vertex.push_back(new Vector4D(-7,35,0));
		hemiSphere.vertex.push_back(new Vector4D(-6,35,-4));
		hemiSphere.vertex.push_back(new Vector4D(-2,35,-7));
		hemiSphere.vertex.push_back(new Vector4D(2,35,-7));
		hemiSphere.vertex.push_back(new Vector4D(6,35,-4));

		hemiSphere.vertex.push_back(new Vector4D(6,38.6,0));
		hemiSphere.vertex.push_back(new Vector4D(5,38.6,4));
		hemiSphere.vertex.push_back(new Vector4D(2,38.6,6));
		hemiSphere.vertex.push_back(new Vector4D(-2,38.6,6));
		hemiSphere.vertex.push_back(new Vector4D(-5,38.6,4));
		hemiSphere.vertex.push_back(new Vector4D(-6,38.6,0));
		hemiSphere.vertex.push_back(new Vector4D(-5,38.6,-4));
		hemiSphere.vertex.push_back(new Vector4D(-2,38.6,-6));
		hemiSphere.vertex.push_back(new Vector4D(2,38.6,-6));
		hemiSphere.vertex.push_back(new Vector4D(5,38.6,-4));

		hemiSphere.vertex.push_back(new  Vector4D(5,39.9,0));
		hemiSphere.vertex.push_back(new  Vector4D(4,39.9,3));
		hemiSphere.vertex.push_back(new  Vector4D(2,39.9,5));
		hemiSphere.vertex.push_back(new  Vector4D(-2,39.9,5));
		hemiSphere.vertex.push_back(new  Vector4D(-4,39.9,3));
		hemiSphere.vertex.push_back(new  Vector4D(-5,39.9,0));
		hemiSphere.vertex.push_back(new  Vector4D(-4,39.9,-3));
		hemiSphere.vertex.push_back(new  Vector4D(-2,39.9,-5));
		hemiSphere.vertex.push_back(new  Vector4D(2,39.9,-5));
		hemiSphere.vertex.push_back(new  Vector4D(4,39.9,-3));

		hemiSphere.vertex.push_back(new  Vector4D(4,40.7,0));
		hemiSphere.vertex.push_back(new  Vector4D(3,40.7,2));
		hemiSphere.vertex.push_back(new  Vector4D(1,40.7,4));
		hemiSphere.vertex.push_back(new  Vector4D(-1,40.7,4));
		hemiSphere.vertex.push_back(new  Vector4D(-3,40.7,2));
		hemiSphere.vertex.push_back(new  Vector4D(-4,40.7,0));
		hemiSphere.vertex.push_back(new  Vector4D(-3,40.7,-2));
		hemiSphere.vertex.push_back(new  Vector4D(-1,40.7,-4));
		hemiSphere.vertex.push_back(new  Vector4D(1,40.7,-4));
		hemiSphere.vertex.push_back(new  Vector4D(3,40.7,-2));

		hemiSphere.vertex.push_back(new  Vector4D(3,41.3,0));
		hemiSphere.vertex.push_back(new  Vector4D(2,41.3,2));
		hemiSphere.vertex.push_back(new  Vector4D(1,41.3,3));
		hemiSphere.vertex.push_back(new  Vector4D(-1,41.3,3));
		hemiSphere.vertex.push_back(new  Vector4D(-2,41.3,2));
		hemiSphere.vertex.push_back(new  Vector4D(-3,41.3,0));
		hemiSphere.vertex.push_back(new  Vector4D(-2,41.3,-2));
		hemiSphere.vertex.push_back(new  Vector4D(-1,41.3,-3));
		hemiSphere.vertex.push_back(new  Vector4D(1,41.3,-3));
		hemiSphere.vertex.push_back(new  Vector4D(2,41.3,-2));

		hemiSphere.vertex.push_back(new  Vector4D(2,41.7,0));
		hemiSphere.vertex.push_back(new  Vector4D(1.7,41.7,1.2));
		hemiSphere.vertex.push_back(new  Vector4D(.6,41.7,2));
		hemiSphere.vertex.push_back(new  Vector4D(-.6,41.7,2));
		hemiSphere.vertex.push_back(new  Vector4D(-1.7,41.7,1.2));
		hemiSphere.vertex.push_back(new  Vector4D(-2,41.7,0));
		hemiSphere.vertex.push_back(new  Vector4D(-1.7,41.7,-1.2));
		hemiSphere.vertex.push_back(new  Vector4D(-.6,41.7,-2));
		hemiSphere.vertex.push_back(new  Vector4D(.6,41.7,-2));
		hemiSphere.vertex.push_back(new  Vector4D(1.7,41.7,-1.2));

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

		hemiSphere.vertex.push_back(new  Vector4D(0,42,0));

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