#include "CVector3.h"
#include "CVector2.h"
#include "CMatrix3.h"
#include <math.h>
//Function to return the coordinate by a_i variable
const float CVector3::operator[](const int a_i) const{
	return m_fCoordinates[a_i];
}
//Function to return the vector coordinates multiplied by themselves and a_other
const CVector3 CVector3::operator*(const float a_other) const{
	CVector3 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] * a_other;
	v.m_fCoordinates[1] = this->m_fCoordinates[1] * a_other;
	v.m_fCoordinates[2] = this->m_fCoordinates[2] * a_other;
	return v;
}
//Function to set the vector coordinates multiplied by themselves and a_other
void CVector3::operator*=(const float a_other){
	m_fCoordinates[0] *= a_other;
	m_fCoordinates[1] *= a_other;
	m_fCoordinates[2] *= a_other;
}
//Function to return the vector coordinates multiplied by themselves and a_other
const CVector3 CVector3::operator*(const CVector3 & a_other) const{
	CVector3 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] * a_other[0];
	v.m_fCoordinates[1] = this->m_fCoordinates[1] * a_other[1];
	v.m_fCoordinates[2] = this->m_fCoordinates[2] * a_other[2];
	return *this;
}
//Function to set the vector coordinates multiplied by themselves and a_other array
void CVector3::operator*=(const CVector3 & a_other){
	m_fCoordinates[0] *= a_other[0];
	m_fCoordinates[1] *= a_other[1];
	m_fCoordinates[2] *= a_other[2];
}
//Function to return the vector coordinates divided by themselves and a_other
const CVector3 CVector3::operator/(const CVector3 & a_other) const{
	CVector3 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] / a_other[0];
	v.m_fCoordinates[1] = this->m_fCoordinates[1] / a_other[1];
	v.m_fCoordinates[2] = this->m_fCoordinates[2] / a_other[2];
	return v;
}
//Function to set the vector coordinates divided by themselves and a_other array
void CVector3::operator/=(const CVector3 & a_other){
	m_fCoordinates[0] /= a_other[0];
	m_fCoordinates[1] /= a_other[1];
	m_fCoordinates[2] /= a_other[2];
}
//Function to set and return the vector coordinates divided by themselves and a_other
const CVector3 CVector3::operator/(const float a_other) const{
	CVector3 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] / a_other;
	v.m_fCoordinates[1] = this->m_fCoordinates[1] / a_other;
	v.m_fCoordinates[2] = this->m_fCoordinates[2] / a_other;
	return v;
}
//Function to divide the vectors by themselves and a_other
void CVector3::operator/=(const float a_other){
	m_fCoordinates[0] /= a_other;
	m_fCoordinates[1] /= a_other;
	m_fCoordinates[2] /= a_other;
}
//Function to return the perpendicular of vector 1 and 2 but as a vector 3
const CVector3 CVector3::perpendicular() const{
	return CVector3(-m_fCoordinates[1], m_fCoordinates[0], 1);
}
//Function to return 3 vectors multiplied by 3 specific different elements from the a_other array respectively (for each of the 3 rows)
const CVector3 CVector3::operator*(const CMatrix3 & a_other) const{
	CVector3 v;
	v.m_fCoordinates[0] = (m_fCoordinates[0] * a_other[0]) + (m_fCoordinates[0] * a_other[3]) + (m_fCoordinates[0] * a_other[6]);
	v.m_fCoordinates[1] = (m_fCoordinates[1] * a_other[1]) + (m_fCoordinates[1] * a_other[4]) + (m_fCoordinates[1] * a_other[7]);
	v.m_fCoordinates[2] = (m_fCoordinates[2] * a_other[2]) + (m_fCoordinates[2] * a_other[5]) + (m_fCoordinates[2] * a_other[8]);
	return v;
}
//Function to return vectors multiplied by relevant a_other array elements 
const CVector3 CVector3::operator+(const CVector3 &a_other) const{
	CVector3 v;
	v.m_fCoordinates[0] = this->m_fCoordinates[0] + a_other[0];
	v.m_fCoordinates[1] = this->m_fCoordinates[1] + a_other[1];
	v.m_fCoordinates[2] = this->m_fCoordinates[2] + a_other[2];
	return v;
}
//Function to return vectors after relevant a_other array elements have been added 
const CVector3 CVector3::operator+=(const CVector3 &a_other){
	this->m_fCoordinates[0] += a_other[0];
	this->m_fCoordinates[1] += a_other[1];
	this->m_fCoordinates[2] += a_other[2];
	return *this;
}
//Function to return vectors after having relevant a_other array elements subtracted from them
const CVector3 CVector3::operator-(const CVector3 &a_other) const{
	CVector3 v;
	v.m_fCoordinates[0] = this-> m_fCoordinates[0] - a_other[0];
	v.m_fCoordinates[1] = this->m_fCoordinates[1] - a_other[1];
	v.m_fCoordinates[2] = this->m_fCoordinates[2] - a_other[2];
	return v;
}
//Function to return vectors minus their relevant a_other array elements
const CVector3 CVector3::operator-=(const CVector3 &a_other){
	this->m_fCoordinates[0] -= a_other[0];
	this->m_fCoordinates[1] -= a_other[1];
	this->m_fCoordinates[2] -= a_other[2];
	return *this;
}
//Function to return the correct magnitude by adding the first vector/coordinates squared to the second squared to the third squared and square routing all of this
const float CVector3::magnitude() const{
	return sqrt(m_fCoordinates[0] * m_fCoordinates[0]) + (m_fCoordinates[1] * m_fCoordinates[1]) + (m_fCoordinates[2] * m_fCoordinates[2]);
}
//Function to return the correct magnitude squared by adding the first vector/coordinates squared to the second squared to the third squared
const float CVector3::magnitudeSq() const{
	return (m_fCoordinates[0] * m_fCoordinates[0]) + (m_fCoordinates[1] * m_fCoordinates[1]) + (m_fCoordinates[2] * m_fCoordinates[2]);
}
//Function to returning the calculated distance, this is done by subtracting a_other from this pointer and then using the3 magnitude function on this
const float CVector3::distance(const CVector3 &a_other) const{
	return (*this - a_other).magnitude();
}
//Function to returning the calculated distance squared, this is done by subtracting a_other from this pointer and then using the square magnitude function on this
const float CVector3::distanceSq(const CVector3 &a_other) const{
	return (*this - a_other).magnitudeSq();
}
//Function to get the dot product by returning the answer of m_fCoordinated array element 0 squared plus m_fCoordinated array element 1 squared plus m_fCoordinated array element 2 squared
const float CVector3::dotProduct(const CVector3 &a_other) const{
	return (m_fCoordinates[0] * a_other[0]) + (m_fCoordinates[1] * a_other[1]) + (m_fCoordinates[2] * a_other[2]);
}
//Cross product function returns x,y, and z coordinates as a vector 3, for each of these coordinates a m_fCoordinates array element is multiplied by another array element then added to the same thing 
const CVector3 CVector3::crossProduct(const CVector3 &a_other) const{
	float x = (m_fCoordinates[1] * m_fCoordinates[2]) - (m_fCoordinates[2] * m_fCoordinates[1]);
	float y = (m_fCoordinates[2] * m_fCoordinates[0]) - (m_fCoordinates[0] * m_fCoordinates[2]);
	float z = (m_fCoordinates[0] * m_fCoordinates[1]) - (m_fCoordinates[1] * m_fCoordinates[0]);
	return CVector3(x, y, z);
}
//Function to normalise in place the elements in the m_fCoordinates, this is done by dividing each of their array elements by the magnitude function
void CVector3::normaliseInPlace(){
	m_fCoordinates[0] = m_fCoordinates[0] / magnitude();
	m_fCoordinates[1] = m_fCoordinates[1] / magnitude();
	m_fCoordinates[2] = m_fCoordinates[2] / magnitude();
}
//Function to return the coordinates after being normalised as seen below
const CVector3 CVector3::normalised() const{
	CVector3 returnthis(m_fCoordinates[0], m_fCoordinates[1], m_fCoordinates[2]);
	returnthis.normaliseInPlace();
	return returnthis;
}
//Overload unction to set each element in the m_fCoordinates array to a variables for their relevant axis (m_fCoordinates[1] = a_y)
CVector3::CVector3(float a_x, float a_y, float a_z){
	m_fCoordinates[0] = a_x;
	m_fCoordinates[1] = a_y;
	m_fCoordinates[2] = a_z;
}
//Overload function set each element im the array except the last to one element from other array
CVector3::CVector3(CVector2 other){
	m_fCoordinates[0] = other[0];
	m_fCoordinates[1] = other[1];
	m_fCoordinates[2] = 0;
}
//Function to return the coordinated/pointer
const float* CVector3::GetPointer() const{
	return m_fCoordinates;
}
//Constructor function
CVector3::CVector3(){
	m_fCoordinates[0] = 0.0f;
	m_fCoordinates[1] = 0.0f;
	m_fCoordinates[2] = 0.0f;
}
//Destructor function
CVector3::~CVector3(){
}
