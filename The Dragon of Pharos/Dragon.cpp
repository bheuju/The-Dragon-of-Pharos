#include "Dragon.h"
#include "InputHandler.h"

Dragon::Dragon()
{
	step = 10;
	x = y = 10;
}

void Dragon::init()
{
	Object cube("cube", 8, 12);
	cube.vertex.push_back(new Vector4D(-10, 10, 10));
	cube.vertex.push_back(new Vector4D(-10, -10, 10));
	cube.vertex.push_back(new Vector4D(10, -10, 10));
	cube.vertex.push_back(new Vector4D(10, 10, 10));
	cube.vertex.push_back(new Vector4D(-10, 10, -10));
	cube.vertex.push_back(new Vector4D(-10, -10, -10));
	cube.vertex.push_back(new Vector4D(10, -10, -10));
	cube.vertex.push_back(new Vector4D(10, 10, -10));

	cube.face.push_back(new Face(0, 1, 2, 3));
	cube.face.push_back(new Face(0, 1, 5, 4));

	cube.translation.setTranslationMatrix(200, 200, 200);
	cube.rotation.setRotationX(90);
	cube.scale.setScaleMatrix(2, 2, 2);


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
	x = InputHandler::Instance()->getMousePosition()->getX();
	y = InputHandler::Instance()->getMousePosition()->getY();
}

void Dragon::update()
{
	
}

void Dragon::render()
{
	gph.drawLine(400, 300, x, y);

	//gph.drawPixel(50, 50);
}