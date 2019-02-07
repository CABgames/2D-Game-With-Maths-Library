//\===========================================================================================================================================
//\ Filename: Vehicle.h
//\ Author  : C.A.Bullock
//\ Date    : 30/04/2018
//\ Brief   : Used to rotate, get movement, scale, parent, add and remove child of vehicles for this it uses the MathLibrary
//\===========================================================================================================================================

#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "MathLibrary.h"
#include <set>

class Vehicle {
public:
	//Constructor
	Vehicle();
	//Destructor
	virtual ~Vehicle();
	//Function to set the parent
	void SettingVehicleParent(Vehicle* a_parent);
	//Function to add the child
	void AddingVehicleChild(Vehicle* a_child);
	//Function to remove the child from structure
	void RemovingVehicleChild(Vehicle* a_child);
	//Function to find where is this located in the world
	void GettingGlobalTransformation(CMatrix3& transformation);
	//Function to get the local transform for the point
	void GettingLocalTransformation(CMatrix3 a_3MatrixTransformation);
	//Function to set the translation
	void SettingTranslation(CVector2 a_v2Translation);
	//Function to rotate this around the Z axis
	//If this was a 3D object then Y and X rotational functions would additionally be needed
	void RotationZAxis(float a_fRotation);
	//Scale this
	void ScaleVehicle(float a_fVehicleScale);

protected:
	//This is the three dimensional matrix class known as CMatrix3
	CMatrix3 matrix3PositionRotation;

private:
	Vehicle * matrix_pParent;
	std::set<Vehicle*>matrix_pChild;

	/* virtual void Update() override;
	virtual void Draw() override; */

};

#endif __VEHICLE_H__