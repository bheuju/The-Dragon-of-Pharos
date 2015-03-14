#include "Graphics.h"
#include <iostream>
#include <cmath>
#include "DoP.h"
#include "Vector3D.h"
#include <SDL_opengl.h>

Graphics* Graphics::pInstance = 0; 

Graphics::Graphics()
{

}

void Graphics::putPixel(float x, float y, float z, Vector3D color)
{
	//for (each pixel (x, y))
	//{
	//	z-depth at (x,y) = z;
	//	if (z-depth < zBuffer(x, y))
	//	{
	//		write point to frameBuffer; i.e vector4d(x, y, z);
	//		zBuffer(x, y) = z-depth;
	//	}
	//}

	//clipping before writing to frameBuffer
	if (x < -400 || y < -300 || x > 400 || y > 300)
		//if (x < -200 || y < -100 || x > 200 || y > 100)
	{
		return;
	}

	float zDepth = z;
	int xp = (int) (x + 400 );
	int yp = (int) (300 - y);

	//std::cout<<"x: "<<xp<<" y: "<<yp<<std::endl;

	//std::cout<<"zDepth: "<<zDepth<<"\tzBuffer: "<<zBuffer[xp][yp]<<std::endl;
	//if the point is further from previous one, do nothing (return)
	if (zDepth > zBuffer[xp][yp])
	{
		return;
	}
	//displayVector4D(frameBuffer.back());

	frameBuffer.push_back(Vector4D(x, y, z));
	colorBuffer.push_back(color);

	//frameBuffer[xp][yp] = Vector4D(x, y, z);
	//colorBuffer[xp][yp] = color;

	zBuffer[xp][yp] = zDepth;

	//std::cout<<"Real: "<<frameBuffer.size()<<std::endl;
}

void Graphics::drawPixel(float x, float y, float z, Vector3D color)
{
	//std::cout<<"Drawn";
	if (DoP::Instance()->getMode() == OPENGL)
	{
		float r = color.getX() / 255.0;
		float g = color.getY() / 255.0;
		float b = color.getZ() / 255.0;

		glColor3f(r, g, b);

		glBegin(GL_POINTS);
		{
			//glVertex2i(x, y);				//origin at top-left-corner
			//glVertex2i(x, 600 - y);		//origin at bottom-left-corner
			glVertex2i(400 + x, 300 - y);	//origin at center
		}
		glEnd();
	}
	else if (DoP::Instance()->getMode() == SDL)
	{
		int r = color.getX();
		int g = color.getY();
		int b = color.getZ();

		SDL_SetRenderDrawColor(DoP::Instance()->getRenderer(), r, g, b, 255);
		//SDL_RenderDrawPoint(DoP::Instance()->getRenderer(), x, y);				//origin at top-left-corner
		//SDL_RenderDrawPoint(DoP::Instance()->getRenderer(), x, 600 - y);			//origin at bottom-left-corner
		SDL_RenderDrawPoint(DoP::Instance()->getRenderer(), 400 + x, 300 - y);		//origin at center
	}
}

void Graphics::drawLine(int x1, int y1, int x2, int y2, Vector3D color, float lineZ)
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
		//drawPixel(x, y, 1000, color);
		putPixel(x, y, lineZ, color);
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
			//drawPixel(x, y, 1000, color);
			putPixel(x, y, lineZ, color);
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
		//drawPixel(x, y, 1000, color);
		putPixel(x, y, lineZ, color);
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
			//drawPixel(x, y, 1000, color);
			putPixel(x, y, lineZ, color);
		}
	}
}

void Graphics::processScanLine(int y, Vector4D pa, Vector4D pb, Vector4D pc, Vector4D pd, Vector3D color)
{
	float gradient1 = pa.getY() != pb.getY() ? (y - pa.getY()) / (pb.getY() - pa.getY()) : 1;
	float gradient2 = pc.getY() != pd.getY() ? (y - pc.getY()) / (pd.getY() - pc.getY()) : 1;

	//clamping between 0-1
	gradient1 = gradient1 < 0 ? 0 : (gradient1 > 1 ? 1 : gradient1);
	gradient2 = gradient2 < 0 ? 0 : (gradient2 > 1 ? 1 : gradient2);

	//displayVector4D(pa, "pa", 1);
	//displayVector4D(pb, "pb", 1);
	//displayVector4D(pc, "pc", 1);
	//displayVector4D(pd, "pd", 1);

	//interpolating start and end points
	int sx = pa.getX() + gradient1 * (pb.getX() - pa.getX());
	int ex = pc.getX() + gradient2 * (pd.getX() - pc.getX());

	//change start and end point
	if (sx > ex)
	{
		int temp = sx;
		sx = ex;
		ex = temp;
	}

	float z1 = pa.getZ() + gradient1 * (pb.getZ() - pa.getZ());
	float z2 = pc.getZ() + gradient2 * (pd.getZ() - pc.getZ());

	//std::cout<<"At y: "<<y<<" sx: "<<(sx)<<" ex: "<<(ex)<<std::endl;

	//std::cout<<"z1: "<<z1<<"\tz2: "<<z2<<std::endl;

	for (int x = sx; x < ex; x++)
	{
		//std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
		float gradient = (x - sx) / (float)(ex - sx);

		//interpolating value of z - for zBuffer test
		float z = z1 + gradient * (z2 - z1);
		//std::cout<<"DZ: "<<z<<std::endl;
		//drawPixel(x, y, z, color);
		//write to frameBuffer
		putPixel(x, y, z, color);
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

	//std::cout<<p2.getY()<<" "<<p1.getY()<<std::endl;
	if ((p2.getY() - p1.getY()) > 0)
	{
		dp1p2 = (p2.getX()- p1.getX()) / (p2.getY() - p1.getY());
	}
	else
	{
		dp1p2 = 0;
	}
	//std::cout<<p3.getY()<<" "<<p1.getY()<<std::endl;
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
		for (int y = (int)p1.getY(); y <= (int)(p3.getY()); y++)
		{
			//std::cout<<y<<" "<<p2.getY()<<std::endl;
			if (y < p2.getY())
			{
				//upper triangle
				processScanLine(y, p1, p3, p1, p2, color);
			}
			else
			{
				//lower triangle
				processScanLine(y, p1, p3, p2, p3, color);
			}
		}
	}
	else
	{
		for (int y = (int)p1.getY(); y <= (int)p3.getY(); y++)
		{
			//std::cout<<y<<" "<<p2.getY()<<std::endl;
			if (y < p2.getY())
			{
				//upper triangle
				processScanLine(y, p1, p2, p1, p3, color);
			}
			else
			{
				//lower triangle
				processScanLine(y, p2, p3, p1, p3, color);
			}
		}
	}
}

void Graphics::clearBuffer()
{
	//clear frameBuffer
	frameBuffer.clear();
	//clear colorBuffer
	colorBuffer.clear();

	//reset zBuffer
	for (int i = 0; i < 801; i++)
	{
		for (int j = 0; j < 601; j++)
		{
			zBuffer[i][j] = 500;
		}
	}
}

void Graphics::render()
{
	//std::cout<<frameBuffer.size()<<std::endl;
	for (int i = 0; i < frameBuffer.size(); i++)
		//for (int i = frameBuffer.size()-1; i >= 0; i--)
	{
		float x = frameBuffer[i].getX();
		float y = frameBuffer[i].getY();
		float z = frameBuffer[i].getZ();

		Vector3D color = colorBuffer[i];

		drawPixel(x, y, z, color);
	}
}