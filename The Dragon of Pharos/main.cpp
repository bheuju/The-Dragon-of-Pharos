/**
Main Function
*/
#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include <cmath>
#include "DoP.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

void myPerspective(float fovy, float aspect, float zNear, float zFar)
{
	float fw, fh;
	fh = tan(fovy / 360 * 3.1416) * zNear;
	fw = fh*aspect;
	glFrustum(-fw, fw, -fh, fh, zNear, zFar);
}

int main(int argc, char** argv)
{
	Uint32 frameStart, frameTime;

	//Initialize
	DoP::Instance()->init("The Dragon of Pharos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

	glClearColor(0, 1, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	myPerspective(45, 600.0/800.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);

	while (DoP::Instance()->isRunning())
	{
		frameStart = SDL_GetTicks();

		/***************************/

		//handle  inputs
		DoP::Instance()->handleInputs();
		//TODO: update
		DoP::Instance()->update();
		//TODO: render
		DoP::Instance()->render();
		
		/***************************/

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	
	//Clean
	DoP::Instance()->clean();

	return 0;
}
