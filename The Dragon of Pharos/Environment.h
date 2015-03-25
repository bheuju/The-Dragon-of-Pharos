/********************** Dragon of Pharos **********************
Environment Class
- consists all about environment

--------------------------------------------------------------

**************************************************************/

#pragma once
#include "Graphics.h"
#include "Object.h"
#include "Matrix4.h"
#include "Vector2D.h"
#include "BasicShape.h"

class Environment
{
public:
	Environment();
	~Environment() {}

	void init();

	void handleInput();
	void update();
	void render();

private:
	bool wireFrame;
	bool showWire;
	bool highLight;

	float angleX, angleY, angleZ;
	float sX, sY, sZ;

	std::vector<Object> objects;

	Matrix4 viewMatrix, projectionMatrix;
	Matrix4 transformMatrix;

	//Camera rotation specification
	Vector3D cameraRot;
	float cameraStepX, cameraStepY, cameraStepZ;

	BasicShape shape;

	//to know which object to move (selects from vector objects)
	int selected;

	bool released;

	//step size for transformations
	float translateStep, rotateStep, scaleStep;

	//std::vector<float> points;
	//std::vector<>
	Vector4D p0, p1, p2;

	Vector2D startPos;
	Vector2D endPos;

	std::vector<Vector2D> lines;
};

