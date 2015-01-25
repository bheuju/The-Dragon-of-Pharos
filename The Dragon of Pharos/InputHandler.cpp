#include "InputHandler.h"
InputHandler* InputHandler::pInstance = 0;

InputHandler::InputHandler() : mousePosition(new Vector2D(0, 0)), keyStates(0), scroll(0)
{
	//Set mouse button states to false
	for (int i = 0; i < 3; i++)
	{
		mouseButtonStates.push_back(false);
	}

	mousePosition = new Vector2D();
}

void InputHandler::update()
{
	if (SDL_WaitEvent(&event))
	//while(SDL_PollEvent(&event))
	{
		//reset mouse states
		reset();

		switch (event.type)
		{
		case SDL_QUIT:
			DoP::Instance()->setRunning(false);
			SDL_Quit();
			break;

			//mouse cases
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown();
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp();
			break;
		case SDL_MOUSEMOTION:
			onMouseMotion();
			break;
		case SDL_MOUSEWHEEL:
			onMouseWheel();
			break;

			//keyboard cases
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}


//mouse functions
void InputHandler::onMouseButtonDown()
{
	//If mouse button pressed set it to true
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		mouseButtonStates[RIGHT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		mouseButtonStates[MIDDLE] = true;
	}
}

void InputHandler::onMouseButtonUp()
{
	//If mose button released set it to false
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		mouseButtonStates[RIGHT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		mouseButtonStates[MIDDLE] = false;
	}
}

void InputHandler::onMouseMotion()
{
	mousePosition->setX(event.motion.x);
	mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseWheel()
{
	scroll = event.wheel.y;
}

void InputHandler::reset()
{
	mouseButtonStates[LEFT] = false;
	mouseButtonStates[RIGHT] = false;
	mouseButtonStates[MIDDLE] = false;
	scroll = 0;
}

//keybard functions
bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (keyStates != 0)
	{
		if (keyStates[key] == 1)
		{
			return true;
		}
	}
	return false;
}

void InputHandler::onKeyDown()
{
	keyStates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
	keyStates = SDL_GetKeyboardState(0);
}

