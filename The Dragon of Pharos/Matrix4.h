/************************** Matrix4 **************************
4D Matrix
- uses row
- handle matrix operations
- translation, rotation, scaling
- multiplication
- generate special matrices (model, view, projection)
--------------------------------------------------------------

**************************************************************/

#pragma once
#include <iostream>
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
	void setTranslationMatrix(float tX = 0, float tY = 0, float tZ = 0);
	void setRotationX(float theta = 0);
	void setRotationY(float theta = 0);
	void setRotationZ(float theta = 0);
	void setScaleMatrix(float sX = 1, float sY = 1, float sZ = 1);

	//Extra matrices
	Matrix4 setModelMatrix(Matrix4 translation, Matrix4 rotation, Matrix4 scale);
	Matrix4 setViewMatrix(Vector3D cameraPos, Vector3D cameraTarget, Vector3D upVector);
	Matrix4 setProjectionMatrix(float fovy, float aspect, float zNear, float zFar);

	friend void displayMatrix(Matrix4 m)
	{
		std::cout.precision(3);
		std::cout<<"=============================="<<std::endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout<<m.mat[i][j]<<"\t";
			}
			std::cout<<"\n";
		}
		std::cout<<"=============================="<<std::endl;
	}

private:
	float mat[4][4];
};

