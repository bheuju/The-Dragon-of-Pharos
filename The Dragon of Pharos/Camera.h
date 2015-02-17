/*************************** Camera **************************
3D Camera
- singleton class
- can return viewMatrix
- initialize cameraPos, cameraTarget, upVector
--------------------------------------------------------------
- added orgCameraPos, orgUpVector to try and standardize
  implementations other functions
- orgCameraPos used in rotate()
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

	//Original camera configs
	void setOrgCameraPos(float x, float y, float z);
	void setOrgUpVector(float x, float y, float z);

	Vector3D getOrgCameraPos() {return orgCameraPos;}

	void setCameraAngle(Vector3D angle);
	void setCameraAngle(float x, float y, float z);
	Vector3D getCameraAngle() {return cameraAngle;}

	Matrix4 getViewMatrix();
	void rotate();

private:
	Camera();
	static Camera* pInstance;

	Vector3D cameraPos;
	Vector3D cameraTarget;
	Vector3D upVector;

	Vector3D orgCameraPos;
	Vector3D orgUpVector;

	Vector3D cameraAngle;

	Matrix4 viewMatrix;
};

