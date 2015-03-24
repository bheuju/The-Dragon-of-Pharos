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
#include <vector>
#include "Vector3D.h"
#include "Vector4D.h"
#include "Object.h"

class Graphics
{
public:
	static Graphics* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new Graphics();
		}
		return pInstance;
	}
	~Graphics() {}

	void drawPixel(float x, float y, float z, Vector3D color = Vector3D(255, 0, 0));
	void putPixel(float x, float y, float z, Vector3D color = Vector3D(255, 0, 0));
	void drawLine(int x1, int y1, int x2, int y2, Vector3D color = Vector3D(255, 0, 0), float lineZ = 1);

	//void processScanLine(int y, Vector4D pa, Vector3D norma, Vector4D pb, Vector3D normb, Vector4D pc, Vector3D normc, Vector4D pd, Vector3D normd, Vector3D color);
	void processScanLine(int y, Vertex va, Vertex vb, Vertex vc, Vertex vd, Vector3D color);
	Vector3D interpolateNormal(Vector3D norma, Vector3D normb, float grad);
	//void fillTriangle(Vector4D p1, Vector4D p2, Vector4D p3, Vector4D p1wc, Vector4D p2wc, Vector4D p3wc, Vector3D norm1, Vector3D norm2, Vector3D norm3, Vector3D color);
	void fillTriangle(Vertex p1, Vertex p2, Vertex p3, Vector3D color);

	void clearBuffer();
	void render();

	float zBuffer[801][601];

	std::vector<Vector4D> frameBuffer;
	std::vector<Vector3D> colorBuffer;

	//Vector4D frameBuffer[801][601];
	//Vector3D colorBuffer[801][601];

private:
	Graphics();
	static Graphics* pInstance;
};

