//\===========================================================================================================================================
//\ Filename: CVector3.h
//\ Author  : C.A.Bullock
//\ Date    : 28/03/2018
//\ Brief   : This function contains all maths logic for a 3 dimensional vector
//\===========================================================================================================================================

#ifndef CVECTOR3_H
#define CVECTOR3_H

class CVector2;
class CMatrix3;
class CVector3 {
public:
#pragma region Overloaded Operators
	//Function to return the coordinate by a_i variable
	const float operator[](const int a_i) const;
	//Function to return the vector coordinates multiplied by themselves and a_other
	const CVector3 operator*(const float a_other) const;
	//Function to set the vector coordinates multiplied by themselves and a_other
	void operator*=(const float a_other);
	//Function to return the perpendicular of vector 1 and 2 but as a vector 3
	const CVector3 perpendicular() const;
	//Function to return the vector coordinates multiplied by themselves and a_other
	const CVector3 operator*(const CVector3 &a_other) const;
	//Function to set the vector coordinates multiplied by themselves and a_other
	void operator*=(const CVector3 &a_other);
	//Function to return the vector coordinates divided by themselves and a_other
	const CVector3 operator/(const CVector3 &a_other) const;
	//Function to set the vector coordinates divided by themselves and a_other array
	void operator/=(const CVector3 &a_other);
	//Function to set and return the vector coordinates divided by themselves and a_other
	const CVector3 operator/(const float a_other) const;
	//Function to divide the vectors by themselves and a_other
	void operator/=(const float a_other);
	//Function to return 3 vectors multiplied by 3 specific different elements from the a_other array respectively (for each of the 3 rows)
	const CVector3 operator*(const CMatrix3 &a_other) const;
	//Function to return vectors multiplied by relevant a_other array elements 
	const CVector3 operator+(const CVector3 &a_other) const;
	//Function to return vectors after relevant a_other array elements have been added 
	const CVector3 operator+=(const CVector3 &a_other);
	//Function to return vectors after having relevant a_other array elements subtracted from them
	const CVector3 operator-(const CVector3 &a_other) const;
	//Function to return vectors minus their relevant a_other array elements
	const CVector3 operator-=(const CVector3 &a_other);
#pragma endregion

#pragma region Public Functions
	//Function to return the correct magnitude by adding the first vector/coordinates squared to the second squared to the third squared and square routing all of this
	const float magnitude() const;
	//Function to return the correct magnitude squared by adding the first vector/coordinates squared to the second squared to the third squared
	const float magnitudeSq() const;
	//Function to returning the calculated distance, this is done by subtracting a_other from this pointer and then using the3 magnitude function on this
	const float distance(const CVector3 &a_other) const;
	//Function to returning the calculated distance squared, this is done by subtracting a_other from this pointer and then using the square magnitude function on this
	const float distanceSq(const CVector3 &a_other) const;
	//Function to get the dot product by returning the answer of m_fCoordinated array element 0 squared plus m_fCoordinated array element 1 squared plus m_fCoordinated array element 2 squared
	const float dotProduct(const CVector3 &a_other) const;
	//Cross product function returns x,y, and z coordinates as a vector 3, for each of these coordinates a m_fCoordinates array element is multiplied by another array element then added to the same thing 
	const CVector3 crossProduct(const CVector3 &a_rv3a) const;
	//Function to normalise in place the elements in the m_fCoordinates, this is done by dividing each of their array elements by the magnitude function
	void normaliseInPlace();
	//Function to return the coordinates after being normalised as seen below
	const CVector3 normalised() const;
	//Function to return the coordinated/pointer
	const float* GetPointer() const;
#pragma endregion

	float m_fCoordinates[3];
#pragma region Constructors/Destructors
	//Overload unction to set each element in the m_fCoordinates array to a variables for their relevant axis (m_fCoordinates[1] = a_y)
	CVector3(float a_x, float a_y, float a_z);
	//Overload function set each element im the array except the last to one element from other array
	CVector3(CVector2 other);
	//Constructor function
	CVector3();
	//Destructor function
	~CVector3();
#pragma endregion
private:
};

#endif __POWERUP4_H__