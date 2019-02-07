//\========================================================================================================================================== =
//\ Filename: OBBcollision.h
//\ Author : C.A.Bullock
//\ Date : 09 / 05 / 2018
//\ Brief   : Calculates the collision for relevant objects to use
//\========================================================================================================================================== =

#ifndef __OBBCOLLISION_H__
#define __OBBCOLLISION_H__

#include "Mathlibrary.h"
#include "GameManager.h"
#include "VisualsManager.h"
#include "UGFW.h"
#include <vector>
class CMatrix3;
class OBBcollision
{
public:
	//Constructor
	OBBcollision();
	//Destructor
	~OBBcollision();
	//Pass the global position so can be used locally
	void CollisionUpdate(CMatrix3 a_matrix3);
	//Function for checking for an OBB collision
	bool CheckOBBCollision(OBBcollision* a_comparingCollision);
	//Function for checking for an oberlap OBB objects
	bool CheckOBBOverlap(float a_fboxMinimum1, float a_fboxMaximum1, float a_fboxMinimum2, float a_fboxMaximum2);
	//This seperate axis theorem function checks the OBB shapes by flattening them and comparing
	void SAT(CVector3 a_vectorNormals, const CVector3 a_vector[], float &a_fMinimumLength, float &a_fMaximumLength);
	//Corners and normals for the object which is being checked
	CVector3 a_vector3Corners[4];
	CVector3 a_vector3Normals[4];
	//Size of the object which is being checked
	int iObbObjectWidth;
	int iObbObjectHeight;
private:
	//Current vector 3 position
	CVector3 a_currentVector3Position;	
};
#endif __OBBCOLLISION_H__