//\===========================================================================================================================================
//\ Filename: VisualsManager.h
//\ Author  : C.A.Bullock
//\ Date    : 11/03/2018
//\ Brief   : Sets up all non gameplay visual components of the game in order for them to be viewed by players
//\===========================================================================================================================================

#ifndef __VISUALSMANAGER_H__
#define __VISUALSMANAGER_H__

#include "UGFW.h"
#include "UG_Defines.h"
#include <random>

class Vector2;

class VisualsManager
{
public:
	//Constructor
	VisualsManager();
	//Destructor
	~VisualsManager();
	//This function is used to initialise the victory screen for when players start the game, win, or return oto menu
	void InitialiseMenu();
	//This function is used to initialise the victory screen for when players neede help/explanaition
	void InitialiseHelp();
	//This function is used to initialise the victory screen for when player 1 wins
	void InitialiseP1VictoryScreen();
	//This function is used to initialise the victory screen for when player 2 wins
	void InitialiseP2VictoryScreen();
	//This function is used to initialise the environment used in the first level such as the ground and blocks
	void InitialiseLevel1();
	//This function is used to initialise the environment used in the second level such as the ground and blocks
	void InitialiseLevel2();
	//This function is used to initialise the environment used in the third level such as the ground and blocks
	void InitialiseLevel3();
	//This function is used to initialise the barbed wire for the environment as it is the same in any of the levels
	void InitialiseCombat();
	//This function is used to initialise the pause screen used in the games levels
	void InitialisePauseScreen();
	//This function is used to render the environments and backgrounds by utilising the UG framework however this does not render the pause background
	void Render();
	//This function is used to draw the pause background and does this with the help of the UG framework
	void RenderPause();
	//Deinitialise function used to destroy many of the sprites when no longer needed
	void Deinitialise();
	//Public variables
	int aiHeartsBlue[18];
	int aiHeartsRed[18];
	int aiLevel1ConcreteBlock[3];
	int aiLevel2ConcreteBlock[3];
	int aiLevel3ConcreteBlock[3];
	//Float arrats for storing the positions which are used to place and move many of the tiles in the games environment
	float a_fSpritePositionsX[26]{ 15,45,75,105,135,165,195,225,255,285,315,345,375,405,435,465,495,525,555,585,615,645,675,705,735,765};
	float a_fSpritePositionsY[26]{ 15,45,75,105,135,165,195,225,255,285,315,345,375,405,435,465,495,525,555,585,615,645,675,705,735,765 };
private:
	//Character arrays for the image file directories which are utilised within this game
	char* apcMenus[4]{ "./images/HelpImage.png", "./images/MenuImage.png", "./images/P1Victory.png", "./images/P2Victory.png" };
	char* apcSpriteDirectories[28]{ "./images/BarbWireSide.png" ,
		"./images/BarbWireVertical.png" ,
		"./images/BlueTankHeart.png" ,
		"./images/BulletBlue.png" ,
		"./images/BulletRed.png" ,
		"./images/ConcreteBlock.png" ,
		"./images/ConcreteBlockCracked.png" ,
		"./images/FloorTile.png" ,
		"./images/GrassTile.png" ,
		"./images/GravelTile.png" ,
		"./images/MetalBlock.png" ,
		"./images/MetalBlockCracked1.png" ,
		"./images/MetalBlockCracked2.png" ,
		"./images/MetalBlockCracked3.png" ,
		"./images/Mine.png." ,
		"./images/Spike.png" 
		"/images/PowerUp1.png" ,
		"./images/PowerUp2.png" ,
		"./images/PowerUp3.png" ,
		"./images/PowerUp4.png" ,
		"./images/RedTankHeart.png" ,
		"./images/TankBlue.png" ,
		"./images/TankGunTopBlue.png" ,
		"./images/TankGunTopRed.png" ,
		"./images/TankRed.png" ,
		"./images/WoodBlock.png" ,
		"./images/Blank.png" ,
		"./images/PauseImage.png" ,
	};
	//Private variables
	float afConcreteBlockLocationsX[11];
	float afMetalBlockLocationsX[11];
	float afWoodenBlockLocationsX[11];
	float afConcreteBlockLocationsY[11];
	float afMetalBlockLocationsY[11];
	float afWoodenBlockLocationsY[11];
	//Enum
	enum currentLevel {
		MENU,
		HELP,
		P1VICTORY,
		P2VICTORY,
		FIRST_LEVEL,
		SECOND_LEVEL,
		THIRD_LEVEL
	};
	currentLevel level;	
	//More private variables
	int iPauseSprite;
	int aiFloorSpriteNumber[625];
	int aiMenuSprite[4];
	int aiBarbWireTop[24];
	int aiBarbWireBottom[24];
	int aiBarbWireLeft[23];
	int aiBarbWireRight[23];
	int aiLevel1MetalBlock[3];
	int aiLevel1WoodBlock[7];
	int aiLevel2MetalBlock[5];
	int aiLevel2WoodBlock[9];
	int aiLevel3MetalBlock[7];
	int aiLevel3WoodBlock[11];

};

#endif __VISUALSMANAGER_H__