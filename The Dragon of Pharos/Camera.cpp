#include "Camera.h"
Camera* Camera::pInstance = 0;

Camera::Camera()
{

}

void Camera::setCameraPos(int x, int y, int z)
{
	cameraPos = Vector3D(x, y, z);
}

void Camera::setCameraTarget(int x, int y, int z)
{
	cameraTarget = Vector3D(x, y, z);
}

void Camera::setUpVector(int x, int y, int z)
{
	upVector = Vector3D(x, y, z);
}

Matrix4 Camera::getViewMatrix()
{
	return(Matrix4().setViewMatrix(cameraPos, cameraTarget, upVector));
}
