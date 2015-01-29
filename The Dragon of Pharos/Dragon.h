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

	Object cube;
	float angleX, angleY, angleZ;
	float sX, sY, sZ;

	std::vector<Object> objects;

	Matrix4 viewMatrix, projectionMatrix;
	Matrix4 transformMatrix;


	//to know which object to move (selects from vector objects)
	int selected;

	bool released;

	//step size for transformations
	float translateStep, rotateStep, scaleStep;

	//std::vector<float> points;
	//std::vector<>
};

