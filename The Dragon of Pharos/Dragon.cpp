#include "Dragon.h"
#include "InputHandler.h"

Dragon::Dragon()
{
	step = 10;
	x = y = 10;
}

void Dragon::update()
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

void Dragon::render()
{
	gph.drawLine(400, 300, x, y);

	//gph.drawPixel(50, 50);
}