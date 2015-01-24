#include "Dragon.h"
#include "InputHandler.h"
#include "Camera.h"

Dragon::Dragon()
{
	step = 10;
	x = y = 10;
	angle = 0;
}

void Dragon::init()
{
	//Set View Matrix
	Camera::Instance()->setCameraPos(0, 0, 0);
	Camera::Instance()->setCameraTarget(100, 100, 100);
	Camera::Instance()->setUpVector(0, 1, 0);
	viewMatrix = Camera::Instance()->getViewMatrix();

	//Set Projection Matrix
	projectionMatrix = Matrix4().setProjectionMatrix(45, 4.0/3.0, 0, 100);

	/** Initialize object: cube */
	//===========================/
	cube = Object("cube", 8, 12);
	cube.vertex.push_back(new Vector4D(-10, 10, 10));
	cube.vertex.push_back(new Vector4D(-10, -10, 10));
	cube.vertex.push_back(new Vector4D(10, -10, 10));
	cube.vertex.push_back(new Vector4D(10, 10, 10));
	cube.vertex.push_back(new Vector4D(-10, 10, -10));
	cube.vertex.push_back(new Vector4D(-10, -10, -10));
	cube.vertex.push_back(new Vector4D(10, -10, -10));
	cube.vertex.push_back(new Vector4D(10, 10, -10));

	cube.face.push_back(new Face(0, 1, 2, 3));
	cube.face.push_back(new Face(4, 5, 6, 7));
	cube.face.push_back(new Face(0, 4, 5, 1));
	cube.face.push_back(new Face(3, 2, 6, 7));
	cube.face.push_back(new Face(0, 3, 7, 4));
	cube.face.push_back(new Face(2, 1, 5, 6));

	cube.translation.setTranslationMatrix(200, 200, 200);
	cube.rotation.setRotationX(0);
	cube.scale.setScaleMatrix(2, 2, 2);

	//Push initialized objects
	objects.push_back(cube);

	/*
	displayMatrix(cube.modelMatrix, "Model Matrix");
	displayMatrix(viewMatrix, "View Matrix");
	displayMatrix(projectionMatrix, "Projection Matrix");
	*/
}

void Dragon::handleInput()
{

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		x -= step;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		x += step;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		y -= step;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		y += step;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_R))
	{
		angle += 5;
	}
	/* Follow mouse
	x = InputHandler::Instance()->getMousePosition()->getX();
	y = InputHandler::Instance()->getMousePosition()->getY();
	*/
}

void Dragon::update()
{
	//objects[0].rotation.setRotationX(angle);
	objects[0].rotation.setRotationY(angle);
	//objects[0].rotation.setRotationZ(angle);
}

void Dragon::render()
{
	//for each object
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i].modelMatrix = Matrix4().setModelMatrix(objects[i].translation, objects[i].rotation, objects[i].scale);
		transformMatrix = projectionMatrix * viewMatrix * objects[i].modelMatrix;
		//transformMatrix = viewMatrix * objects[i].modelMatrix;

		//displayMatrix(objects[i].modelMatrix);
		//displayMatrix(transformMatrix, "Transform");

		//for each vertex in the object
		for (int j = 0; j < objects[i].vertex.size(); j++)
		{
			Vector4D point = transformMatrix * *objects[i].vertex[j];
			int x0 = point.getX();
			int y0 = point.getY();
			std::cout<<"Point "<<j<<": "<<x0<<" "<<y0<<std::endl;
			gph.drawPixel(x0, y0);
		}
		//for each face of the object
		for (int k = 0; k < objects[i].face.size(); k++)
		{
			//used quad as basic shape
			int v0 = objects[i].face[k]->v0;
			int v1 = objects[i].face[k]->v1;
			int v2 = objects[i].face[k]->v2;
			int v3 = objects[i].face[k]->v3;

			Vector4D point0 = transformMatrix * *objects[i].vertex[v0];
			Vector4D point1 = transformMatrix * *objects[i].vertex[v1];
			Vector4D point2 = transformMatrix * *objects[i].vertex[v2];
			Vector4D point3 = transformMatrix * *objects[i].vertex[v3];

			//draw 4 lines of the quad
			gph.drawLine(point0.getX(), point0.getY(), point1.getX(), point1.getY());
			gph.drawLine(point1.getX(), point1.getY(), point2.getX(), point2.getY());
			gph.drawLine(point2.getX(), point2.getY(), point3.getX(), point3.getY());
			gph.drawLine(point3.getX(), point3.getY(), point0.getX(), point0.getY());
		}
	}

	//gph.drawLine(400, 300, x, y);
	//gph.drawPixel(91, 39);
	/*
	for (int i = 0; i < points.size(); i++)
	{
	int x0 = points[i].getX();
	int y0 = points[i].getY();
	std::cout<<"Point "<<i<<": "<<x0<<" "<<y0<<std::endl;
	gph.drawPixel(x0, y0);
	}
	*/
	//gph.drawPixel(50, 50);
}