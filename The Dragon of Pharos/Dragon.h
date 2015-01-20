/********************** Dragon of Pharos **********************
Dragon Class
- consists all about dragon
- model space of each parts
- wireframe
--------------------------------------------------------------

**************************************************************/

#pragma once
#include "Graphics.h"

class Dragon
{
public:
	Dragon();
	~Dragon() {}

	void render();

private:
	Graphics gph;
};

