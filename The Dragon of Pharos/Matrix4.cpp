#include "Matrix4.h"


Matrix4::Matrix4()
{
	reset();
}

Matrix4::Matrix4(float matrix[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat[i][j] = matrix[i][j];
		}
	}
}

Matrix4::Matrix4(Vector4D v0, Vector4D v1, Vector4D v2, Vector4D v3)
{
	mat[0][0] = v0.getX();
	mat[0][1] = v0.getY();
	mat[0][2] = v0.getZ();
	mat[0][3] = v0.getW();

	mat[1][0] = v1.getX();
	mat[1][1] = v1.getY();
	mat[1][2] = v1.getZ();
	mat[1][3] = v1.getW();

	mat[2][0] = v2.getX();
	mat[2][1] = v2.getY();
	mat[2][2] = v2.getZ();
	mat[2][3] = v2.getW();

	mat[3][0] = v3.getX();
	mat[3][1] = v3.getY();
	mat[3][2] = v3.getZ();
	mat[3][3] = v3.getW();
}

void Matrix4::reset()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat[i][j] = 0;
		}
	}
}

void Matrix4::setIdentityMatrix()
{
	reset();
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
}

//Matrix operations
//matrix * matrix
Matrix4 Matrix4::operator* (Matrix4& mat1)
{
	Matrix4 m;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m.mat[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				m.mat[i][j] += this->mat[i][k] * mat1.mat[k][j];
			}
		}
	}

	return m;
}

//matrix * vector
Vector4D operator* (Matrix4& m, Vector4D& v)
{
	Vector4D vector;

	float x = v.getX() * m.mat[0][0] + v.getY() * m.mat[0][1] + v.getZ() * m.mat[0][2] + v.getW() * m.mat[0][3];
	float y = v.getX() * m.mat[1][0] + v.getY() * m.mat[1][1] + v.getZ() * m.mat[1][2] + v.getW() * m.mat[1][3];
	float z = v.getX() * m.mat[2][0] + v.getY() * m.mat[2][1] + v.getZ() * m.mat[2][2] + v.getW() * m.mat[2][3];
	float w = v.getX() * m.mat[3][0] + v.getY() * m.mat[3][1] + v.getZ() * m.mat[3][2] + v.getW() * m.mat[3][3];

	vector.setX(x);
	vector.setY(y);
	vector.setZ(z);
	vector.setW(w);

	return vector;
}

//Transformation Matrices
//Translation
Matrix4 Matrix4::setTranslationMatrix(float tX, float tY, float tZ)
{
	setIdentityMatrix();
	mat[0][3] = tX;
	mat[1][3] = tY;
	mat[2][3] = tZ;

	return *this;
}
//Rotations
Matrix4 Matrix4::setRotationX(float theta)
{
	float angle = (PI / 180) * theta;
	setIdentityMatrix();
	mat[1][1] = cos(theta);
	mat[1][2] = -sin(theta);
	mat[2][1] = sin(theta);
	mat[2][2] = cos(theta);
	return *this;
}
Matrix4 Matrix4::setRotationY(float theta)
{
	float angle = (PI / 180) * theta;
	setIdentityMatrix();
	mat[0][0] = cos(theta);
	mat[2][0] = -sin(theta);
	mat[0][2] = sin(theta);
	mat[2][2] = cos(theta);
	return *this;
}
Matrix4 Matrix4::setRotationZ(float theta)
{
	float angle = (PI / 180) * theta;
	setIdentityMatrix();
	mat[0][0] = cos(theta);
	mat[0][1] = -sin(theta);
	mat[1][0] = sin(theta);
	mat[1][1] = cos(theta);
	return *this;
}
Matrix4 Matrix4::setRotation(float thetaX, float thetaY, float thetaZ)
{
	//displayMatrix(setRotationX(thetaX), "X");
	//displayMatrix(setRotationY(thetaY), "Y");
	//displayMatrix(setRotationZ(thetaZ), "Z");

	Matrix4 rotate = setRotationX(thetaX) * setRotationY(thetaY) * setRotationZ(thetaZ);
	
	//displayMatrix(rotate, "All");
	return (rotate);
}
//Scaling
Matrix4 Matrix4::setScaleMatrix(float sX, float sY, float sZ)
{
	setIdentityMatrix();
	mat[0][0] = sX;
	mat[1][1] = sY;
	mat[2][2] = sZ;

	return *this;
}


//Extra matrices
Matrix4 Matrix4::setModelMatrix(Matrix4 translation, Matrix4 rotation, Matrix4 scale)
{
	Matrix4 modelMatrix = (translation * rotation * scale);
	return modelMatrix;
}

Matrix4 Matrix4::setViewMatrix(Vector3D cameraPos, Vector3D cameraTarget, Vector3D upVector)
{
	Vector3D zAxis = normalize(cameraPos - cameraTarget);
	Vector3D xAxis = normalize(cross(upVector, zAxis));
	Vector3D yAxis = cross(zAxis, xAxis);

	//create a 4x4 orientation matrix
	//this is transposed which is eqvt. to performing an inverse
	//if the matrix is orthonormalized (in this case, it is)
	Matrix4 orientation (
		Vector4D(	xAxis.getX(),	xAxis.getY(),	xAxis.getZ(),	0 ),
		Vector4D(	yAxis.getX(),	yAxis.getY(),	yAxis.getZ(),	0 ),
		Vector4D(	zAxis.getX(),	zAxis.getY(),	zAxis.getZ(),	0 ),
		Vector4D(	0,				0,				0,				1 )
		);

	//create 4x4 tralslation matrix
	//cameraPos is negelected which is eqvt
	//to the inverse of the translation matrix
	Matrix4 translation (
		Vector4D(	1,	0,	0,	-cameraPos.getX()	),
		Vector4D(	0,	1,	0,	-cameraPos.getY()	),
		Vector4D(	0,	0,	1,	-cameraPos.getZ()	),
		Vector4D(	0,	0,	0,		1				)
		);

	//combine the orientation and translation to compute
	//the final view matrix
	return (orientation * translation);

	/**
	Simplified form
	***************
	Vector3D zAxis = normalize(cameraPos - cameraTarget);	// The "forward" vector.
	Vector3D xAxis = normalize(cross(upVector, zAxis));		// The "right" vector.
	Vector3D yAxis = cross(zAxis, xAxis);					// The "up" vector.

	//Create a 4x4 view matrix from
	//the right, up, forward and eye position vectors
	Matrix4 viewMatrix (
	Vector4D(	xAxis.getX(),			xAxis.getY(),			xAxis.getZ(),			0 ),
	Vector4D(	yAxis.getX(),			yAxis.getY(),			yAxis.getZ(),			0 ),
	Vector4D(	zAxis.getX(),			zAxis.getY(),			zAxis.getZ(),			0 ),
	Vector4D(	-dot(xAxis, cameraPos),	-dot(yAxis, cameraPos),	-dot(zAxis, cameraPos),	1 )
	);
	return viewMatrix;
	*/
}

Matrix4 Matrix4::setProjectionMatrix(float fovy, float aspect, float zNear, float zFar)
{
	float angle = (PI / 180) * fovy;
	reset();
	mat[0][0] = aspect * (1.0 / (tan(angle * 0.5)));
	mat[1][1] = 1.0 / (tan(angle * 0.5));
	mat[2][2] = -((zFar + zNear) / (zFar - zNear));
	mat[2][3] = -((2 * zFar * zNear) / (zFar - zNear));
	mat[3][2] = -1;
	return *this;
}

