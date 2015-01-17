/************************ InputHandler ************************
Handles all the inputs
- mouse
- keyboard
--------------------------------------------------------------
Singleton class
**************************************************************/

#pragma once
#include <SDL.h>
#include <vector>
#include "DoP.h"
#include "Vector2D.h"

enum mouseButtons
{
	LEFT = 0,
	RIGHT = 1,
	MIDDLE = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new InputHandler();
		}
		return pInstance;
	}

	~InputHandler();

	void update();
	void clean();

	//Keyboard handling functions
	void onKeyDown();
	void onKeyUp();
	bool isKeyDown(SDL_Scancode key);

	//Mouse handling functions
	void onMouseButtonDown();
	void onMouseButtonUp();
	void onMouseMotion();
	void onMouseWheel();
	bool getMouseButtonState(int buttonNumber)
	{
		//returns the (true/false) state of moue button of buttonNumber (LEFT, RIGHT, MIDDLE)
		return mouseButtonStates[buttonNumber];
	}
	Vector2D* getMousePosition()
	{
		//return 2D vector coordinates of mouse postion
		return mousePosition;
	}
	int getWheelPosition()
	{
		//return 1 for scroll up, -1 for scroll down
		return scroll;
	}
	void reset();

private:
	InputHandler();
	static InputHandler* pInstance;

	SDL_Event event;
	bool keyPress;

	const Uint8* keyStates;
	std::vector<bool> mouseButtonStates;

	Vector2D* mousePosition;
	int scroll;
};

