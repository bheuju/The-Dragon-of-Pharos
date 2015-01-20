#include "DoP.h"
DoP* DoP::pInstance = 0;

DoP::DoP()
{
	mRun = true;
}

void DoP::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{

	//turn on double buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_Init(SDL_INIT_EVERYTHING);
	if (win = SDL_CreateWindow(title, xpos, ypos, width, height, flags))
	{
		std::cout<<"Window initialized..."<<std::endl;
	}
	else
	{
		std::cout<<"!! Initialization failed"<<std::endl;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(win);


	drag = new Dragon();
}

void DoP::handleInputs()
{
	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		mRun = false;
	}
}

void DoP::update()
{
	
}

void DoP::render()
{
	//clear window to white
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	drag->render();

	//display
	SDL_GL_SwapWindow(win);
}

void DoP::clean()
{
	delete drag;
	SDL_Quit();
}
