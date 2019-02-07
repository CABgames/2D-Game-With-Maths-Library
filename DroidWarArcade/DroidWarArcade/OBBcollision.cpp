#include "OBBcollision.h"
//Constructor
OBBcollision::OBBcollision() {
}
//Destructor
OBBcollision::~OBBcollision() {
}
//Pass the global position so can be used locally
void OBBcollision::CollisionUpdate(CMatrix3 a_matrix3) {
	a_currentVector3Position = a_matrix3.GetRow(2);
	a_vector3Corners[0] = a_matrix3.GetRow(2) - (a_matrix3.GetRow(0) * (float)(iObbObjectWidth / 2) - (a_matrix3.GetRow(1) * (float)(iObbObjectWidth / 2)));
	a_vector3Corners[1] = a_matrix3.GetRow(2) + (a_matrix3.GetRow(0) * (float)(iObbObjectWidth / 2) + (a_matrix3.GetRow(1) * (float)(iObbObjectWidth / 2)));
	a_vector3Corners[2] = a_matrix3.GetRow(2) + (a_matrix3.GetRow(0) * (float)(iObbObjectWidth / 2) - (a_matrix3.GetRow(1) * (float)(iObbObjectWidth / 2)));
	a_vector3Corners[3] = a_matrix3.GetRow(2) - (a_matrix3.GetRow(0) * (float)(iObbObjectWidth / 2) + (a_matrix3.GetRow(1) * (float)(iObbObjectWidth / 2)));
	CVector3 edge1 = a_vector3Corners[1] - a_vector3Corners[0];
	CVector3 edge2 = a_vector3Corners[2] - a_vector3Corners[1];
	a_vector3Normals[0] = a_matrix3.GetRow(0);
	a_vector3Normals[1] = a_matrix3.GetRow(0);
}
//Function for checking for an OBB collision
bool OBBcollision::CheckOBBCollision(OBBcollision* a_comparingCollision)  {	
	bool bDoesOverlap ;

	for (int i=0; i < 2; ++i) {
		float fShape1Minimum = 0, fShape1Maximum = 0, fShape2Minimum = 0, fShape2Maximum = 0;


		SAT(a_vector3Normals[i], a_vector3Corners, fShape1Minimum, fShape1Maximum);

		SAT(a_vector3Normals[i], a_comparingCollision->a_vector3Corners, fShape2Minimum, fShape2Maximum);

		bDoesOverlap = CheckOBBOverlap(fShape1Minimum, fShape1Maximum, fShape2Minimum, fShape2Maximum);

		if (bDoesOverlap == false) return false;
	}	
	return bDoesOverlap;
}
//Function for checking for an oberlap OBB objects
bool OBBcollision::CheckOBBOverlap(float fShape1Minimum, float fShape1Maximum, float fShape2Minimum, float fShape2Maximum)
{
	return (fShape1Minimum < fShape2Maximum && fShape1Maximum > fShape2Minimum);
}
//This seperate axis theorem function checks the OBB shapes by flattening them and comparing
void OBBcollision::SAT(CVector3 a_vectorNormals, const CVector3 a_positionPoint[], float &a_fMinimumLength, float &a_fMaximumLength) {
	
	a_fMinimumLength = a_positionPoint[0].normalised().dotProduct(a_vectorNormals.normalised());
	a_fMaximumLength = a_positionPoint[0].normalised().dotProduct(a_vectorNormals.normalised());

	//Go through the corner points
	for (int i = 0; i < 4;i++) {
		//Use dot product to get the minimum/maximum along this axis
		float fDotValue = a_positionPoint[i].normalised().dotProduct(a_vectorNormals.normalised());
		if (fDotValue < a_fMinimumLength) 
		{
			a_fMinimumLength = fDotValue;
		}
		if (fDotValue > a_fMaximumLength) 
		{
			a_fMaximumLength = fDotValue;
		}
	}
}
