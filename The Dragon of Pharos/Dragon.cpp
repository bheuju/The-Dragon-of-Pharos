#include "Dragon.h"
#include "InputHandler.h"
#include "Camera.h"

#include <fstream>

Dragon::Dragon()
{
	selected = 0;
	wireFrame = true;
	//wireFrame = false;
	showWire = true;

	released = true;

	translateStep = 1;
	rotateStep = 0.1;
	scaleStep = 0.1;

	endPos = Vector2D(0, 0);
	startPos = Vector2D(0, 0);

	//lines.push_back(Vector2D(0, 0));
}

void Dragon::init()
{
	//Set View Matrix
	Camera::Instance()->setCameraPos(0, 0, 200);
	Camera::Instance()->setCameraTarget(0, 0, 0);
	Camera::Instance()->setUpVector(0, 1, 0);
	viewMatrix = Camera::Instance()->getViewMatrix();

	//displayMatrix(viewMatrix);

	//Set Projection Matrix
	projectionMatrix = Matrix4().setProjectionMatrix(45, 3.0/4.0, 1, 500);

	/** Initialize object: cube */
	//===========================/
	cube = Object("cube");
	{
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
	}
	Object octahedron("Octahedron");
	{
		octahedron.vertex.push_back(new Vector4D(10, 0, 0));
		octahedron.vertex.push_back(new Vector4D(0, -10, 0));
		octahedron.vertex.push_back(new Vector4D(-10, 0, 0));
		octahedron.vertex.push_back(new Vector4D(0, 10, 0));
		octahedron.vertex.push_back(new Vector4D(0, 0, 10));
		octahedron.vertex.push_back(new Vector4D(0, 0, -10));
		octahedron.face.push_back(new Face(1, 0, 4));
		octahedron.face.push_back(new Face(2, 1, 4));
		octahedron.face.push_back(new Face(3, 2, 4));
		octahedron.face.push_back(new Face(0, 3, 4));
		octahedron.face.push_back(new Face(0, 1, 5));
		octahedron.face.push_back(new Face(1, 2, 5));
		octahedron.face.push_back(new Face(2, 3, 5));
		octahedron.face.push_back(new Face(3, 0, 5));

		octahedron.setTranslation(-20, -50, 0);
		octahedron.setScale(2, 2, 2);
		//octahedron.shown = false;
	}
	//Push initialized objects
	//cube.setTranslation(-100, 50, 0);
	cube.setScale(2, 2, 2);
	//cube.shown = false;
	cube.setRotation(0, 0, 0);

	objects.push_back(cube);

	cube.setTranslation(-15, 50, -10);
	cube.setScale(1, 1, 1);
	//cube.shown = false;

	objects.push_back(cube);

	objects.push_back(octahedron);

	Object tailFin("Tail Fin");
	{
		tailFin.vertex.push_back(new Vector4D(-200, 0, 0));	//0
		tailFin.vertex.push_back(new Vector4D(-160, 15, 0));	//1
		tailFin.vertex.push_back(new Vector4D(-120, 64, 0));	//2
		tailFin.vertex.push_back(new Vector4D(-80, 64, 0));	//3
		tailFin.vertex.push_back(new Vector4D(-55, 71, 0));	//4
		tailFin.vertex.push_back(new Vector4D(-40, 82, 0));	//5
		tailFin.vertex.push_back(new Vector4D(-5, 70, 0));	//6
		tailFin.vertex.push_back(new Vector4D(30, 65, 0));	//7
		tailFin.vertex.push_back(new Vector4D(60, 69, 0));	//8
		tailFin.vertex.push_back(new Vector4D(45, 41, 0));	//9
		tailFin.vertex.push_back(new Vector4D(43, 29, 0));	//10
		tailFin.vertex.push_back(new Vector4D(45, 17, 0));	//11
		tailFin.vertex.push_back(new Vector4D(-18, 0, 0));	//12
		tailFin.face.push_back(new Face(0, 1, 2));
		tailFin.face.push_back(new Face(0, 2, 3));
		tailFin.face.push_back(new Face(0, 3, 4));
		tailFin.face.push_back(new Face(0, 4, 5));
		tailFin.face.push_back(new Face(0, 5, 6));
		tailFin.face.push_back(new Face(0, 6, 7));
		tailFin.face.push_back(new Face(0, 7, 8));
		tailFin.face.push_back(new Face(0, 8, 9));
		tailFin.face.push_back(new Face(0, 9, 10));
		tailFin.face.push_back(new Face(0, 10, 11));
		tailFin.face.push_back(new Face(0, 11, 12));

		tailFin.setScale(0.5, 0.5, 0.5);
		tailFin.setTranslation(100, 50, 0);
	}
	objects.push_back(tailFin);

	Object dragon("Dragon");


	/*
	displayMatrix(cube.modelMatrix, "Model Matrix");
	displayMatrix(viewMatrix, "View Matrix");
	displayMatrix(projectionMatrix, "Projection Matrix");
	*/
}

void Dragon::handleInput()
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


	/**********************************************************
	Input Keys Description:
	F10					-	toggle wire
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


	//clearing
	//gph.depthBuffer.clear();
	//gph.depthBuffer.push_back(1000);

	//clear frameBuffer
	gph.frameBuffer.clear();
	//cleat colorBuffer
	gph.colorBuffer.clear();
	//reset zBuffer
	for (int i = 0; i < 801; i++)
	{
		for (int j = 0; j < 601; j++)
		{
			gph.zBuffer[i][j] = 500;
		}
	}

	//draw axis lines
	gph.drawLine(0, 300, 0, -300, Vector3D(0, 255, 255));
	gph.drawLine(400, 0, -400, 0, Vector3D(0, 255, 255));

	//std::cout<<lines.size()<<std::endl;


	//display self made line
	for (int i = 1; i < lines.size(); i++)
	{
		int x1, y1, x2, y2;
		x1 = lines[i-1].getX();
		y1 = lines[i-1].getY();
		x2 = lines[i].getX();
		y2 = lines[i].getY();
		gph.drawLine(x1, y1, x2, y2, Vector3D(0, 10, 10));
	}
	//std::cout<<"Real: "<<gph.frameBuffer.size()<<std::endl;

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
		//	gph.drawPixel(x0, y0);
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
			if (showWire)
			{
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
			}

			if (!wireFrame)
			{
				switch (k)
				{
				case 0:
				case 1:
					//std::cout<<"Face "<<k<<std::endl;
					gph.fillTriangle(point0, point1, point2, Vector3D(0, 100, 100));	//front
					break;
				case 2:
				case 3:
					gph.fillTriangle(point0, point1, point2, Vector3D(25, 100, 25));	//back
					break;
				case 4:
				case 5:
					gph.fillTriangle(point0, point1, point2, Vector3D(100, 100, 150));	//left
					break;
				case 6:
				case 7:
					gph.fillTriangle(point0, point1, point2, Vector3D(150, 25, 150));	//right
					break;
				case 8:
				case 9:
					gph.fillTriangle(point0, point1, point2, Vector3D(50, 20, 80));	//top
					break;
				case 10:
				case 11:
					gph.fillTriangle(point0, point1, point2, Vector3D(123, 32, 12));		//bottom
					break;
				default:
					gph.fillTriangle(point0, point1, point2, Vector3D(0, 10, 150));
					break;
				}

			}
		}
	}
}

void Dragon::render()
{
	//std::cout<<gph.frameBuffer.size()<<std::endl;

	for (int i = 0; i < gph.frameBuffer.size(); i++)
		//for (int i = gph.frameBuffer.size()-1; i >= 0; i--)
	{
		float x = gph.frameBuffer[i].getX();
		float y = gph.frameBuffer[i].getY();
		float z = gph.frameBuffer[i].getZ();

		Vector3D color = gph.colorBuffer[i];

		gph.drawPixel(x, y, z, color);
	}

}