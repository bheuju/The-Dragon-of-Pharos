#include "Camera.h"
Camera* Camera::pInstance = 0;

Camera::Camera()
{

}

void Camera::setCameraPos(float x, float y, float z)
{
	cameraPos = Vector3D(x, y, z);
}

void Camera::setCameraTarget(float x, float y, float z)
{
	cameraTarget = Vector3D(x, y, z);
}

void Camera::setUpVector(float x, float y, float z)
{
	upVector = Vector3D(x, y, z);
}

void Camera::setOrgCameraPos(float x, float y, float z)
{
	orgCameraPos = Vector3D(x, y, z);
}

void Camera::setOrgUpVector(float x, float y, float z)
{
	orgUpVector = Vector3D(x, y, z);
}

Matrix4 Camera::getViewMatrix()
{
	return(Matrix4().setViewMatrix(cameraPos, cameraTarget, upVector));
}

void Camera::rotate(Vector3D angle)
{
	//displayVector3D(angle, "Rotation Angle", 1);

	//Vector4D pos = Vector4D(cameraPos - cameraTarget);
	//float x = pos.getX();
	//float y = pos.getY();
	//float z = pos.getZ();

	//Matrix4 transformMatrix = Matrix4().setTranslationMatrix(-x, -y, -z) * Matrix4().setRotation(angle.getX(), angle.getY(), angle.getZ()) * Matrix4().setTranslationMatrix(x, y, z);
	//Matrix4 transformMatrix = Matrix4().setTranslationMatrix(x, y, z) * Matrix4().setRotation(angle.getX(), angle.getY(), angle.getZ()) * Matrix4().setTranslationMatrix(-x, -y, -z);
	Matrix4 transformMatrix = Matrix4().setRotation(angle.getX(), angle.getY(), angle.getZ());

	Vector4D post = transformMatrix * Vector4D(orgCameraPos);

	cameraPos.setX(post.getX());
	cameraPos.setY(post.getY());
	cameraPos.setZ(post.getZ());

	//displayVector3D(cameraPos, "Camera Position", 1);
}