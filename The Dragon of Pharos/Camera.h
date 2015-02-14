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

	void setCameraPos(float x, float y, float z);
	void setCameraTarget(float x, float y, float z);
	void setUpVector(float x, float y, float z);

	Vector3D getCameraPos() {return cameraPos;}
	Vector3D getCameraTarget() {return cameraTarget;}
	Vector3D getUpVector() {return upVector;}

	Matrix4 getViewMatrix();
	void rotate(Vector3D angle);

private:
	Camera();
	static Camera* pInstance;

	Vector3D cameraPos;
	Vector3D cameraTarget;
	Vector3D upVector;

	Matrix4 viewMatrix;
};

