/************************** Matrix4 **************************
4D Matrix
- uses row
- handle matrix operations
- translation, rotation, scaling
- multiplication //TODO
--------------------------------------------------------------

**************************************************************/

#pragma once
#include <cmath>
#include "Vector3D.h"
#include "Vector4D.h"

#define PI	3.1416

class Matrix4
{
public:
	Matrix4();
	Matrix4(float matrix[4][4]);
	Matrix4(Vector4D v1, Vector4D v2, Vector4D v3, Vector4D v4);
	~Matrix4() {}

	void reset();
	void setIdentityMatrix();

	//Operations
	Matrix4 operator* (Matrix4& mat1);						//matrix - matrix multiplication
	friend Vector4D operator* (Matrix4& mat, Vector4D& v);	//matrix - vector multiplication

	//Transformation matrices
	void setTranslationMatrix(float tX, float tY, float tZ);
	void setRotationX(float theta);
	void setRotationY(float theta);
	void setRotationZ(float theta);
	void setScaleMatrix(float sX, float sY, float sZ);

	//Extra matrices
	Matrix4 setModelMatrix(Matrix4 translation, Matrix4 rotation, Matrix4 scale);
	Matrix4 setViewMatrix(Vector3D cameraPos, Vector3D cameraTarget, Vector3D upVector);
	Matrix4 setProjectionMatrix(float fovy, float aspect, float zNear, float zFar);

private:
	float mat[4][4];
};

