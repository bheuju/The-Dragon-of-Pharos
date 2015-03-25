#include "DoP.h"

DoP* DoP::pInstance = 0;

DoP::DoP()
{
	mRun = true;
	mode = OPENGL;

	inputChoice = choice = DRAGON;
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

	//TTF_Init();

	//font = TTF_OpenFont("fonts/SourceSansPro-Bold.ttf", 18);
	//SDL_Color color = {100, 100, 100};
	//surf = TTF_RenderText_Blended(font, "The Dragon of Pharos", color);
	//tex = SDL_CreateTextureFromSurface(ren, surf);
	//SDL_FreeSurface(surf);

	//initialize the objects to draw dragon
	drag.init();
	pharos.init();
	environment.init();
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
		std::cout<<"Working with Dragon only"<<std::endl;
		choice = DRAGON;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F2))
	{
		std::cout<<"Working with Pharos only"<<std::endl;
		choice = PHAROS;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F3))
	{
		std::cout<<"Working with Environment only"<<std::endl;
		choice = ENVIRONMENT;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F4))
	{
		std::cout<<"Working with ALL"<<std::endl;
		choice = ALL;
	}

	if (choice == ALL)
	{
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_1))
		{
			std::cout<<"Dragon - Input Enabled."<<std::endl;
			inputChoice = DRAGON;
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_2))
		{
			std::cout<<"Pharos - Input Enabled."<<std::endl;
			inputChoice = PHAROS;
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_3))
		{
			std::cout<<"Environment - Input Enabled."<<std::endl;
			inputChoice = ENVIRONMENT;
		}
	}

	//Camera are coupled
	switch(choice)
	{
	case DRAGON:
		drag.handleInput();
		break;
	case PHAROS:
		pharos.handleInput();
		break;
	case ENVIRONMENT:
		environment.handleInput();
		break;
	case ALL:
		switch(inputChoice)
		{
		case DRAGON:
			drag.handleInput();
			break;
		case PHAROS:
			pharos.handleInput();
			break;
		case ENVIRONMENT:
			environment.handleInput();
			break;
		}
		break;
	}
}

void DoP::update()
{
	Graphics::Instance()->clearBuffer();

	switch(choice)
	{
	case DRAGON:
		drag.update();
		break;
	case PHAROS:
		pharos.update();
		break;
	case ENVIRONMENT:
		environment.update();
		break;
	case ALL:
		drag.update();
		pharos.update();
		environment.update();
		break;
	}
}

void DoP::render()
{
	//SDL_Rect srcRect, destRect;
	//SDL_QueryTexture(tex, 0, 0, &srcRect.w, &srcRect.h);

	//SDL_RenderCopy(ren, tex, 0, &srcRect);
	//SDL_RenderPresent(ren);

	if (mode == SDL)
	{
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderClear(ren);

		Graphics::Instance()->render();

		//switch(choice)
		//{
		//case DRAGON:
		//	drag.render();
		//	break;
		//case PHAROS:
		//	pharos.render();
		//	break;
		//case ALL:
		//	drag.render();
		//	pharos.render();
		//	break;
		//}

		SDL_RenderPresent(ren);
	}
	else if (mode == OPENGL)
	{
		//clear window to white
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		Graphics::Instance()->render();


		//switch(choice)
		//{
		//case DRAGON:
		//	drag.render();
		//	break;
		//case PHAROS:
		//	pharos.render();
		//	break;
		//case ALL:
		//	drag.render();
		//	pharos.render();
		//	break;
		//}

		SDL_GL_SwapWindow(win);
	}
}

void DoP::clean()
{
	//delete drag;
	SDL_Quit();
}
