/********************** Dragon of Pharos **********************
Dragon Class
- consists all about dragon
- model space of each parts
- wireframe
--------------------------------------------------------------

**************************************************************/

#pragma once
#include "Graphics.h"
#include "Object.h"
#include "Matrix4.h"

class Dragon
{
public:
	Dragon();
	~Dragon() {}

	void init();

	void handleInput();
	void update();
	void render();

private:
	Graphics gph;

	bool wireFrame;

	int x, y;
	int step;

	Object cube;
	float angleX, angleY, angleZ;
	float sX, sY, sZ;

	std::vector<Object> objects;

	Matrix4 viewMatrix, projectionMatrix;
	Matrix4 transformMatrix;

	//std::vector<float> points;
	//std::vector<>
};

