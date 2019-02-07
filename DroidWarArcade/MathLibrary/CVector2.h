//\===========================================================================================================================================
//\ Filename: CVector2.h
//\ Author  : C.A.Bullock
//\ Date    : 28/03/2018
//\ Brief   : This contains all maths logic for a 2 dimensional vector
//\===========================================================================================================================================

#ifndef __CVECTOR2_H__
#define __CVECTOR2_H__

class CVector2
{
public:
#pragma region Overloaded Operators
	//Function to return specific axis coordinates
	const float operator[](const int a_i) const;
	//Function to set and return vector coordinates to value of themselves multiplied by a_other
	const CVector2 operator*(const float a_other) const;
	//Function to set vector coordinates to a_other multiplied by a_other
	void operator*=(const float a_other);
	//Function to set and return Cvector2 v as the vector coordinates multiplied by the relevent a_other array elements
	const CVector2 operator*(const CVector2 &a_other) const;
	//Function to set the elements of m_fCoordinates to the value of themselves multiplied by a relevant array element
	void operator*=(const CVector2 &a_other);
	//Function to set and return Cvector2 v as the vector coordinates divided by the relevent a_other array elements
	const CVector2 operator/(const CVector2 &a_other) const;
	//Function to set the elements of m_fCoordinates to the value of themselves divided by a relevant array element
	void operator/=(const CVector2 &a_other);
	//Function to set and return Cvector2 v as the vector coordinates divided by the a_other 
	const CVector2 operator/(const float a_other) const;
	//Function to set the elements of m_fCoordinates to the value of themselves divided by a_other
	void operator/=(const float a_other);
	//Function to return v from the elements of m_fCoordinates to the value of themselves plus a relevant array element
	const CVector2 operator+(const CVector2 &a_other) const;
	//Function to set m_fCoordinates to the value of themselves plus the relevant a_other array element
	void operator+=(const CVector2 &a_other);
	//Function to return vectors after having relevant a_other array elements subtracted from them
	const CVector2 operator-(const CVector2 &a_other) const;
	//Function to set vectors to themselves minus their relevant a_other array elements
	void operator-=(const CVector2 &a_other);
#pragma endregion
#pragma region Public Functions
	//Function to return the correct magnitude by adding the first vector/coordinates squared to the second squared and square routing all of this
	const float magnitude() const;
	//Function to return the correct magnitude squared by adding the first vector/coordinates squared to the second squared
	const float magnitudeSq() const;
	//Function to returning the calculated distance, this is done by subtracting a_other from this pointer and then using the3 magnitude function on this
	const float distance(const CVector2 &a_other) const;
	//Function to returning the calculated distance squared, this is done by subtracting a_other from this pointer and then using the square magnitude function on this
	const float distanceSq(const CVector2 &a_other) const;
	//Function to return the perpendicular of vector 1 and 2 as a vector 2
	const CVector2 perpendicular() const;
	//Function to get the dot product by returning the answer of m_fCoordinated array element 0 squared plus m_fCoordinated array element 1 squared
	const float dotProduct(const CVector2 &a_other) const;
	//Function to normalise in place the elements in the m_fCoordinates, this is done by dividing each of their array elements by the magnitude function
	void normaliseInPlace();
	//Function to return the coordinates after being normalised as seen below
	const CVector2 normalised() const;
	//Function to get the pointer (the coordinates)
	const float* GetPointer() const;
#pragma endregion

#pragma region Constructors/Destructors
	//Constructor overload function
	CVector2(float a_x, float a_y);
	//Constructor function
	CVector2();
	//Destructor function
	~CVector2();
#pragma endregion

private:
	float m_fCoordinates[2];
};

#endif __CVECTOR2_H__