/********************** Dragon of Pharos **********************
Dragon Class
- consists all about dragon
- model space of each parts
- wireframe
--------------------------------------------------------------

**************************************************************/

#pragma once
#include "Graphics.h"
#include "Object.h"
#include "Matrix4.h"

class Dragon
{
public:
	Dragon();
	~Dragon() {}

	void init();

	void handleInput();
	void update();
	void render();
private:
	Graphics gph;
	int x, y;
	int step;
};

