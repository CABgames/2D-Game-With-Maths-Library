#include "VisualsManager.h"
#include "UG_Defines.h"
#include "UGFW.h"
#include <iostream>
#include <set>
#include <array>
//Constructor
VisualsManager::VisualsManager()
{
}
//Destructor
VisualsManager::~VisualsManager()
{
}
//This function is used to initialise the victory screen for when players start the game, win, or return oto menu
void VisualsManager::InitialiseMenu(){
	level = MENU;
	int iCurrentBackgroundSprite = 0;
	aiMenuSprite[0] = UG::CreateSprite(apcMenus[1], 720, 750, true);
	UG::SetSpriteLayer(aiMenuSprite[0], 0);
	UG::SetSpritePosition(aiMenuSprite[iCurrentBackgroundSprite], 360, 375);
	iCurrentBackgroundSprite++;	
}
//This function is used to initialise the victory screen for when players neede help/explanaition
void VisualsManager::InitialiseHelp(){
	level = HELP;
	int iCurrentBackgroundSprite = 1;

	aiMenuSprite[1] = UG::CreateSprite(apcMenus[0], 720, 750, true);
	UG::SetSpriteLayer(aiMenuSprite[1], 0);
	UG::SetSpritePosition(aiMenuSprite[iCurrentBackgroundSprite], 360, 375);
	iCurrentBackgroundSprite++;
}
//This function is used to initialise the victory screen for when player 1 wins
void VisualsManager::InitialiseP1VictoryScreen(){
	level = P1VICTORY;
	int iCurrentBackgroundSprite = 2;
	aiMenuSprite[2] = UG::CreateSprite(apcMenus[2], 720, 750, true);
	UG::SetSpriteLayer(aiMenuSprite[2], 0);
	UG::SetSpritePosition(aiMenuSprite[iCurrentBackgroundSprite], 360, 375);
}
//This function is used to initialise the victory screen for when player 2 wins
void VisualsManager::InitialiseP2VictoryScreen(){
	level = P2VICTORY;
	int iCurrentBackgroundSprite = 3;
	aiMenuSprite[3] = UG::CreateSprite(apcMenus[3], 720, 750, true);
	UG::SetSpriteLayer(aiMenuSprite[3], 0);
	UG::SetSpritePosition(aiMenuSprite[iCurrentBackgroundSprite], 360, 375);
}
//This function is used to initialise the pause screen used in the games levels
void VisualsManager::InitialisePauseScreen(){
	iPauseSprite = UG::CreateSprite(apcSpriteDirectories[26], 720, 750, true);
	UG::SetSpriteLayer(iPauseSprite, -1);
	UG::SetSpritePosition(iPauseSprite, 360, 375);
}
//This function is used to initialise the environment used in the first level such as the ground and blocks
void VisualsManager::InitialiseLevel1(){
	level = FIRST_LEVEL;

	int iCurrentBackgroundSprite = 0;
	for (int i = 0; i < 625; i++) {
		aiFloorSpriteNumber[i] = UG::CreateSprite(apcSpriteDirectories[7], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 0);
	}
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 25; y++) {
			UG::SetSpritePosition(aiFloorSpriteNumber[iCurrentBackgroundSprite], a_fSpritePositionsX[x] - 30, a_fSpritePositionsY[y]);
			iCurrentBackgroundSprite++;
		}
	}
	//Initialisation of concrete blocks for this level.
	for (int i = 0; i < 3; i++) {
		aiLevel1ConcreteBlock[i] = UG::CreateSprite(apcSpriteDirectories[17], 30, 30, true);
		UG::SetSpriteLayer(aiLevel1ConcreteBlock[i], -1);
	}
	//Setting the location for the concrete block for this level.
	for (int i = 0; i < 3; i++) {
		UG::SetSpritePosition(aiLevel1ConcreteBlock[i], a_fSpritePositionsX[15 - i], a_fSpritePositionsY[i + 3]);
	}
	//Initialisation of metal blocks for this level.
	for (int i = 0; i < 3; i++) {
		aiLevel1MetalBlock[i] = UG::CreateSprite(apcSpriteDirectories[10], 30, 30, true);
		UG::SetSpriteLayer(aiLevel1MetalBlock[i], -1);
	}
	//Setting the location for the metal blocks for this level.
	for (int i = 0; i < 3; i++) {
		UG::SetSpritePosition(aiLevel1MetalBlock[i], a_fSpritePositionsX[3], a_fSpritePositionsY[i + 3]);
	}
	//Initialisation of wood blocks for this level.
	for (int i = 0; i < 7; i++) {
		aiLevel1WoodBlock[i] = UG::CreateSprite(apcSpriteDirectories[24], 30, 30, true);
		UG::SetSpriteLayer(aiLevel1WoodBlock[i], -1);
	}
	//Setting the location for the wood blocks for this level.
	for (int i = 0; i < 7; i++) {
		UG::SetSpritePosition(aiLevel1WoodBlock[i], a_fSpritePositionsX[5 + i], a_fSpritePositionsY[20]);
	}
}
//This function is used to initialise the environment used in the second level such as the ground and blocks
void VisualsManager::InitialiseLevel2() {
	level = SECOND_LEVEL;
	int iCurrentBackgroundSprite = 0;
	for (int i = 0; i < 625; i++) {
		aiFloorSpriteNumber[i] = UG::CreateSprite(apcSpriteDirectories[8], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 0);
	}
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 25; y++) {
			UG::SetSpritePosition(aiFloorSpriteNumber[iCurrentBackgroundSprite], a_fSpritePositionsX[x] - 30, a_fSpritePositionsY[y]);
			iCurrentBackgroundSprite++;
		}
	}
	//Initialisation of concrete blocks for this level.
	for (int i = 0; i < 3; i++) {
		aiLevel2ConcreteBlock[i] = UG::CreateSprite(apcSpriteDirectories[16], 30, 30, true);
		UG::SetSpriteLayer(aiLevel2ConcreteBlock[i], -1);
	}
	//Setting the location for the concrete block for this level.
	for (int i = 0; i < 3; i++) {
		UG::SetSpritePosition(aiLevel2ConcreteBlock[i], a_fSpritePositionsX[15 - i], a_fSpritePositionsY[i + 3]);
	}
	//Initialisation of metal blocks for this level.
	for (int i = 0; i < 5; i++) {
		aiLevel2MetalBlock[i] = UG::CreateSprite(apcSpriteDirectories[10], 30, 30, true);
		UG::SetSpriteLayer(aiLevel2MetalBlock[i], -1);
	}
	//Setting the location for the metal blocks for this level.
	for (int i = 0; i < 5; i++) {
		UG::SetSpritePosition(aiLevel2MetalBlock[i], a_fSpritePositionsX[4], a_fSpritePositionsY[i + 3]);
	}
	//Initialisation of wood blocks for this level.
	for (int i = 0; i < 9; i++) {
		aiLevel2WoodBlock[i] = UG::CreateSprite(apcSpriteDirectories[24], 30, 30, true);
		UG::SetSpriteLayer(aiLevel2WoodBlock[i], -1);
	}
	//Setting the location for the wood blocks for this level.
	for (int i = 0; i < 9; i++) {
		UG::SetSpritePosition(aiLevel2WoodBlock[i], a_fSpritePositionsX[5 + i], a_fSpritePositionsY[20]);
	}
}
//This function is used to initialise the environment used in the third level such as the ground and blocks
void VisualsManager::InitialiseLevel3() {

	level = THIRD_LEVEL;
	int iCurrentBackgroundSprite = 0;
	for (int i = 0; i < 625; i++) {
		aiFloorSpriteNumber[i] = UG::CreateSprite(apcSpriteDirectories[9], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 0);
	}
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 25; y++) {
			UG::SetSpritePosition(aiFloorSpriteNumber[iCurrentBackgroundSprite], a_fSpritePositionsX[x] - 30, a_fSpritePositionsY[y]);
			iCurrentBackgroundSprite++;
		}
	}
	//Initialisation of concrete blocks for this level.
	for (int i = 0; i < 3; i++) {
		aiLevel3ConcreteBlock[i] = UG::CreateSprite(apcSpriteDirectories[18], 30, 30, true);
		UG::SetSpriteLayer(aiLevel3ConcreteBlock[i], -1);
	}
	//Setting the location for the concrete block for this level.
	for (int i = 0; i < 3; i++) {
		UG::SetSpritePosition(aiLevel3ConcreteBlock[i],a_fSpritePositionsX[15 - i],a_fSpritePositionsY[i+3]);
		//Sets the values for collision constraints to the relevant current blocks.
		afConcreteBlockLocationsX[i] = a_fSpritePositionsX[15 - i];
		afConcreteBlockLocationsY[i] = a_fSpritePositionsY[i + 3];
	}
	//Initialisation of metal blocks for this level.
	for (int i = 0; i < 7; i++) {
		aiLevel3MetalBlock[i] = UG::CreateSprite(apcSpriteDirectories[10], 30, 30, true);
		UG::SetSpriteLayer(aiLevel3MetalBlock[i], -1);
	}
	//Setting the location for the metal blocks for this level.
	for (int i = 0; i < 7; i++) {
		UG::SetSpritePosition(aiLevel3MetalBlock[i], a_fSpritePositionsX[2], a_fSpritePositionsY[i + 3]);
		//Sets the values for collision constraints to the relevant current blocks.
		afMetalBlockLocationsX[i] = a_fSpritePositionsX[2];
		afMetalBlockLocationsY[i] = a_fSpritePositionsY[i + 3];
	}
	//Initialisation of wood blocks for this level.
	for (int i = 0; i < 11; i++) {
		aiLevel3WoodBlock[i] = UG::CreateSprite(apcSpriteDirectories[24], 30, 30, true);
		UG::SetSpriteLayer(aiLevel3WoodBlock[i], -1);
	}
	//Setting the location for the wood blocks for this level.
	for (int i = 0; i < 11; i++) {
		UG::SetSpritePosition(aiLevel3WoodBlock[i], a_fSpritePositionsX[5 + i], a_fSpritePositionsY[20]);
		//Sets the values for collision constraints to the relevant current blocks.
		afMetalBlockLocationsX[i] = a_fSpritePositionsX[5 + i];
		afMetalBlockLocationsY[i] = a_fSpritePositionsY[20];
	}
}
//This function is used to initialise the barbed wire for the environment as it is the same in any of the levels
void VisualsManager::InitialiseCombat()
{
	//Initialising the barbwire perimeter.
	int iCurrentBackgroundSprite = 0;
	//Top
	for (int i = 0; i < 24; i++)
	{
		aiBarbWireTop[i] = UG::CreateSprite(apcSpriteDirectories[1], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 1);
	}
	for (int x = 0; x < 24; x++) {
			UG::SetSpritePosition(aiBarbWireTop[x], a_fSpritePositionsX[x], a_fSpritePositionsY[24]);
	}
	//Bottom
	for (int i = 0; i < 24; i++) {
		aiBarbWireBottom[i] = UG::CreateSprite(apcSpriteDirectories[1], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 1);
	}	
	for (int x = 0; x < 24; x++) {
		UG::SetSpritePosition(aiBarbWireBottom[x], a_fSpritePositionsX[x], a_fSpritePositionsY[0]);
	}
	//Left
	for (int i = 0; i < 23; i++) {
		aiBarbWireLeft[i] = UG::CreateSprite(apcSpriteDirectories[0], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 1);
	}
	for (int y = 0; y < 23; y++) {
		UG::SetSpritePosition(aiBarbWireLeft[y], a_fSpritePositionsX[0], a_fSpritePositionsY[y +1]);
	}
	//Right
	for (int i = 0; i < 23; i++) {
		aiBarbWireRight[i] = UG::CreateSprite(apcSpriteDirectories[0], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 1);
	}
	for (int y = 0; y < 23; y++) {
		UG::SetSpritePosition(aiBarbWireRight[y], a_fSpritePositionsX[24] - 30, a_fSpritePositionsY[y +1]);
	}
	//Initialising Hearts
	for (int i = 0; i < 9; i++) {
		aiHeartsBlue[i] = UG::CreateSprite(apcSpriteDirectories[2], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 2);
	}
	for (int y = 0; y < 9; y++) {
		UG::SetSpritePosition(aiHeartsBlue[y], a_fSpritePositionsX[y + 1] - 30, a_fSpritePositionsY[24]);
	}
	for (int i = 0; i < 9; i++) {
		aiHeartsRed[i] = UG::CreateSprite(apcSpriteDirectories[19], 30, 30, true);
		UG::SetSpriteLayer(aiFloorSpriteNumber[i], 2);
	}
	for (int y = 0; y < 9; y++) {
		UG::SetSpritePosition(aiHeartsRed[y], a_fSpritePositionsX[y + 16] - 30, a_fSpritePositionsY[24]);
	}
}
//This function is used to render the environments and backgrounds by utilising the UG framework however this does not render the pause background
void VisualsManager::Render() {
	if (level == FIRST_LEVEL || level == SECOND_LEVEL || level == THIRD_LEVEL) {
		for (int i = 0; i < 625; i++) {
			UG::DrawSprite(aiFloorSpriteNumber[i]);
		}
		for (int i = 0; i < 24; i++) {
			UG::DrawSprite(aiBarbWireTop[i]);
			UG::DrawSprite(aiBarbWireBottom[i]);
		}	
		for (int i = 0; i < 23; i++) {
			UG::DrawSprite(aiBarbWireLeft[i]);
			UG::DrawSprite(aiBarbWireRight[i]);
		}
	}
	//Switch statement to ensure elements are drawn only when there relevent
	switch (level) {
	case VisualsManager::MENU:
		UG::DrawSprite(aiMenuSprite[0]);
		break;
	case VisualsManager::HELP:
		UG::DrawSprite(aiMenuSprite[1]);
		break;
	case VisualsManager::P1VICTORY:
		UG::DrawSprite(aiMenuSprite[2]);
		break;
	case VisualsManager::P2VICTORY:
		UG::DrawSprite(aiMenuSprite[3]);
		break;
	case VisualsManager::FIRST_LEVEL:

		for (int i = 0; i < 3; i++) {
			UG::DrawSprite(aiLevel1MetalBlock[i]);
		}
		for (int i = 0; i < 7; i++) {
			UG::DrawSprite(aiLevel1WoodBlock[i]);
		}
		break;
	case VisualsManager::SECOND_LEVEL:

		for (int i = 0; i < 5; i++) {
			UG::DrawSprite(aiLevel2MetalBlock[i]);
		}
		for (int i = 0; i < 9; i++) {
			UG::DrawSprite(aiLevel2WoodBlock[i]);
		}		
		break;
	case VisualsManager::THIRD_LEVEL:

		for (int i = 0; i < 7; i++) {
			UG::DrawSprite(aiLevel3MetalBlock[i]);
		}
		for (int i = 0; i < 11; i++) {
			UG::DrawSprite(aiLevel3WoodBlock[i]);
		}
		break;
	default:
		break;
	}
}
//This function is used to draw the pause background and does this with the help of the UG framework
void VisualsManager::RenderPause() {
	UG::DrawSprite(iPauseSprite);
}
//Deinitialise function used to destroy many of the sprites when no longer needed
void VisualsManager::Deinitialise() {
	//If the game is on one of the 3 levels then destroy it's floow tile sprites
	if (level == FIRST_LEVEL || level == SECOND_LEVEL || level == THIRD_LEVEL) {
		for (int i = 0; i < 625; i++) {
			UG::DestroySprite(aiFloorSpriteNumber[i]);
		}
	}
	//Switch statement for the destruction of level specific sprites
	switch (level) {
	//Case for the main menu to destroy it's sprite when this function is called
	case VisualsManager::MENU:
		UG::DestroySprite(aiMenuSprite[0]);
		break;
	//Case for the help menu to destroy it's sprite when this function is called
	case VisualsManager::HELP:
		UG::DestroySprite(aiMenuSprite[1]);
		break;
	//Case for the player 1 victory menu to destroy it's sprite when this function is called
	case VisualsManager::P1VICTORY:
		UG::DestroySprite(aiMenuSprite[2]);
		break;
	//Case for the player 2 victory menu to destroy it's sprite when this function is called
	case VisualsManager::P2VICTORY:
		UG::DestroySprite(aiMenuSprite[3]);
		break;
	//Case for when the game level is on the first level to desrt
	case VisualsManager::FIRST_LEVEL:
		for (int i = 0; i < 5; i++) {
			UG::DestroySprite(aiLevel1ConcreteBlock[i]);
		}
		for (int i = 0; i < 3; i++) {
			UG::DestroySprite(aiLevel1MetalBlock[i]);
		}
		for (int i = 0; i < 7; i++) {
			UG::DestroySprite(aiLevel1WoodBlock[i]);
		}
		break;
	//Case for when the game level is on the second level to destroy level specific sprites
	case VisualsManager::SECOND_LEVEL:
		for (int i = 0; i < 7; i++) {
			UG::DestroySprite(aiLevel2ConcreteBlock[i]);
		}
		for (int i = 0; i < 5; i++) {
			UG::DestroySprite(aiLevel2MetalBlock[i]);
		}
		for (int i = 0; i < 9; i++) {
			UG::DestroySprite(aiLevel2WoodBlock[i]);
		}
		break;
	//Case for when the game level is on the third level to destroy level specific sprites
	case VisualsManager::THIRD_LEVEL:
		for (int i = 0; i < 9; i++) {
			UG::DestroySprite(aiLevel3ConcreteBlock[i]);
		}
		for (int i = 0; i < 7; i++) {
			UG::DestroySprite(aiLevel3MetalBlock[i]);
		}
		for (int i = 0; i < 11; i++)  {
			UG::DestroySprite(aiLevel3WoodBlock[i]);
		}
		break;
	default:
		break;
	}
}