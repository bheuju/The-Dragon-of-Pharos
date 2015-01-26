#include "DoP.h"

DoP* DoP::pInstance = 0;

DoP::DoP()
{
	mRun = true;
	mode = OPENGL;
}

void DoP::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	if (win = SDL_CreateWindow(title, xpos, ypos, width, height, flags))
	{
		std::cout<<"Window initialized..."<<std::endl;
	}

	if (mode == SDL)
	{
		//create renderer only in SDL mode
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		std::cout<<"SDL mode ..."<<std::endl;
	}
	else if (mode == OPENGL)
	{
		//turn on double buffering
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		//setting to render in window coordinate system
		//instead of normalized
		SDL_GL_CreateContext(win);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, height, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		std::cout<<"OpenGL mode ..."<<std::endl;
	}

	//initialize the objects to draw dragon
	drag.init();
}

void DoP::handleInputs()
{
	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		mRun = false;
	}

	drag.handleInput();
}

void DoP::update()
{
	drag.update();
}

void DoP::render()
{
	if (mode == SDL)
	{
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderClear(ren);

		drag.render();

		SDL_RenderPresent(ren);
	}
	else if (mode == OPENGL)
	{
		//clear window to white
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		drag.render();

		SDL_GL_SwapWindow(win);
	}
}

void DoP::clean()
{
	//delete drag;
	SDL_Quit();
}
