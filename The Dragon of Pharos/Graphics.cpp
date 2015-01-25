#include "Graphics.h"
#include <iostream>
#include <cmath>
#include "DoP.h"
#include "Vector3D.h"

Graphics::Graphics()
{

}

void Graphics::drawPixel(float x, float y, Vector3D color)
{
	/*
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	{
	glVertex2i(x, y);
	}
	glEnd();
	*/
	uint8_t r = color.getX();
	uint8_t g = color.getY();
	uint8_t b = color.getZ();

	SDL_SetRenderDrawColor(DoP::Instance()->getRenderer(), r, g, b, 255);
	//SDL_RenderDrawPoint(DoP::Instance()->getRenderer(), x, y);				//origin at top-left-corner
	//SDL_RenderDrawPoint(DoP::Instance()->getRenderer(), x, 600 - y);			//origin at bottom-left-corner
	SDL_RenderDrawPoint(DoP::Instance()->getRenderer(), 400 + x, 300 - y);	//origin at center
}

void Graphics::drawLine(int x1, int y1, int x2, int y2, Vector3D color)
{
	int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
	dx=x2-x1;
	dy=y2-y1;
	dx1=abs(dx);
	dy1=abs(dy);
	px=2*dy1-dx1;
	py=2*dx1-dy1;
	if(dy1<=dx1)
	{
		if(dx>=0)
		{
			x=x1;
			y=y1;
			xe=x2;
		}
		else
		{
			x=x2;
			y=y2;
			xe=x1;
		}
		drawPixel(x, y, color);
		//putpixel(x,y,c);
		for(i=0;x<xe;i++)
		{
			x=x+1;
			if(px<0)
			{
				px=px+2*dy1;
			}
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
				{
					y=y+1;
				}
				else
				{
					y=y-1;
				}
				px=px+2*(dy1-dx1);
			}
			drawPixel(x, y, color);
			//putpixel(x,y,c);
		}
	}
	else
	{
		if(dy>=0)
		{
			x=x1;
			y=y1;
			ye=y2;
		}
		else
		{
			x=x2;
			y=y2;
			ye=y1;
		}
		drawPixel(x, y, color);
		//putpixel(x,y,c);
		for(i=0;y<ye;i++)
		{
			y=y+1;
			if(py<=0)
			{
				py=py+2*dx1;
			}
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
				{
					x=x+1;
				}
				else
				{
					x=x-1;
				}
				py=py+2*(dx1-dy1);
			}
			drawPixel(x, y, color);
			//putpixel(x,y,c);
		}
	}
}

void Graphics::processScanLine(int y, Vector4D pa, Vector4D pb, Vector4D pc, Vector4D pd, Vector3D color)
{
	float gradient1 = pa.getY() != pb.getY() ? (y - pa.getY()) / (pb.getY() - pa.getY()) : 1;
	float gradient2 = pc.getY() != pd.getY() ? (y - pc.getY()) / (pd.getY() - pc.getY()) : 1;

	int sx = pa.getX() + gradient1 * (pb.getX() - pa.getX());
	int ex = pc.getX() + gradient2 * (pd.getX() - pc.getX());

	//std::cout<<"sx: "<<sx<<" ex: "<<ex<<std::endl;
	
	for (int x = sx+1; x < ex; x++)
	{
		//std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
		drawPixel(x, y, color);
	}
}

void Graphics::fillTriangle(Vector4D p1, Vector4D p2, Vector4D p3, Vector3D color)
{
	Vector4D temp;
	float dp1p2, dp1p3;
	if (p1.getY() > p2.getY())
	{
		temp = p2;
		p2 = p1;
		p1 = temp;
	}
	if (p2.getY() > p3.getY())
	{
		temp = p2;
		p2 = p3;
		p3 = temp;
	}
	if (p1.getY() > p2.getY())
	{
		temp = p2;
		p2 = p1;
		p1 = temp;
	}

	if ((p2.getY() - p1.getY()) > 0)
	{
		dp1p2 = (p2.getX()- p1.getX()) / (p2.getY() - p1.getY());
	}
	else
	{
		dp1p2 = 0;
	}
	if ((p3.getY() - p1.getY()) > 0)
	{
		dp1p3 = (p3.getX() - p1.getX()) / (p3.getY() - p1.getY());
	}
	else
	{
		dp1p3 = 0;
	}

	if (dp1p2 > dp1p3)
	{
		for (int y = p1.getY(); y <= (p3.getY()); y++)
		{
			if (y < p2.getY())
			{
				processScanLine(y, p1, p3, p1, p2, color);
			}
			else
			{
				processScanLine(y, p1, p3, p2, p3, color);
			}
		}
	}
	else
	{
		for (int y = p1.getY(); y <= p3.getY(); y++)
		{
			if (y < p2.getY())
			{
				processScanLine(y, p1, p2, p1, p3, color);
			}
			else
			{
				processScanLine(y, p2, p3, p1, p3, color);
			}
		}
	}
}