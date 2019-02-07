//\===========================================================================================================================================
//\ Filename: GameSprite.cpp
//\ Author  : C.A.Bullock
//\ Date    : 30/04/2018
//\ Brief   : Sets up, moves and draws the position for relevant game sprites
//\===========================================================================================================================================

#ifndef __GAMESPRITE_H__
#define __GAMESPRITE_H__

#include <set>
#include "Mathlibrary.h"
#include "UGFW.h"
#include "Vehicle.h"
#include "OBBcollision.h"
//A structure sprite class which extends from the Tank class in order for us to have a sprite hierarchy tree
class OBBcollision;
class GameSprite: public Vehicle{
public:
	//Constructor creates a UG sprite object
	GameSprite(const char* a_fileName, const float *a_size, const float *a_origin, const float *a_UVCoords);
	//heirarchies the destructors will be called in the right order.
	virtual ~GameSprite();
	//Function which sets the sprites layer
	void SetLayer(unsigned int a_uiLayer);
	//Function that to call that updates each frame to update our sprites data
	void Update(float a_fdt);
	//Function to move sprite
	void MoveSprite(CVector3 a_movementVector);
	//Function to draw sprite
	void Draw();
	//Function for setting the position using vector 2
	void SetPosition(CVector2 a_pos);

	CVector3 GetPosition(int iRow);
	OBBcollision* obbBox;
private:
	int m_iSpriteID;
};

#endif __GAMESPRITE_H__