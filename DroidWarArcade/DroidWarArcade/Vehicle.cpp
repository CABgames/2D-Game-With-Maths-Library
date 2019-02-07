#include "Vehicle.h"

// typedefs
//typedef GameObject PARENT;

//Constructor
Vehicle::Vehicle() {
	matrix_pParent = nullptr;
	matrix3PositionRotation = CMatrix3::Identity();
}

//Destructor
Vehicle::~Vehicle() {
	//Replaced by this range based for loop
	for (auto &iterate : matrix_pChild) {	
		RemovingVehicleChild(iterate);
	}
	//The parent is set to nullptr value (null)
	matrix_pParent = nullptr;
}

//Function to set the parent
void Vehicle::SettingVehicleParent(Vehicle* a_parent) { 
	//If this has tried to be set to a parent of itself the don't do anything and return
	if (a_parent == this) {
		return;
	}
	//If there's already a parent then prior to execution remove this as a child from the parent
	if (matrix_pParent != nullptr) {
		matrix_pParent->RemovingVehicleChild(this);
	}
	//Set this objects parent variable, then add this to the parent object as a child
	matrix_pParent = a_parent;
	matrix_pParent->AddingVehicleChild(this);
}

//Function to add the child
void Vehicle::AddingVehicleChild(Vehicle* a_child) {
	auto iterator = matrix_pChild.find(a_child);
	//Children are stored in a set which enabled for easy searching of the child item
	//this enables checking if the child already exists within the set of children
	//if the child already exists then it will not be added to the set multiple times
	if (iterator != matrix_pChild.end()) {
		matrix_pChild.emplace(a_child);
	}
}

//Function to remove the child from structure
void Vehicle::RemovingVehicleChild(Vehicle* a_child) {
	//If we are able to find the child then remove it, a successful find will return an
	//iterator to the object being search. But an unsuccessful find returns an iterator
	//that is one item past the end of the set
	auto iterator = matrix_pChild.find(a_child);
	if(iterator != matrix_pChild.end()) {
		matrix_pChild.erase(iterator);
	}
}

//Function to find where is this located in the world
void Vehicle::GettingGlobalTransformation(CMatrix3& transformation) {
	if (matrix_pParent)
	{
		matrix_pParent->GettingGlobalTransformation(transformation);
		transformation = matrix3PositionRotation * transformation;
	}
	else
	{
		transformation = matrix3PositionRotation;
	}
}

//Function to get the local transform for the point
void Vehicle::GettingLocalTransformation(CMatrix3 a_3MatrixTransformation) {
	a_3MatrixTransformation = matrix3PositionRotation;
}

//Function to set the translation
void Vehicle::SettingTranslation(CVector2 a_v2Translation) {
	matrix3PositionRotation.SetRow(2, CVector3(a_v2Translation));
}

//Function to rotate this around the Z axis
//If this was a 3D object then Y and X rotational functions would additionally be needed
void Vehicle::RotationZAxis(float a_fRotation) {
	CMatrix3 matrix3Rotation = CMatrix3::Identity();
	matrix3Rotation = matrix3Rotation.RotateZ(a_fRotation);
	matrix3PositionRotation = matrix3Rotation * matrix3PositionRotation;
}

//Scale this
void Vehicle::ScaleVehicle(float a_fVehicleScale) {	
	CVector3 translation = matrix3PositionRotation.GetRow(2);
	
	CMatrix3 identity = CMatrix3::Identity();
	matrix3PositionRotation = (identity * a_fVehicleScale) * matrix3PositionRotation;
	matrix3PositionRotation.SetRow(2, translation);
}
