#include "Dragon.h"
#include "InputHandler.h"
#include "Camera.h"

Dragon::Dragon()
{
	selected = 0;
	wireFrame = true;

	released = true;

	translateStep = 1;
	rotateStep = 0.1;
	scaleStep = 0.1;
}

void Dragon::init()
{
	//Set View Matrix
	Camera::Instance()->setCameraPos(0, 0, 200);
	Camera::Instance()->setCameraTarget(0, 0, 0);
	Camera::Instance()->setUpVector(0, 1, 0);
	viewMatrix = Camera::Instance()->getViewMatrix();

	//Set Projection Matrix
	projectionMatrix = Matrix4().setProjectionMatrix(45, 4.0/3.0, 0, 100);

	/** Initialize object: cube */
	//===========================/
	cube = Object("cube");
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
	cube.setTranslation(100, 0, 0);
	objects.push_back(cube);
	cube.setTranslation(-100, 20, -10);
	objects.push_back(cube);

	/*
	displayMatrix(cube.modelMatrix, "Model Matrix");
	displayMatrix(viewMatrix, "View Matrix");
	displayMatrix(projectionMatrix, "Projection Matrix");
	*/
}

void Dragon::handleInput()
{
	/**********************************************************
	Input Keys Description:
	F11					-	toggle wireframe / rasterized
	F12					-	display FPS
	TAB and BACKSPACE	-	select objects
	H					-	hide objects
	LEFT(-), RIGHT(+)	-	translate X
	UP(+), DOWN(-)		-	translate Y
	LCTRL(+), RCTRL(-)	-	translate Z
	W,A,S,D,Q,E			-	rotate X, Y, Z
	Scroll and Z,X		-	scale
	LSHIFT + (R, S, T)	-	reset rotate, scale, translate
	SPACE				-	show info of slected object
	**********************************************************/

	//toggle between wireframe and rasterized model
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
	//Selecting objects
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_TAB))
	{
		selected++;
		if (selected >= objects.size())
		{
			selected = 0;
		}
		std::cout<<"Selected - "<<selected<<"\t -- "<<objects[selected].name<<" Status: "<<objects[selected].shown<<std::endl;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_BACKSPACE))
	{
		selected--;
		if (selected < 0)
		{
			selected = objects.size() - 1;
		}
		std::cout<<"Selected - "<<selected<<"\t -- "<<objects[selected].name<<" Status: "<<objects[selected].shown<<std::endl;
	}
	//toggling hiding objects
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_H) && released)
	{
		if (objects[selected].shown)
		{
			objects[selected].shown = false;
		}
		else
		{
			objects[selected].shown = true;
		}
		released = false;
	}
	else
	{
		released = true;
	}
	//translation
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		objects[selected].tX -= translateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		objects[selected].tX += translateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		objects[selected].tY -= translateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		objects[selected].tY += translateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LCTRL))
	{
		objects[selected].tZ += translateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
	{
		objects[selected].tZ -= translateStep;
	}
	//rotation
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		objects[selected].angleX -= rotateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{
		objects[selected].angleX += rotateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		objects[selected].angleY -= rotateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		objects[selected].angleY += rotateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Q))
	{
		objects[selected].angleZ -= rotateStep;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_E))
	{
		objects[selected].angleZ += rotateStep;
	}
	//scaling
	if (InputHandler::Instance()->getWheelPosition() == -1)
	{
		objects[selected].sX -= scaleStep;
		objects[selected].sY -= scaleStep;
		objects[selected].sZ -= scaleStep;
		if (objects[selected].sX < 0.1)
		{
			objects[selected].sX = objects[selected].sY = objects[selected].sZ = 0.1;
		}
	}
	else if (InputHandler::Instance()->getWheelPosition() == 1)
	{
		if (objects[selected].sX >= 0.1)
		{
			objects[selected].sX += scaleStep;
			objects[selected].sY += scaleStep;
			objects[selected].sZ += scaleStep;
		}
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
	{
		if (objects[selected].sX > 0.1)
		{
			objects[selected].sX = objects[selected].sY = objects[selected].sZ += 1;
		}
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))
	{
		objects[selected].sX = objects[selected].sY = objects[selected].sZ -= 1;
		if (objects[selected].sX < 0.1)
		{
			objects[selected].sX = objects[selected].sY = objects[selected].sZ = 0.1;
		}
	}
	//reset model
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT))
	{
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_T))
		{
			std::cout<<"Reset Translation\n";
			objects[selected].tX = objects[selected].tY = objects[selected].tZ = 0;
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_R))
		{
			std::cout<<"Reset Rotation\n";
			objects[selected].angleX = objects[selected].angleY = objects[selected].angleZ = 0;
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
		{
			std::cout<<"Reset Scaling\n";
			objects[selected].sX = objects[selected].sY = objects[selected].sZ = 1;
		}
	}
	//show info
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		std::cout<<"======================================="<<std::endl;
		std::cout<<"SN: "<<selected<<std::endl;
		std::cout<<"Object: "<<objects[selected].name<<std::endl;
		std::cout<<"Status: "<<(objects[selected].shown ? "shown": "hidden")<<std::endl;
		std::cout<<"World coordinates: "<<objects[selected].tX<<", "<<objects[selected].tY<<", "<<objects[selected].tZ<<std::endl;
		std::cout<<"Rotation: "<<objects[selected].angleX<<", "<<objects[selected].angleY<<", "<<objects[selected].angleZ<<std::endl;
		std::cout<<"Scale: "<<objects[selected].sX<<", "<<objects[selected].sY<<", "<<objects[selected].sZ<<std::endl;
		std::cout<<"======================================="<<std::endl;
	}
}

void Dragon::update()
{
	for (int i = 0; i < objects.size(); i++)
	{

		//std::cout<<"angle x"<<objects[i].tX<<std::endl;
		//std::cout<<"angle y"<<objects[i].tY<<std::endl;
		objects[i].translation = Matrix4().setTranslationMatrix(objects[i].tX, objects[i].tY, objects[i].tZ);
		objects[i].rotation = Matrix4().setRotation(objects[i].angleX, objects[i].angleY, objects[i].angleZ);
		objects[i].scale = Matrix4().setScaleMatrix(objects[i].sX, objects[i].sY, objects[i].sZ);
		//displayMatrix(objects[i].translation, "Translate");
		//displayMatrix(objects[i].rotation, "Rotate");
		//displayMatrix(objects[i].scale, "Scale");
	}

	//objects[0].translation = Matrix4().setTranslationMatrix(0, 0, 0);
	//objects[0].rotation = Matrix4().setRotation(angleX, angleY, angleZ);
	//objects[0].scale = Matrix4().setScaleMatrix(sX, sY, sZ);

	//objects[1].translation = Matrix4().setTranslationMatrix(50, 0, 0);
	//objects[1].rotation = Matrix4().setRotation(angleX, angleY, angleZ);
	//objects[1].scale = Matrix4().setScaleMatrix(sX, sY, sZ);
}

void Dragon::render()
{
	//clearing
	//gph.depthBuffer.clear();
	//gph.depthBuffer.push_back(1000);

	//draw axis lines
	gph.drawLine(0, 300, 0, -300, Vector3D(0, 255, 255));
	gph.drawLine(400, 0, -400, 0, Vector3D(0, 255, 255));

	//for each object
	for (int i = 0; i < objects.size(); i++)
	{
		if (!objects[i].shown)
		{
			continue;
		}
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
			point0.normalizeW();
			point1.normalizeW();
			point2.normalizeW();

			//displayVector4D(point0, "Point 0", 1);
			//displayVector4D(point1, "Point 1", 1);
			//displayVector4D(point2, "Point 2", 1);

			//draw 3 lines of the triangle
			if (i == selected)
			{
				//highlight selected object by drawng green color line	
				gph.drawLine(point0.getX(), point0.getY(), point1.getX(), point1.getY(), Vector3D(0, 255, 0));
				gph.drawLine(point1.getX(), point1.getY(), point2.getX(), point2.getY(), Vector3D(0, 255, 0));
				gph.drawLine(point2.getX(), point2.getY(), point0.getX(), point0.getY(), Vector3D(0, 255, 0));
			}
			else
			{
				//use default color red for unselected
				gph.drawLine(point0.getX(), point0.getY(), point1.getX(), point1.getY());
				gph.drawLine(point1.getX(), point1.getY(), point2.getX(), point2.getY());
				gph.drawLine(point2.getX(), point2.getY(), point0.getX(), point0.getY());
			}

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
					gph.fillTriangle(point0, point1, point2, Vector3D(150, 200, 150));
					break;
				case 5:
					gph.fillTriangle(point0, point1, point2, Vector3D(123, 32, 12));
					break;
				case 6:
					gph.fillTriangle(point0, point1, point2, Vector3D(230, 90, 45));
					break;
				case 7:
					gph.fillTriangle(point0, point1, point2, Vector3D(159, 23, 23));
					break;
				case 8:
					gph.fillTriangle(point0, point1, point2, Vector3D(255, 10, 100));
					break;
				case 9:
					gph.fillTriangle(point0, point1, point2, Vector3D(24, 28, 87));
					break;
				case 10:
					gph.fillTriangle(point0, point1, point2, Vector3D(14, 11, 60));
					break;
				case 11:
					gph.fillTriangle(point0, point1, point2, Vector3D(155, 43, 67));
					break;
				default:
					break;
				}
				//gph.fillTriangle(point0, point1, point2, Vector3D(0, 100, 150));
			}
		}
	}
}