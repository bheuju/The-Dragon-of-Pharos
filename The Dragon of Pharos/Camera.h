/*************************** Camera **************************
3D Camera
- singleton class
- can return viewMatrix
- initialize cameraPos, cameraTarget, upVector
--------------------------------------------------------------

**************************************************************/

#pragma once
#include "Vector3D.h"
#include "Matrix4.h"

class Camera
{
public:
	static Camera* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new Camera();
		}
		return pInstance;
	}

	~Camera() {}

	void setCameraPos(int x, int y, int z);
	void setCameraTarget(int x, int y, int z);
	void setUpVector(int x, int y, int z);

	Vector3D getCameraPos() {return cameraPos;}
	Vector3D getCameraTarget() {return cameraTarget;}
	Vector3D getUpVector() {return upVector;}

	Matrix4 getViewMatrix();

private:
	Camera();
	static Camera* pInstance;

	Vector3D cameraPos;
	Vector3D cameraTarget;
	Vector3D upVector;

	Matrix4 viewMatrix;
};

