/************************** Graphics *************************
Graphics Class
- handle graphics
- line drawing
- pixel plotting
--------------------------------------------------------------
Singleton class
**************************************************************/

#pragma once
class Graphics
{
public:
	Graphics();
	~Graphics() {}

	void drawPixel(float x, float y);
	void drawLine(int x1, int y1, int x2, int y2);

};

