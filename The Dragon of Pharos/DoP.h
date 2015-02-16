/********************** Dragon of Pharos **********************
Main Class
- handle all processes
--------------------------------------------------------------
Singleton class
**************************************************************/

#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include "InputHandler.h"
#include "Dragon.h"
#include "Pharos.h"

enum
{
	OPENGL = 0,
	SDL = 1,

	DRAGON = 0,
	PHAROS = 1,
	ALL = 9
};

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

	int getMode() {return mode;}

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

	int mode;	//SDL or OPENGL
	bool mRun;

	int choice;
	int inputChoice;

	SDL_Window* win;
	SDL_Renderer* ren;

	//Objects
	Dragon drag;
	Pharos pharos;
};