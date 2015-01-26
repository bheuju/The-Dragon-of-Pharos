/************************** Graphics *************************
Graphics Class
- handle graphics
- line drawing
- pixel plotting

- can switch between OPENGL and SDL rendering 
		by defining 'mode' in DoP
		default: OPENGL
--------------------------------------------------------------
Singleton class
**************************************************************/

#pragma once
#include "Vector3D.h"
#include "Vector4D.h"

class Graphics
{
public:
	Graphics();
	~Graphics() {}

	void drawPixel(float x, float y, Vector3D color = Vector3D(255, 0, 0));
	void drawLine(int x1, int y1, int x2, int y2, Vector3D color = Vector3D(255, 0, 0));

	void processScanLine(int y, Vector4D pa, Vector4D pb, Vector4D pc, Vector4D pd, Vector3D color);
	void fillTriangle(Vector4D p1, Vector4D p2, Vector4D p3, Vector3D color);

};

