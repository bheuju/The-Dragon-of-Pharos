#include "Dragon.h"
#include "InputHandler.h"
#include "Camera.h"

Dragon::Dragon()
{
	wireFrame = false;
	step = 10;
	x = y = 10;
	angleX = angleY = angleZ = 0;
	sX = sY = sZ = 1;
}

void Dragon::init()
{
	//gph.setMode(SDL);

	//Set View Matrix
	Camera::Instance()->setCameraPos(0, 0, 1);
	Camera::Instance()->setCameraTarget(0, 0, 0);
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

	//Push initialized objects
	objects.push_back(cube);

	angleX = angleY = angleZ = 0;
	sX = sY = sZ = 2;

	/*
	displayMatrix(cube.modelMatrix, "Model Matrix");
	displayMatrix(viewMatrix, "View Matrix");
	displayMatrix(projectionMatrix, "Projection Matrix");
	*/
}

void Dragon::handleInput()
{
	/*
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
	*/

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F11))
	{
		if (wireFrame)
		{
			std::cout<<"Enabled rasterized model"<<std::endl;
			wireFrame = false;
		}
		else
		{
			std::cout<<"Enabled wireframe model"<<std::endl;
			wireFrame = true;
		}
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		angleX += 0.1;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{
		angleX -= 0.1;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		angleY -= 0.1;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		angleY += 0.1;
	}

	//std::cout<<InputHandler::Instance()->getWheelPosition()<<std::endl;
	//zoom function (scaling)
	if (InputHandler::Instance()->getWheelPosition() == -1)
	{
		sX -= 0.1;
		sY -= 0.1;
		sZ -= 0.1;
	}
	else if (InputHandler::Instance()->getWheelPosition() == 1)
	{
		if (sX > 0.1)
		{
			sX += 0.1;
			sY += 0.1;
			sZ += 0.1;
		}
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
	{
		sX = sY = sZ += 1;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))
	{
		sX = sY = sZ -= 1;
	}
	/* Follow mouse
	x = InputHandler::Instance()->getMousePosition()->getX();
	y = InputHandler::Instance()->getMousePosition()->getY();
	*/
}

void Dragon::update()
{
	objects[0].translation = Matrix4().setTranslationMatrix(0, 0, 0);
	objects[0].rotation = Matrix4().setRotation(angleX, angleY, angleZ);
	objects[0].scale = Matrix4().setScaleMatrix(sX, sY, sZ);
}

void Dragon::render()
{
	//draw axis lines
	gph.drawLine(0, 300, 0, -300, Vector3D(0, 255, 0));
	gph.drawLine(400, 0, -400, 0, Vector3D(0, 255, 0));

	//for each object
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i].modelMatrix = Matrix4().setModelMatrix(objects[i].translation, objects[i].rotation, objects[i].scale);
		//objects[i].modelMatrix = Matrix4().setModelMatrix(objects[i].translation, rotation, objects[i].scale);
		transformMatrix = projectionMatrix * viewMatrix * objects[i].modelMatrix;
		//transformMatrix = viewMatrix * objects[i].modelMatrix;

		//displayMatrix(viewMatrix * objects[i].modelMatrix);
		//displayMatrix(transformMatrix, "Transform");

		//for each vertex in the object
		/*
		for (int j = 0; j < objects[i].vertex.size(); j++)
		{
		Vector4D point = transformMatrix * *objects[i].vertex[j];
		//std::cout<<"Before = Point "<<j<<": "<<point.getX()<<" "<<point.getY()<<std::endl;

		displayVector4D(point, "Before", 1);
		point.normalizeW();
		displayVector4D(point, "After", 1);
		int x0 = point.getX();
		int y0 = point.getY();
		//std::cout<<"After = Point "<<j<<": "<<x0<<" "<<y0<<std::endl;
		gph.drawPixel(x0, y0);
		}
		*/
		//for each face of the object
		for (int k = 0; k < objects[i].face.size(); k++)
		{
			//used quad as basic shape
			int v0 = objects[i].face[k]->v0;
			int v1 = objects[i].face[k]->v1;
			int v2 = objects[i].face[k]->v2;
			//int v3 = objects[i].face[k]->v3;

			Vector4D point0 = transformMatrix * *objects[i].vertex[v0];
			Vector4D point1 = transformMatrix * *objects[i].vertex[v1];
			Vector4D point2 = transformMatrix * *objects[i].vertex[v2];
			//Vector4D point3 = transformMatrix * *objects[i].vertex[v3];

			
			//normalizing w component
			/*
			displayVector4D(point0, "Before point 0", 1);
			point0.normalizeW();
			displayVector4D(point0, "After point 0", 1);
			displayVector4D(point1, "Before point 1", 1);
			point1.normalizeW();
			displayVector4D(point1, "After point 1", 1);
			displayVector4D(point2, "Before point 2", 1);
			point2.normalizeW();
			displayVector4D(point2, "After point 2", 1);
			*/

			//displayVector4D(point0, "Point 0", 1);
			//displayVector4D(point1, "Point 1", 1);
			//displayVector4D(point2, "Point 2", 1);

			//draw 4 lines of the quad
			gph.drawLine(point0.getX(), point0.getY(), point1.getX(), point1.getY());
			gph.drawLine(point1.getX(), point1.getY(), point2.getX(), point2.getY());
			gph.drawLine(point2.getX(), point2.getY(), point0.getX(), point0.getY());

			if (!wireFrame)
			{
				switch (k)
				{
				case 0:
					gph.fillTriangle(point0, point1, point2, Vector3D(0, 25, 25));
					break;
				case 1:
					gph.fillTriangle(point0, point1, point2, Vector3D(25, 100, 25));
					break;
				case 2:
					gph.fillTriangle(point0, point1, point2, Vector3D(100, 100, 150));
					break;
				case 3:
					gph.fillTriangle(point0, point1, point2, Vector3D(150, 25, 150));
					break;
				case 4:
					//gph.fillTriangle(point0, point1, point2, Vector3D(150, 200, 150));
					break;
				case 5:
					//gph.fillTriangle(point0, point1, point2, Vector3D(123, 32, 12));
					break;
				case 6:
					//gph.fillTriangle(point0, point1, point2, Vector3D(230, 90, 45));
					break;
				case 7:
					//gph.fillTriangle(point0, point1, point2, Vector3D(159, 23, 23));
					break;
				case 8:
					//gph.fillTriangle(point0, point1, point2, Vector3D(255, 10, 100));
					break;
				case 9:
					//gph.fillTriangle(point0, point1, point2, Vector3D(24, 28, 87));
					break;
				case 10:
					//gph.fillTriangle(point0, point1, point2, Vector3D(14, 11, 60));
					break;
				case 11:
					//gph.fillTriangle(point0, point1, point2, Vector3D(155, 43, 67));
					break;
				default:
					break;
				}
				//gph.fillTriangle(point0, point1, point2, Vector3D(0, 100, 150));
			}
		}
	}
}