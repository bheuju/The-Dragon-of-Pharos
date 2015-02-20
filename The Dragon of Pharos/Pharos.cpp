#include "Pharos.h"
#include "InputHandler.h"
#include "Camera.h"

Pharos::Pharos()
{
	selected = 0;
	wireFrame = true;
	//wireFrame = false;
	showWire = true;
	highLight = true;

	released = true;

	translateStep = 1;
	rotateStep = 0.1;
	scaleStep = 0.1;

	endPos = Vector2D(0, 0);
	startPos = Vector2D(0, 0);

	cameraRot = Vector3D(0, 0, 0);
	cameraStepX = 0.1;
	cameraStepY = 0.1;
	cameraStepZ = 5;
	//lines.push_back(Vector2D(0, 0));
}

void Pharos::init()
{
	//Set View Matrix
	Camera::Instance()->setOrgCameraPos(0, 0, 200);
	Camera::Instance()->setCameraPos(0, 0, 200);
	Camera::Instance()->setCameraTarget(0, 0, 0);
	Camera::Instance()->setOrgUpVector(0, 1, 0);
	Camera::Instance()->setUpVector(0, 1, 0);
	viewMatrix = Camera::Instance()->getViewMatrix();

	//Set Projection Matrix
	projectionMatrix = Matrix4().setProjectionMatrix(45, 3.0/4.0, 1, 500);

	/** Initialize object: cube */
	//===========================/
	Object tower = shape.createTower(40);
	tower.setTranslation(0, 0, 0);
	tower.setScale(1, 1, 1);
	tower.shown = true;

	Object hemisphere = shape.createHemiSphere();
	hemisphere.setTranslation(0, 40, 0);
	hemisphere.setScale(1, 1, 1);
	hemisphere.shown = true;

	Object torus = shape.createTorus();
	torus.setTranslation(0, 25, 0);
	torus.setScale(1, 1, 1);
	torus.shown = true;

	objects.push_back(tower);
	objects.push_back(hemisphere);
	objects.push_back(torus);

	/*
	displayMatrix(cube.modelMatrix, "Model Matrix");
	displayMatrix(viewMatrix, "View Matrix");
	displayMatrix(projectionMatrix, "Projection Matrix");
	*/
}

void Pharos::handleInput()
{
	////for self drawing lines
	//if (InputHandler::Instance()->getMouseButtonState(LEFT))
	//{
	//	startPos = endPos;

	//	endPos = *InputHandler::Instance()->getMousePosition();

	//	endPos.setX(endPos.getX() - 400);
	//	endPos.setY(300 - endPos.getY());

	//	lines.push_back(endPos);

	//	displayVector2D(startPos, "Start Position");
	//	displayVector2D(endPos, "End Position");
	//}
	//if (InputHandler::Instance()->getMouseButtonState(RIGHT))
	//{
	//	if (lines.size() > 0)
	//	{
	//		lines.pop_back();
	//	}
	//}


	/************************************************************
	Input Keys Description:
	F1, F2				-	work with DRAGON / PHAROS
	F4					-	display all (no manipulation inputs)
		1				-	DRAGON input handling
		2				-	PHAROS input handling
	F9					-	toggle objct highlight on select
	F10					-	toggle wire
	F11					-	toggle wireframe / rasterized
	F12					-	display FPS
	TAB and BACKSPACE	-	select objects
	H					-	hide objects
	LEFT(-), RIGHT(+)	-	translate X
	UP(+), DOWN(-)		-	translate Y
	LCTRL(+), RCTRL(-)	-	translate Z
	W,A,S,D,Q,E			-	rotate X, Y, Z
	mouseScroll and Z,X	-	scale
	SHIFT + (R, S, T)	-	reset rotate, scale, translate
	SPACE				-	show info of slected object
	I, K, J, L, U, O	-	move camera up, down, left, right
	R + C				-	reset camera
	*************************************************************/
	//toggle highlight on select
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F9))
	{
		if (highLight)
		{
			std::cout<<"Highlight disabled"<<std::endl;
			highLight = false;
		}
		else
		{
			std::cout<<"Highlight enable"<<std::endl;
			highLight = true;
		}
	}
	//toggle showing of wire in both wireframe and rasterized model
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F10))
	{
		if (showWire)
		{
			std::cout<<"Disabled wire"<<std::endl;
			showWire = false;
		}
		else
		{
			std::cout<<"Enabled wire"<<std::endl;
			showWire = true;
		}
	}
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
		std::cout<<"\nSelected - "<<selected<<"\t"<<objects[selected].name<<"\n\t\tStatus: "<<(objects[selected].shown ? "shown": "hidden")<<std::endl;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_BACKSPACE))
	{
		selected--;
		if (selected < 0)
		{
			selected = objects.size() - 1;
		}
		std::cout<<"\nSelected - "<<selected<<"\t"<<objects[selected].name<<"\n\t\tStatus: "<<(objects[selected].shown ? "shown": "hidden")<<std::endl;
	}
	//toggling hiding objects
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_H) && released)
	{
		if (objects[selected].shown)
		{
			std::cout<<objects[selected].name<<": "<<"hidden"<<std::endl;
			objects[selected].shown = false;
		}
		else
		{
			std::cout<<objects[selected].name<<": "<<"shown"<<std::endl;
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
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT) || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RSHIFT))
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
		std::cout.precision(5);
		std::cout<<"======================================="<<std::endl;
		std::cout<<"SN: "<<selected<<std::endl;
		std::cout<<"Object: "<<objects[selected].name<<std::endl;
		std::cout<<"Status: "<<(objects[selected].shown ? "shown": "hidden")<<std::endl;
		std::cout<<"World coordinates: "<<objects[selected].tX<<", "<<objects[selected].tY<<", "<<objects[selected].tZ<<std::endl;
		std::cout<<"Rotation: "<<objects[selected].angleX<<", "<<objects[selected].angleY<<", "<<objects[selected].angleZ<<std::endl;
		std::cout<<"Scale: "<<objects[selected].sX<<", "<<objects[selected].sY<<", "<<objects[selected].sZ<<std::endl;
		std::cout<<"---------------------------------------"<<std::endl;

		/*
		for (int i = 0; i < objects[selected].vertex.size(); i++)
		{
		Vector4D p = *objects[selected].vertex[i];
		std::cout<<"Vertex "<<i<<": "<<p.getX()<<", "<<p.getY()<<", "<<p.getZ()<<", "<<p.getW()<<std::endl;
		objects[selected].modelMatrix = Matrix4().setModelMatrix(objects[selected].translation, objects[selected].rotation, objects[selected].scale);
		transformMatrix = projectionMatrix * viewMatrix * objects[selected].modelMatrix;
		p = transformMatrix * *objects[selected].vertex[i];
		//std::cout<<"Vertex "<<i<<": "<<p.getX()<<", "<<p.getY()<<", "<<p.getZ()<<", "<<p.getW()<<std::endl;
		p = p.getNormalizedW();
		std::cout<<"Vertex "<<i<<": "<<p.getX()<<", "<<p.getY()<<", "<<p.getZ()<<", "<<p.getW()<<std::endl;
		}
		*/
		std::cout<<"======================================="<<std::endl;
	}

	//camera manipulators
	{
		cameraRot = Camera::Instance()->getCameraAngle();
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_I))
		{
			//up - move camera down
			//cameraPos.setY(cameraPos.getY() - cameraStepY);
			cameraRot.setX(cameraRot.getX() - cameraStepX);
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_K))
		{
			//down - move camera up
			//cameraPos.setY(cameraPos.getY() + cameraStepY);
			cameraRot.setX(cameraRot.getX() + cameraStepX);
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_J))
		{
			//left - move camera right
			//cameraPos.setX(cameraPos.getX() + cameraStepX);
			cameraRot.setY(cameraRot.getY() + cameraStepY);
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_L))
		{
			//right - move camera left
			//cameraPos.setX(cameraPos.getX() - cameraStepX);
			cameraRot.setY(cameraRot.getY() - cameraStepY);
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_U))
		{
			//near - move camera near
			//cameraPos.setZ(cameraPos.getZ() - cameraStepZ);
			//cameraRot.setX(cameraRot.getX() - cameraStepX);
			Camera::Instance()->setOrgCameraPos(0, 0, Camera::Instance()->getOrgCameraPos().getZ() - cameraStepZ);
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_O))
		{
			//far - move camera far
			//cameraPos.setZ(cameraPos.getZ() + cameraStepZ);
			//cameraRot.setX(cameraRot.getX() + cameraStepX);
			Camera::Instance()->setOrgCameraPos(0, 0, Camera::Instance()->getOrgCameraPos().getZ() + cameraStepZ);
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_C))
		{
			//reset camera
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_R))
			{
				std::cout<<"Reset camera configs"<<std::endl;
				Camera::Instance()->setOrgCameraPos(0, 0, 200);
				Camera::Instance()->setCameraPos(0, 0, 200);
				Camera::Instance()->setUpVector(0, 1, 0);
				cameraRot = Vector3D(0, 0, 0);
			}
			//display info of camera
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
			{
				std::cout.precision(5);
				float x = Camera::Instance()->getCameraPos().getX();
				float y = Camera::Instance()->getCameraPos().getY();
				float z = Camera::Instance()->getCameraPos().getZ();
				float radius = sqrt(x * x + y * y + z * z);
				std::cout<<"=============== Camera ================"<<std::endl;
				std::cout<<"Camera"<<std::endl;
				std::cout<<"World coordinates: "<<x<<", "<<y<<", "<<z<<std::endl;
				std::cout<<"Radius: "<<radius<<std::endl;
				std::cout<<"Rotation: "<<cameraRot.getX()<<", "<<cameraRot.getY()<<", "<<cameraRot.getZ()<<std::endl;
				std::cout<<"======================================="<<std::endl;
			}
		}
		Camera::Instance()->setCameraAngle(cameraRot);
	}
}

void Pharos::update()
{
	//displayVector3D(cameraRot, "Rotation Camera", 1);

	//TODO:	Try to move cameraRot variable to camera class to generalize camera
	//		rotation also in BOTH mode of F4
	Camera::Instance()->rotate();
	viewMatrix = Camera::Instance()->getViewMatrix();

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


	//clearing
	//Graphics::Instance()->depthBuffer.clear();
	//Graphics::Instance()->depthBuffer.push_back(1000);

	/** This has been moved to Graphics - clearBuffer() **/
	////clear frameBuffer
	//Graphics::Instance()->frameBuffer.clear();
	////cleat colorBuffer
	//Graphics::Instance()->colorBuffer.clear();
	////reset zBuffer
	//for (int i = 0; i < 800; i++)
	//{
	//	for (int j = 0; j < 600; j++)
	//	{
	//		Graphics::Instance()->zBuffer[i][j] = 500;
	//	}
	//}

	//draw axis lines
	Graphics::Instance()->drawLine(0, 300, 0, -300, Vector3D(0, 255, 255));
	Graphics::Instance()->drawLine(400, 0, -400, 0, Vector3D(0, 255, 255));

	//std::cout<<lines.size()<<std::endl;


	//display self made line
	for (int i = 1; i < lines.size(); i++)
	{
		int x1, y1, x2, y2;
		x1 = lines[i-1].getX();
		y1 = lines[i-1].getY();
		x2 = lines[i].getX();
		y2 = lines[i].getY();
		Graphics::Instance()->drawLine(x1, y1, x2, y2, Vector3D(0, 10, 10));
	}
	//std::cout<<"Real: "<<Graphics::Instance()->frameBuffer.size()<<std::endl;

	//for each object
	for (int i = 0; i < objects.size(); i++)
	{
		if (!objects[i].shown)
		{
			continue;
		}
		objects[i].modelMatrix = Matrix4().setModelMatrix(objects[i].translation, objects[i].rotation, objects[i].scale);
		transformMatrix = projectionMatrix * viewMatrix * objects[i].modelMatrix;
		//transformMatrix = viewMatrix * objects[i].modelMatrix;

		//displayMatrix(viewMatrix * objects[i].modelMatrix);
		//displayMatrix(transformMatrix, "Transform");

		//for each vertex in the object

		//for (int j = 0; j < objects[i].vertex.size(); j++)
		//{
		//	Vector4D point = transformMatrix * *objects[i].vertex[j];
		//	//std::cout<<"Before = Point "<<j<<": "<<point.getX()<<" "<<point.getY()<<std::endl;

		//	displayVector4D(point, "Before", 1);
		//	point.normalizeW();
		//	displayVector4D(point, "After", 1);
		//	int x0 = point.getX();
		//	int y0 = point.getY();
		//	//std::cout<<"After = Point "<<j<<": "<<x0<<" "<<y0<<std::endl;
		//	Graphics::Instance()->drawPixel(x0, y0);
		//}

		//for each face of the object
		for (int k = 0; k < objects[i].face.size(); k++)
		{
			//used quad as basic shape
			int v0 = objects[i].face[k]->v0;
			int v1 = objects[i].face[k]->v1;
			int v2 = objects[i].face[k]->v2;
			//int v3 = objects[i].face[k]->v3;

			//displayVector4D(*objects[i].vertex[v0], "Before", 1);

			//displayMatrix(projectionMatrix, "Projection");
			//displayMatrix(viewMatrix, "View");
			//displayMatrix(objects[i].modelMatrix, "Model");
			//displayMatrix(transformMatrix, "Transform");

			Vector4D point0 = transformMatrix * *objects[i].vertex[v0];
			Vector4D point1 = transformMatrix * *objects[i].vertex[v1];
			Vector4D point2 = transformMatrix * *objects[i].vertex[v2];
			//Vector4D point3 = transformMatrix * *objects[i].vertex[v3];

			//displayVector4D(point0);

			//values before normalizing
			p0 = point0;
			p1 = point1;
			p2 = point2;

			//displayVector4D(p0, "After", 1);

			//normalizing w component
			point0 = point0.getNormalizedW();
			point1 = point1.getNormalizedW();
			point2 = point2.getNormalizedW();

			//displayVector4D(point0, "After normalized", 1);

			//std::cout<<"Face: "<<k<<std::endl;

			//displayVector4D(point0, "Point 0", 1);
			//displayVector4D(point1, "Point 1", 1);
			//displayVector4D(point2, "Point 2", 1);

			//draw 3 lines of the triangle
			//draw 3 lines of the triangle
			if (showWire)
			{
				if (i == selected && highLight)
				{
					//highlight selected object by drawng green color line	
					Graphics::Instance()->drawLine(point0.getX(), point0.getY(), point1.getX(), point1.getY(), Vector3D(0, 255, 0));
					Graphics::Instance()->drawLine(point1.getX(), point1.getY(), point2.getX(), point2.getY(), Vector3D(0, 255, 0));
					Graphics::Instance()->drawLine(point2.getX(), point2.getY(), point0.getX(), point0.getY(), Vector3D(0, 255, 0));
				}
				else
				{
					//use default color red for unselected
					Graphics::Instance()->drawLine(point0.getX(), point0.getY(), point1.getX(), point1.getY());
					Graphics::Instance()->drawLine(point1.getX(), point1.getY(), point2.getX(), point2.getY());
					Graphics::Instance()->drawLine(point2.getX(), point2.getY(), point0.getX(), point0.getY());
				}
			}

			if (!wireFrame)
			{
				switch (k % 12)
				{
				case 0:
				case 1:
					//std::cout<<"Face "<<k<<std::endl;
					Graphics::Instance()->fillTriangle(point0, point1, point2, Vector3D(0, 100, 100));	//front
					break;
				case 2:
				case 3:
					Graphics::Instance()->fillTriangle(point0, point1, point2, Vector3D(25, 100, 25));	//back
					break;
				case 4:
				case 5:
					Graphics::Instance()->fillTriangle(point0, point1, point2, Vector3D(100, 100, 150));	//left
					break;
				case 6:
				case 7:
					Graphics::Instance()->fillTriangle(point0, point1, point2, Vector3D(150, 25, 150));	//right
					break;
				case 8:
				case 9:
					Graphics::Instance()->fillTriangle(point0, point1, point2, Vector3D(50, 20, 80));	//top
					break;
				case 10:
				case 11:
					Graphics::Instance()->fillTriangle(point0, point1, point2, Vector3D(123, 32, 12));		//bottom
					break;
				default:
					Graphics::Instance()->fillTriangle(point0, point1, point2, Vector3D(0, 10, 150));
					break;
				}
			}
		}
	}
}

void Pharos::render()
{
	//std::cout<<Graphics::Instance()->frameBuffer.size()<<std::endl;

	for (int i = 0; i < Graphics::Instance()->frameBuffer.size(); i++)
		//for (int i = Graphics::Instance()->frameBuffer.size()-1; i >= 0; i--)
	{
		float x = Graphics::Instance()->frameBuffer[i].getX();
		float y = Graphics::Instance()->frameBuffer[i].getY();
		float z = Graphics::Instance()->frameBuffer[i].getZ();

		Vector3D color = Graphics::Instance()->colorBuffer[i];

		Graphics::Instance()->drawPixel(x, y, z, color);
	}

}
