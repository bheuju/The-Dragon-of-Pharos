/************************ Basic Shapes ***********************
BasicShape Class
- consists predefined standard objects
- objects consists of:
* vertices
* faces
* face normals (TODO)
- smallest possible size of object
- model coordinates of each object
- objects creating functions have prefix "create[objectName]"
--------------------------------------------------------------

**************************************************************/

#pragma once
#include "Object.h"

class BasicShape
{
public:
	BasicShape();
	~BasicShape(){}

	//General
	Object createCube();
	Object createOctahedron();
	Object createCuboid();

	//Dragon
	Object createDragon();
	Object createTailFin();
	Object createBodyFin();
	Object createWing();
	Object createHead();

	//Pharos
	Object createTower(float h);
	Object createHemiSphere();
	Object createTorus();
};

