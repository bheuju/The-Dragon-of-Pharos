#include "DoP.h"

DoP* DoP::pInstance = 0;

DoP::DoP()
{
	mRun = true;
	mode = OPENGL;

	choice = PHAROS;
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
	pharos.init();
}

void DoP::handleInputs()
{
	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		mRun = false;
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F1))
	{
		choice = DRAGON;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F2))
	{
		choice = PHAROS;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F4))
	{
		choice = ALL;
	}

	switch(choice)
	{
	case DRAGON:
		drag.handleInput();
		break;
	case PHAROS:
		pharos.handleInput();
		break;
	case ALL:
		//drag.handleInput();
		//pharos.handleInput();
		break;
	}
}

void DoP::update()
{
	switch(choice)
	{
	case DRAGON:
		drag.update();
		break;
	case PHAROS:
		pharos.update();
		break;
	case ALL:
		drag.update();
		pharos.update();
		break;
	}
}

void DoP::render()
{
	if (mode == SDL)
	{
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderClear(ren);

		switch(choice)
		{
		case DRAGON:
			drag.render();
			break;
		case PHAROS:
			pharos.render();
			break;
		case ALL:
			drag.render();
			pharos.render();
			break;
		}

		SDL_RenderPresent(ren);
	}
	else if (mode == OPENGL)
	{
		//clear window to white
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		switch(choice)
		{
		case DRAGON:
			drag.render();
			break;
		case PHAROS:
			pharos.render();
			break;
		case ALL:
			drag.render();
			pharos.render();
			break;
		}

		SDL_GL_SwapWindow(win);
	}
}

void DoP::clean()
{
	//delete drag;
	SDL_Quit();
}
