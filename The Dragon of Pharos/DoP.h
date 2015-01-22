/********************** Dragon of Pharos **********************
Main Class
- handle all processes
--------------------------------------------------------------
Singleton class
**************************************************************/

#pragma once
#include <SDL.h>
#include <iostream>
#include "InputHandler.h"
#include "Dragon.h"

class DoP
{
public:
	static DoP* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new DoP();
		}
		return pInstance;
	}
	~DoP() {}

	void init(const char* title, int xpos, int ypos, int width, int height, int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	void handleInputs();
	void update();
	void render();

	void clean();

	bool isRunning() {return mRun;}
	void setRunning(bool run) {mRun = run;}

	SDL_Renderer* getRenderer() {return ren;}

private:
	DoP();
	static DoP* pInstance;

	bool mRun;

	SDL_Window* win;
	SDL_Renderer* ren;

	//Objects
	Dragon drag;
};