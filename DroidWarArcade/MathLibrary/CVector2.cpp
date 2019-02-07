#include "CVector2.h"
#include <math.h>
//Constructor function
CVector2::CVector2() {
	m_fCoordinates[0] = 0.0f;
	m_fCoordinates[1] = 0.0f;
}
//Constructor overload function
CVector2::CVector2(const float x, const float y) {
	m_fCoordinates[0] = x;
	m_fCoordinates[1] = y;
}
//Destructor function
CVector2::~CVector2()
{
}
//Function to get the pointer (the coordinates)
const float* CVector2::GetPointer() const {
	return m_fCoordinates;
}
//Function to return specific axis coordinates
const float CVector2::operator[](const int a_i) const {
	return m_fCoordinates[a_i];
}
//Function to set and return vector coordinates to value of themselves multiplied by a_other
const CVector2 CVector2::operator*(const float a_other) const {
	CVector2 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] * a_other;
	v.m_fCoordinates[1] = this->m_fCoordinates[1] * a_other;
	return v;
}
//Function to set vector coordinates to a_other multiplied by a_other
void CVector2::operator*=(const float a_other) {
	m_fCoordinates[0] *= a_other;
	m_fCoordinates[1] *= a_other;
}
//Function to set and return Cvector2 v as the vector coordinates multiplied by the relevent a_other array elements
const CVector2 CVector2::operator*(const CVector2 &a_other) const {
	CVector2 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] * a_other[0];
	v.m_fCoordinates[1] = this->m_fCoordinates[1] * a_other[1];
	return v;
}
//Function to set the elements of m_fCoordinates to the value of themselves multiplied by a relevant array element
void CVector2::operator*=(const CVector2 &a_other) {
	this->m_fCoordinates[0] *= a_other[0];
	this->m_fCoordinates[1] *= a_other[1];
}
//Function to set and return Cvector2 v as the vector coordinates divided by the relevent a_other array elements
const CVector2 CVector2::operator/(const CVector2 &a_other) const {
	CVector2 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] / a_other[0];
	v.m_fCoordinates[1] = this->m_fCoordinates[1] / a_other[1];
	return v;
}
//Function to set the elements of m_fCoordinates to the value of themselves divided by a relevant array element
void CVector2::operator/=(const CVector2 &a_other) {
	this->m_fCoordinates[0] /= a_other[0];
	this->m_fCoordinates[1] /= a_other[1];
}
//Function to set and return Cvector2 v as the vector coordinates divided by the a_other 
const CVector2 CVector2::operator/(const float a_other) const {
	CVector2 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] / a_other;
	v.m_fCoordinates[1] = this->m_fCoordinates[1] / a_other;
	return v;
}
//Function to set the elements of m_fCoordinates to the value of themselves divided by a_other
void CVector2::operator/=(const float a_other) {
	this->m_fCoordinates[0] /= a_other;
	this->m_fCoordinates[1] /= a_other;
}
//Function to return v from the elements of m_fCoordinates to the value of themselves plus a relevant array element
const CVector2 CVector2::operator+(const CVector2 &a_other) const {
	CVector2 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] + a_other[0];
	v.m_fCoordinates[1] = this->m_fCoordinates[1] + a_other[1];
	return v;
}
//Function to set m_fCoordinates to the value of themselves plus the relevant a_other array element
void CVector2::operator+=(const CVector2 &a_other) {
	this->m_fCoordinates[0] += a_other[0];
	this->m_fCoordinates[1] += a_other[1];
}
//Function to return vectors after having relevant a_other array elements subtracted from them
const CVector2 CVector2::operator-(const CVector2 &a_other) const {
	CVector2 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] - a_other[0];
	v.m_fCoordinates[1] = this->m_fCoordinates[1] - a_other[1];
	return v;
}
//Function to set vectors to themselves minus their relevant a_other array elements
void CVector2::operator-=(const CVector2 &a_other) {
	this->m_fCoordinates[0] -= a_other[0];
	this->m_fCoordinates[1] -= a_other[1];
}
//Function to return the correct magnitude by adding the first vector/coordinates squared to the second squared and square routing all of this
const float CVector2::magnitude() const {
	return (float)(sqrt(m_fCoordinates[0] * m_fCoordinates[0]) + (m_fCoordinates[1] * m_fCoordinates[1]));
}
//Function to return the correct magnitude squared by adding the first vector/coordinates squared to the second squared
const float CVector2::magnitudeSq() const {
	return (m_fCoordinates[0] * m_fCoordinates[0]) + (m_fCoordinates[1] * m_fCoordinates[1]);
}
//Function to returning the calculated distance, this is done by subtracting a_other from this pointer and then using the3 magnitude function on this
const float CVector2::distance(const CVector2 &a_other) const {
	return (*this - a_other).magnitude();
}
//Function to returning the calculated distance squared, this is done by subtracting a_other from this pointer and then using the square magnitude function on this
const float CVector2::distanceSq(const CVector2 &a_other) const {
	return (*this - a_other).magnitudeSq();
}
//Function to return the perpendicular of vector 1 and 2 as a vector 2
const CVector2 CVector2::perpendicular() const {
	return CVector2(-m_fCoordinates[1], m_fCoordinates[0]);
}
//Function to get the dot product by returning the answer of m_fCoordinated array element 0 squared plus m_fCoordinated array element 1 squared
const float CVector2::dotProduct(const CVector2 &a_other) const {
	return (m_fCoordinates[0] * m_fCoordinates[0]) + (m_fCoordinates[1] * m_fCoordinates[1]);
}
//Function to normalise in place the elements in the m_fCoordinates, this is done by dividing each of their array elements by the magnitude function
void CVector2::normaliseInPlace() {
	m_fCoordinates[0] = m_fCoordinates[0] / magnitude();
	m_fCoordinates[1] = m_fCoordinates[1] / magnitude();
}
//Function to return the coordinates after being normalised as seen below
const CVector2 CVector2::normalised() const {
	CVector2 returnthis(m_fCoordinates[0], m_fCoordinates[1]);
	returnthis.normaliseInPlace();
	return returnthis;
}
