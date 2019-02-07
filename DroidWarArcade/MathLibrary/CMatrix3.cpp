#include <math.h>
#include "CMatrix3.h"
#include "CVector3.h"
//Identity matrix function returning an identity matrix
const CMatrix3 CMatrix3::Identity() {
	return CMatrix3(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	);
}
//Function to return the requested for, for example a_irowNumber being 1 will return a vector 3 containing  matrix values of 3,4, and 5
const CVector3 CMatrix3::GetRow(const int a_irowNumber) const {
	if (a_irowNumber == 0) {
		return CVector3(m_fMatrixValues[0], m_fMatrixValues[1], m_fMatrixValues[2]);
	}
	else if (a_irowNumber == 1) {
		return CVector3(m_fMatrixValues[3], m_fMatrixValues[4], m_fMatrixValues[5]);
	}
	else if (a_irowNumber == 2) {
		return CVector3(m_fMatrixValues[6], m_fMatrixValues[7], m_fMatrixValues[8]);
	}
	return CVector3 (0,0,0);
}
//Function to set the requested matrix row based upon the value of a_irowNumber
void CMatrix3::SetRow(const int a_irowNumber, const CVector3 &a_rowValues){
	if (a_irowNumber == 0) {
		m_fMatrixValues[0] = a_rowValues[0];
		m_fMatrixValues[1] = a_rowValues[1];
		m_fMatrixValues[2] = a_rowValues[2];
	}
	else if (a_irowNumber == 1) {
		m_fMatrixValues[3] = a_rowValues[0];
		m_fMatrixValues[4] = a_rowValues[1];
		m_fMatrixValues[5] = a_rowValues[2];
	}
	else if (a_irowNumber == 2) {
		m_fMatrixValues[6] = a_rowValues[0];
		m_fMatrixValues[7] = a_rowValues[1];
		m_fMatrixValues[8] = a_rowValues[2];
	}
	return;
}
//Function to rotate the X axis within 3 dimensions
const CMatrix3 CMatrix3::RotateX(const float a_ftheta) const{
	const float co = cosf(a_ftheta);
	const float si = sinf(a_ftheta);
	return *this * CMatrix3(
		1.0f, 0.0f, 0.0f,
		0.0f, co, -si,
		0.0f, si, co
	);
}
//Function to rotate the Y axis within 3 dimensions
const CMatrix3 CMatrix3::RotateY(const float a_ftheta) const{
	const float co = cosf(a_ftheta);
	const float si = sinf(a_ftheta);
	return *this * CMatrix3(
		co, 0.0f, -si,
		0.0f, 1.0f, 0.0f,
		si, 0.0f, co
	);
}
//Function to rotate the Z axis within 3 dimensions
const CMatrix3 CMatrix3::RotateZ(const float a_ftheta) const{
	const float co = cosf(a_ftheta);
	const float si = sinf(a_ftheta);
	return *this * CMatrix3(
		co, -si, 0.0f,
		si, co, 0.0f,
		0.0f, 0.0f, 1.0f
	);
}
//Function to do and return a matrix with addition done to it on it's relevant rows
const CMatrix3 CMatrix3::operator+(const CMatrix3 & a_other) const{
	CMatrix3 matrix = CMatrix3(
	(m_fMatrixValues[0] + a_other.m_fMatrixValues[0]) + (m_fMatrixValues[1] + a_other.m_fMatrixValues[3]) + (m_fMatrixValues[2] + a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[0] + a_other.m_fMatrixValues[1]) + (m_fMatrixValues[1] + a_other.m_fMatrixValues[4]) + (m_fMatrixValues[2] + a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[0] + a_other.m_fMatrixValues[2]) + (m_fMatrixValues[1] + a_other.m_fMatrixValues[5]) + (m_fMatrixValues[2] + a_other.m_fMatrixValues[8]),

	(m_fMatrixValues[3] + a_other.m_fMatrixValues[0]) + (m_fMatrixValues[4] + a_other.m_fMatrixValues[3]) + (m_fMatrixValues[5] + a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[3] + a_other.m_fMatrixValues[1]) + (m_fMatrixValues[4] + a_other.m_fMatrixValues[4]) + (m_fMatrixValues[5] + a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[3] + a_other.m_fMatrixValues[2]) + (m_fMatrixValues[4] + a_other.m_fMatrixValues[5]) + (m_fMatrixValues[5] + a_other.m_fMatrixValues[8]),

	(m_fMatrixValues[6] + a_other.m_fMatrixValues[0]) + (m_fMatrixValues[7] + a_other.m_fMatrixValues[3]) + (m_fMatrixValues[8] + a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[6] + a_other.m_fMatrixValues[1]) + (m_fMatrixValues[7] + a_other.m_fMatrixValues[4]) + (m_fMatrixValues[8] + a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[6] + a_other.m_fMatrixValues[2]) + (m_fMatrixValues[7] + a_other.m_fMatrixValues[5]) + (m_fMatrixValues[8] + a_other.m_fMatrixValues[8])
	);
	return matrix;
}
//Function to add another value to the relevant value inside the matrix
void CMatrix3::operator+=(const CMatrix3 & a_other){
	m_fMatrixValues[0] += a_other[0];
	m_fMatrixValues[1] += a_other[1];
	m_fMatrixValues[2] += a_other[2];
	m_fMatrixValues[3] += a_other[3];
	m_fMatrixValues[4] += a_other[4];
	m_fMatrixValues[5] += a_other[5];
	m_fMatrixValues[6] += a_other[6];
	m_fMatrixValues[7] += a_other[7];
	m_fMatrixValues[8] += a_other[8];
}
//Function to do and return a matrix with subtraction done to it on it's relevant rows
const CMatrix3 CMatrix3::operator-(const CMatrix3 & a_other) const{
	CMatrix3 matrix = CMatrix3(
	(m_fMatrixValues[0] - a_other.m_fMatrixValues[0]) + (m_fMatrixValues[1] - a_other.m_fMatrixValues[3]) + (m_fMatrixValues[2] - a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[0] - a_other.m_fMatrixValues[1]) + (m_fMatrixValues[1] - a_other.m_fMatrixValues[4]) + (m_fMatrixValues[2] - a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[0] - a_other.m_fMatrixValues[2]) + (m_fMatrixValues[1] - a_other.m_fMatrixValues[5]) + (m_fMatrixValues[2] - a_other.m_fMatrixValues[8]),

	(m_fMatrixValues[3] - a_other.m_fMatrixValues[0]) + (m_fMatrixValues[4] - a_other.m_fMatrixValues[3]) + (m_fMatrixValues[5] - a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[3] - a_other.m_fMatrixValues[1]) + (m_fMatrixValues[4] - a_other.m_fMatrixValues[4]) + (m_fMatrixValues[5] - a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[3] - a_other.m_fMatrixValues[2]) + (m_fMatrixValues[4] - a_other.m_fMatrixValues[5]) + (m_fMatrixValues[5] - a_other.m_fMatrixValues[8]),

	(m_fMatrixValues[6] - a_other.m_fMatrixValues[0]) + (m_fMatrixValues[7] - a_other.m_fMatrixValues[3]) + (m_fMatrixValues[8] - a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[6] - a_other.m_fMatrixValues[1]) + (m_fMatrixValues[7] - a_other.m_fMatrixValues[4]) + (m_fMatrixValues[8] - a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[6] - a_other.m_fMatrixValues[2]) + (m_fMatrixValues[7] - a_other.m_fMatrixValues[5]) + (m_fMatrixValues[8] - a_other.m_fMatrixValues[8])
	);
	return matrix;
}
//Function to subtract another value to the relevant value inside the matrix
void CMatrix3::operator-=(const CMatrix3 & a_other){
	m_fMatrixValues[0] -= a_other[0];
	m_fMatrixValues[1] -= a_other[1];
	m_fMatrixValues[2] -= a_other[2];
	m_fMatrixValues[3] -= a_other[3];
	m_fMatrixValues[4] -= a_other[4];
	m_fMatrixValues[5] -= a_other[5];
	m_fMatrixValues[6] -= a_other[6];
	m_fMatrixValues[7] -= a_other[7];
	m_fMatrixValues[8] -= a_other[8];
}
//Function to do and return a matrix with multiplication done to it
const CMatrix3 CMatrix3::operator*(const CMatrix3 &a_other) const{
	CMatrix3 matrix = CMatrix3(
	(m_fMatrixValues[0] * a_other.m_fMatrixValues[0]) + (m_fMatrixValues[1] * a_other.m_fMatrixValues[3]) + (m_fMatrixValues[2] * a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[0] * a_other.m_fMatrixValues[1]) + (m_fMatrixValues[1] * a_other.m_fMatrixValues[4]) + (m_fMatrixValues[2] * a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[0] * a_other.m_fMatrixValues[2]) + (m_fMatrixValues[1] * a_other.m_fMatrixValues[5]) + (m_fMatrixValues[2] * a_other.m_fMatrixValues[8]),

	(m_fMatrixValues[3] * a_other.m_fMatrixValues[0]) + (m_fMatrixValues[4] * a_other.m_fMatrixValues[3]) + (m_fMatrixValues[5] * a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[3] * a_other.m_fMatrixValues[1]) + (m_fMatrixValues[4] * a_other.m_fMatrixValues[4]) + (m_fMatrixValues[5] * a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[3] * a_other.m_fMatrixValues[2]) + (m_fMatrixValues[4] * a_other.m_fMatrixValues[5]) + (m_fMatrixValues[5] * a_other.m_fMatrixValues[8]),

	(m_fMatrixValues[6] * a_other.m_fMatrixValues[0]) + (m_fMatrixValues[7] * a_other.m_fMatrixValues[3]) + (m_fMatrixValues[8] * a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[6] * a_other.m_fMatrixValues[1]) + (m_fMatrixValues[7] * a_other.m_fMatrixValues[4]) + (m_fMatrixValues[8] * a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[6] * a_other.m_fMatrixValues[2]) + (m_fMatrixValues[7] * a_other.m_fMatrixValues[5]) + (m_fMatrixValues[8] * a_other.m_fMatrixValues[8])
	);
	return matrix;
}
//Function to do a matrix with multiplication done to it on it's relevant values
void CMatrix3::operator*=(const CMatrix3 &a_other){
	CMatrix3 matrix = CMatrix3(
	(m_fMatrixValues[0] *= a_other.m_fMatrixValues[0]) + (m_fMatrixValues[1] *= a_other.m_fMatrixValues[3]) + (m_fMatrixValues[2] *= a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[0] *= a_other.m_fMatrixValues[1]) + (m_fMatrixValues[1] *= a_other.m_fMatrixValues[4]) + (m_fMatrixValues[2] *= a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[0] *= a_other.m_fMatrixValues[2]) + (m_fMatrixValues[1] *= a_other.m_fMatrixValues[5]) + (m_fMatrixValues[2] *= a_other.m_fMatrixValues[8]),

	(m_fMatrixValues[3] *= a_other.m_fMatrixValues[0]) + (m_fMatrixValues[4] *= a_other.m_fMatrixValues[3]) + (m_fMatrixValues[5] *= a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[3] *= a_other.m_fMatrixValues[1]) + (m_fMatrixValues[4] *= a_other.m_fMatrixValues[4]) + (m_fMatrixValues[5] *= a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[3] *= a_other.m_fMatrixValues[2]) + (m_fMatrixValues[4] *= a_other.m_fMatrixValues[5]) + (m_fMatrixValues[5] *= a_other.m_fMatrixValues[8]),

	(m_fMatrixValues[6] *= a_other.m_fMatrixValues[0]) + (m_fMatrixValues[7] *= a_other.m_fMatrixValues[3]) + (m_fMatrixValues[8] *= a_other.m_fMatrixValues[6]),
	(m_fMatrixValues[6] *= a_other.m_fMatrixValues[1]) + (m_fMatrixValues[7] *= a_other.m_fMatrixValues[4]) + (m_fMatrixValues[8] *= a_other.m_fMatrixValues[7]),
	(m_fMatrixValues[6] *= a_other.m_fMatrixValues[2]) + (m_fMatrixValues[7] *= a_other.m_fMatrixValues[5]) + (m_fMatrixValues[8] *= a_other.m_fMatrixValues[8])
	);
}
//Function to do a matrix with multiplication done to it
const CMatrix3 CMatrix3::operator*(const float & a_other) const{
	CMatrix3 matrix = CMatrix3(
	(m_fMatrixValues[0] * a_other) + (m_fMatrixValues[1] * a_other) + (m_fMatrixValues[2] * a_other),
	(m_fMatrixValues[0] * a_other) + (m_fMatrixValues[1] * a_other) + (m_fMatrixValues[2] * a_other),
	(m_fMatrixValues[0] * a_other) + (m_fMatrixValues[1] * a_other) + (m_fMatrixValues[2] * a_other),

	(m_fMatrixValues[3] * a_other) + (m_fMatrixValues[4] * a_other) + (m_fMatrixValues[5] * a_other),
	(m_fMatrixValues[3] * a_other) + (m_fMatrixValues[4] * a_other) + (m_fMatrixValues[5] * a_other),
	(m_fMatrixValues[3] * a_other) + (m_fMatrixValues[4] * a_other) + (m_fMatrixValues[5] * a_other),

	(m_fMatrixValues[6] * a_other) + (m_fMatrixValues[7] * a_other) + (m_fMatrixValues[8] * a_other),
	(m_fMatrixValues[6] * a_other) + (m_fMatrixValues[7] * a_other) + (m_fMatrixValues[8] * a_other),
	(m_fMatrixValues[6] * a_other) + (m_fMatrixValues[7] * a_other) + (m_fMatrixValues[8] * a_other)
	);
	return matrix;

}
//Function to do a matrix with multiplication done to it
void CMatrix3::operator*=(const float & a_other){
	CMatrix3 matrix = CMatrix3(
	(m_fMatrixValues[0] *= a_other) + (m_fMatrixValues[1] *= a_other) + (m_fMatrixValues[2] *= a_other),
	(m_fMatrixValues[0] *= a_other) + (m_fMatrixValues[1] *= a_other) + (m_fMatrixValues[2] *= a_other),
	(m_fMatrixValues[0] *= a_other) + (m_fMatrixValues[1] *= a_other) + (m_fMatrixValues[2] *= a_other),

	(m_fMatrixValues[3] *= a_other) + (m_fMatrixValues[4] *= a_other) + (m_fMatrixValues[5] *= a_other),
	(m_fMatrixValues[3] *= a_other) + (m_fMatrixValues[4] *= a_other) + (m_fMatrixValues[5] *= a_other),
	(m_fMatrixValues[3] *= a_other) + (m_fMatrixValues[4] *= a_other) + (m_fMatrixValues[5] *= a_other),

	(m_fMatrixValues[6] *= a_other) + (m_fMatrixValues[7] *= a_other) + (m_fMatrixValues[8] *= a_other),
	(m_fMatrixValues[6] *= a_other) + (m_fMatrixValues[7] *= a_other) + (m_fMatrixValues[8] *= a_other),
	(m_fMatrixValues[6] *= a_other) + (m_fMatrixValues[7] *= a_other) + (m_fMatrixValues[8] *= a_other)
	);
}
//Function to return the value if all the other matrix values are equal to this matrix value relevant to them respectively
const bool CMatrix3::operator==(const CMatrix3& a_other) const{
	bool bEquals = 
		a_other.m_fMatrixValues[0] == this->m_fMatrixValues[0] && 
		a_other.m_fMatrixValues[1] == this->m_fMatrixValues[1] &&
		a_other.m_fMatrixValues[2] == this->m_fMatrixValues[2] &&
		a_other.m_fMatrixValues[3] == this->m_fMatrixValues[3] &&
		a_other.m_fMatrixValues[4] == this->m_fMatrixValues[4] &&
		a_other.m_fMatrixValues[5] == this->m_fMatrixValues[5] &&
		a_other.m_fMatrixValues[6] == this->m_fMatrixValues[6] &&
		a_other.m_fMatrixValues[7] == this->m_fMatrixValues[7] &&
		a_other.m_fMatrixValues[8] == this->m_fMatrixValues[8] ;
		return bEquals;
}
//Function to return the value if all the other matrix values are not equal to this matrix value relevant to them respectively
const bool CMatrix3::operator!=(const CMatrix3& a_other) const {
	bool bEquals =
		a_other.m_fMatrixValues[0] != this->m_fMatrixValues[0] &&
		a_other.m_fMatrixValues[1] != this->m_fMatrixValues[1] &&
		a_other.m_fMatrixValues[2] != this->m_fMatrixValues[2] &&
		a_other.m_fMatrixValues[3] != this->m_fMatrixValues[3] &&
		a_other.m_fMatrixValues[4] != this->m_fMatrixValues[4] &&
		a_other.m_fMatrixValues[5] != this->m_fMatrixValues[5] &&
		a_other.m_fMatrixValues[6] != this->m_fMatrixValues[6] &&
		a_other.m_fMatrixValues[7] != this->m_fMatrixValues[7] &&
		a_other.m_fMatrixValues[8] != this->m_fMatrixValues[8];
	return bEquals;
}
//Function to return the requested matrix value based upon value of i
const float CMatrix3::operator[](const int i) const{
	return m_fMatrixValues[i];
}
//Constructor function to set all the values in the m_fMatrixValues array to 0
CMatrix3::CMatrix3(){
	m_fMatrixValues[0] = 0;
	m_fMatrixValues[1] = 0;
	m_fMatrixValues[2] = 0;
	m_fMatrixValues[3] = 0;
	m_fMatrixValues[4] = 0;
	m_fMatrixValues[5] = 0;
	m_fMatrixValues[6] = 0;
	m_fMatrixValues[7] = 0;
	m_fMatrixValues[8] = 0;
}
//Constructor overload function to set the matrix values to relevant float variables
CMatrix3::CMatrix3(
	const float a_fm11, const float a_fm12, const float a_fm13,
	const float a_fm21, const float a_fm22, const float a_fm23,
	const float a_fm31, const float a_fm32, const float a_fm33){
	m_fMatrixValues[0] = a_fm11;
	m_fMatrixValues[1] = a_fm12;
	m_fMatrixValues[2] = a_fm13;
	m_fMatrixValues[3] = a_fm21;
	m_fMatrixValues[4] = a_fm22;
	m_fMatrixValues[5] = a_fm23;
	m_fMatrixValues[6] = a_fm31;
	m_fMatrixValues[7] = a_fm32;
	m_fMatrixValues[8] = a_fm33;
}
//Constructor overload function to set the matrix values to relevant float variables array 
CMatrix3::CMatrix3(const float *a_fpm33Values){
	m_fMatrixValues[0] = a_fpm33Values[0];
	m_fMatrixValues[1] = a_fpm33Values[1];
	m_fMatrixValues[2] = a_fpm33Values[2];
	m_fMatrixValues[3] = a_fpm33Values[3];
	m_fMatrixValues[4] = a_fpm33Values[4];
	m_fMatrixValues[5] = a_fpm33Values[5];
	m_fMatrixValues[6] = a_fpm33Values[6];
	m_fMatrixValues[7] = a_fpm33Values[7];
	m_fMatrixValues[8] = a_fpm33Values[8];
}
//Destructor function
CMatrix3::~CMatrix3(){
}
