#include "GameSprite.h"

//Constructor makes a UG sprite object
GameSprite::GameSprite(const char* a_fileName, const float *a_size, const float *a_origin, const float *a_UVCoords) {
	//Getting the sprite ID
	m_iSpriteID = UG::CreateSprite(a_fileName, a_size[0], a_size[1], a_origin, UG::SColour(255, 255, 255, 255));
	obbBox = new OBBcollision();
	obbBox->iObbObjectHeight = 30;
	obbBox->iObbObjectWidth = 30;
}

//Destructor is virtual which makes sure that despite the fact we are using inheritance 
//heirarchies the destructors will be called in the right order.
GameSprite::~GameSprite() {
	//When this object is destroyed free up that memory
	UG::DestroySprite(m_iSpriteID);
}
//Function which sets the sprites layer
void GameSprite::SetLayer(unsigned int a_uiLayer) {
	UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);
}
//Function that is called each frame to update the data of our game sprites
void GameSprite::Update(float a_fdt) {	
	CMatrix3 matrix3PositionRotation = CMatrix3::Identity();
	GettingGlobalTransformation(matrix3PositionRotation);
	//A 4x4 matrix is used for the setting of the sprite matrix which needs an identity matrix
	float matrix4x4[] = {
		matrix3PositionRotation[0], matrix3PositionRotation[1], matrix3PositionRotation[2], 0.0f,
		matrix3PositionRotation[3], matrix3PositionRotation[4], matrix3PositionRotation[5], 0.0f,
		0.0f,		0.0f,		1.0f,		0.0f,
		matrix3PositionRotation[6], matrix3PositionRotation[7], 0.0f,		1.0f,
	};
	UG::SetSpriteMatrix(m_iSpriteID, matrix4x4);
	obbBox->CollisionUpdate(matrix3PositionRotation);
}
//Function to get and return the specified row from the matrix
CVector3 GameSprite::GetPosition(int iRow) {
	return matrix3PositionRotation.GetRow(iRow);
}
//Function to move sprite
void GameSprite::MoveSprite(CVector3 a_movementVector) {
	CVector3 position = matrix3PositionRotation.GetRow(2);
	//By multiplying our movement vector by the local transform will put the vector into local space of this object
	//float x = a_movementVector.GetPointer()[0];
	//float y = a_movementVector.GetPointer()[1];
	position += a_movementVector;
	matrix3PositionRotation.SetRow(2, position);
}
//Function to draw sprite
void GameSprite::Draw() {
	UG::DrawSprite(m_iSpriteID);
}
//Function for setting the position using vector 2
void GameSprite::SetPosition(CVector2 a_pos) {
	CVector3 np = CVector3(a_pos[0], a_pos[1], 1.f);
	matrix3PositionRotation.SetRow(2, np);
}