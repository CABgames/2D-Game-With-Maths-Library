//\===========================================================================================================================================
//\ Filename: GameManager.h
//\ Author  : C.A.Bullock
//\ Date    : 05/02/2018
//\ Brief   : GameManager is responsible for managing and controlling all the various aspects of the game/program such as movement and bringing it together
//\===========================================================================================================================================

#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "UGFW.h"
#include "UG_Defines.h"
#include "VisualsManager.h"
#include "MathLibrary.h"
#include "GameSprite.h"
#include <math.h>
#include <iostream>
#include <vector>
class GameSprite;
class GameManager
{
public:
	//Constructor function
	GameManager();
	//Destructor function
	~GameManager();
	//Function to set up initial positioning and other minor things
	void Positioning();
	//Update function is called constantly no matter which game state the player is in
	void Update();
	//Check input function checks the players vehicle input when on a level
	void CheckInput();
	//Check scores function checks the players score input when on a level
	void CheckScores();
	//Called when initialises essential things such as the player vehicle
	void Initialise();
	//Called in when box collision function has detected a colision betrween players and can give far  more accurate testing
	void OBBCollisionCheck();
	//Checks the different box collisions needed
	void BoxCollisionCheck();	
	//Generates random value and ability
	void RandomGeneration();
	//Which powerups have already been taken
	void Powerups();
	//Public variables
	int iLevelStateValue;
	float fPlayer1Accelleration;
	float fPlayer2Accelleration;
private:
	//Variables
	GameSprite* pTank1;
	GameSprite* pTank2;
	GameSprite* pTurret1;
	GameSprite* pTurret2;
	GameSprite* pBullet1;
	GameSprite* pBullet2;
	bool bGameNotQuit;
	//Enum
	enum currentLevel
	{
		MENU,
		HELP,
		P1WIN,
		P2WIN,
		FIRST_LEVEL,
		SECOND_LEVEL,
		THIRD_LEVEL
	};
	//Variables
	currentLevel level;
	VisualsManager vManager;
	int aiScores[2];
	int aiPowerups;
	int count;
	bool bIsPaused;
	bool bPlayer1IsDead;
	bool bPlayer2IsDead;
	bool bPlayer1BulletLaunched;
	bool bPlayer2BulletLaunched;
	bool bStopPlayer1ShootJump;
	bool bStopPlayer2ShootJump;
	bool bHasBeenSeen[9];
	//Powerup related variables
	float fVehicle1Speed;
	float fVehicle2Speed;
	//Movement related variables
	float fCurrentVelocity;
	float fCurrentVelocity2;
	float fCurrentVelocityBullet;
	float fCurrentVelocityBullet2;
	float fPlayer1Drag;
	float fPlayer2Drag;
	float fMaxVelocity;
	float fMaxVelocity2;
	float fMaxVelocityBullet;
	float fMaxVelocityBullet2;
	//Delta time float
	float dt;
	//Vectors
	CVector2 v2Velocity;
	CVector2 v2Position1;
	CVector2 v2Position2;
	CVector3 movementVector;
	CVector3 movementVector2;
	CVector3 movementVectorBullet;
	CVector3 movementVectorBullet2;
	CVector3 temporaryPositionVector;
	CVector3 temporaryPositionVector2;
};

#endif __GAMEMANAGER_H__