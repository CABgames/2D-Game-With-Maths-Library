//\===========================================================================================================================================
//\ Filename: CMatrix3.h
//\ Author  : C.A.Bullock
//\ Date    : 28/03/2018
//\ Brief   : This function all maths logic for a multidimensional matrix
//\===========================================================================================================================================

#ifndef __CVECTOR3_H__
#define __CVECTOR3_H__

//Forward declarations, to avoid having headers in headers except where intentional (overarching mathlib.h)
class CVector3;

class CMatrix3
{
public:
	//Identity matrix function returning an identity matrix
	static const CMatrix3 Identity();
#pragma region Getters and Setters
	//Function to return the requested for, for example a_irowNumber being 1 will return a vector 3 containing  matrix values of 3,4, and 5
	const CVector3 GetRow(const int a_irowNumber) const;
	//Function to set the requested matrix row based upon the value of a_irowNumber
	void SetRow(const int a_irowNumber, const CVector3 &a_rowValues);
#pragma endregion
#pragma region Rotations
	//Function to rotate the X axis within 3 dimensions
	const CMatrix3 RotateX(const float a_ftheta) const;
	//Function to rotate the Y axis within 3 dimensions
	const CMatrix3 RotateY(const float a_ftheta) const;
	//Function to rotate the Z axis within 3 dimensions
	const CMatrix3 RotateZ(const float a_ftheta) const;
#pragma endregion
#pragma region overloaded operators
	//Function to do and return a matrix with addition done to it on it's relevant rows
	const CMatrix3 operator+(const CMatrix3 &a_other) const;
	//Function to add another value to the relevant value inside the matrix
	void operator+=(const CMatrix3 &a_other);
	//Function to do and return a matrix with subtraction done to it on it's relevant rows
	const CMatrix3 operator-(const CMatrix3 &a_other) const;
	//Function to subtract another value to the relevant value inside the matrix
	void operator-=(const CMatrix3 &a_other);
	//Function to do and return a matrix with multiplication done to it
	const CMatrix3 operator*(const CMatrix3 &a_other) const;
	//Function to do a matrix with multiplication done to it on it's relevant values
	void operator*=(const CMatrix3 &a_other);
	//Function to do a matrix with multiplication done to it
	const CMatrix3 operator*(const float &a_other) const;
	//Function to do a matrix with multiplication done to it
	void operator*=(const float &a_other);
	//Function to return the value if all the other matrix values are equal to this matrix value relevant to them respectively
	const bool operator==(const CMatrix3 &a_other) const;
	//Function to return the value if all the other matrix values are not equal to this matrix value relevant to them respectively
	const bool operator!=(const CMatrix3 &a_other) const;
	//Function to return the requested matrix value based upon value of i
	const float operator[](const int i) const;
#pragma endregion

#pragma region Constructors/Destructors
	//Constructor function to set all the values in the m_fMatrixValues array to 0
	CMatrix3();
	//Constructor overload function to set the matrix values to relevant float variables
	CMatrix3(const float a_fm11, const float a_fm12, const float a_fm13,
		const float a_fm21, const float a_fm22, const float a_fm23,
		const float a_fm31, const float a_fm32, const float a_fm33);
	//Constructor overload function to set the matrix values to relevant float variables array 
	CMatrix3(const float *a_fpm33Values);
	//Destructor function
	~CMatrix3();
#pragma endregion

private:
	static const int sc_iCollumns = 3;
	static const int sc_iRows = 3;
	float m_fMatrixValues[9];
};

#endif __CVECTOR3_H__