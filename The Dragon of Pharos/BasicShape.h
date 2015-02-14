#pragma once
#include "Object.h"

class BasicShape
{
public:
	BasicShape();
	~BasicShape(){}

	Object createCube();
	Object createOctahedron();
	Object createTailFin();
};

