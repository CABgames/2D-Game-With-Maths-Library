#include "GameManager.h"
#include <iostream>
//Variables
int iSetScreenWidth = 720;
int iSetScreenHeight = 750;
bool bStopSystemJump = false;
bool bStopPauseJump = false;
bool bStopLeveJump = false;
float fTank1Speed = 100.0f;
float fTank2Speed = 100.0f;
//Constructor function
GameManager::GameManager() {
}
//Destructor function
GameManager::~GameManager() {
}
//Called when initialises essential things such as the player vehicle
void GameManager::Initialise() {

	UG::Create(iSetScreenWidth, iSetScreenHeight, false, "TankDroid-War-Arcade", 100, 100);
	bGameNotQuit = true;	
	bGameNotQuit = UG::Process();
	level = MENU;
	vManager.InitialiseMenu();
	aiScores[0] = 9;
	aiScores[1] = 9;
	bPlayer1BulletLaunched = false;
	bPlayer2BulletLaunched = false;
	//Create the bullet for player 1
	//X1, Y1, X2, Y2
	float UVCoordinates5[] = { 0.99f,0.99f,0.99f,0.99f };
	pBullet1 = new GameSprite(
		"./images/BulletBlue.png",
		CVector2(40.0f, 40.0f).GetPointer(),
		CVector2(0.5f, 0.5f).GetPointer(),
		UVCoordinates5
	);
	pBullet1->SetPosition(CVector2(iSetScreenWidth * 0.25f, iSetScreenHeight * 0.5f));
	pBullet1->SetLayer(5);
	//Create the bullet for player 2
	//X1, Y1, X2, Y2
	float UVCoordinates6[] = { 0.99f,0.99f,0.99f,0.99f };
	pBullet2 = new GameSprite(
		"./images/BulletRed.png",
		CVector2(40.0f, 40.0f).GetPointer(),
		CVector2(0.5f, 0.5f).GetPointer(),
		UVCoordinates6
	);
	pBullet2->SetPosition(CVector2(iSetScreenWidth * 0.25f, iSetScreenHeight * 0.5f));
	pBullet2->SetLayer(5);
	//Create the tank body for player 1
	//X1, Y1, X2, Y2
	float UVCoordinates1[] = { 0.99f,0.99f,0.99f,0.99f };
	pTank1 = new GameSprite(
		"./images/TankBlue.png",
		CVector2(40.0f, 40.0f).GetPointer(),
		CVector2(0.5f, 0.5f).GetPointer(),
		UVCoordinates1
	);
	pTank1->SetPosition(CVector2(iSetScreenWidth * 0.25f, iSetScreenHeight * 0.5f));
	pTank1->SetLayer(3);
	//Create the tank turret for player 1
	//X1, Y1, X2, Y2
	float UVCoordinates2[] = { 0.99f,0.99f,0.99f,0.99f };
	pTurret1 = new GameSprite(
		"./images/TankGunTopBlue.png",
		CVector2(40.0f, 40.0f).GetPointer(),
		CVector2(0.5f, 0.4f).GetPointer(),
		UVCoordinates2
	);
	pTurret1->SettingVehicleParent(pTank1);
	pTurret1->SetLayer(4);

	//Create the tank body for player 2
	//X1, Y1, X2, Y2
	float UVCoordinates3[] = { 0.99f,0.99f,0.99f,0.99f };
	pTank2 = new GameSprite(
		"./images/TankRed.png",
		CVector2(40.0f, 40.0f).GetPointer(),
		CVector2(0.5f, 0.5f).GetPointer(),
		UVCoordinates3
	);
	pTank2->SetPosition(CVector2(iSetScreenWidth * 0.75f, iSetScreenHeight * 0.5f));
	pTank2->SetLayer(3);
	//Create the tank turret for player 2
	//X1, Y1, X2, Y2
	float UVCoordinates4[] = { 0.99f,0.99f,0.99f,0.99f };
	pTurret2 = new GameSprite(
		"./images/TankGunTopRed.png",
		CVector2(40.0f, 40.0f).GetPointer(),
		CVector2(0.5f, 0.4f).GetPointer(),
		UVCoordinates4
	);
	pTurret2->SettingVehicleParent(pTank2);
	pTurret2->SetLayer(4);
	Update();
}
//Function to set up initial positioning and other minor things
void GameManager::Positioning() {
	bIsPaused = false;
	bPlayer1IsDead = false;
	bPlayer2IsDead = false;
}
//Update function is called constantly no matter which game state the player is in
void GameManager::Update() {
	//Variables for the two players tank movement and bullets
	fCurrentVelocity = 0.f;
	fCurrentVelocity2 = 0.f;
	fCurrentVelocityBullet = 0.f;
	fCurrentVelocityBullet2 = 0.f;
	fMaxVelocity = 8.f;
	fMaxVelocity2 = 8.f;
	fMaxVelocityBullet = 8.f;
	fMaxVelocityBullet2 = 8.f;
	fPlayer1Drag = 0.04f;
	fPlayer2Drag = 0.04f;
	//Do this while UG process is running
	do {
		//dt is the difference in time between the last time
		dt = UG::GetDeltaTime();
		//X, Y, Z
		CMatrix3 movementMatrix = CMatrix3::Identity();
		CMatrix3 movementMatrix2 = CMatrix3::Identity();
		CMatrix3 movementMatrixBullet = CMatrix3::Identity();
		CMatrix3 movementMatrixBullet2 = CMatrix3::Identity();
		pTank1->GettingGlobalTransformation(movementMatrix);
		pTank2->GettingGlobalTransformation(movementMatrix2);
		pBullet1->GettingGlobalTransformation(movementMatrixBullet);
		pBullet2->GettingGlobalTransformation(movementMatrixBullet2);
		movementVector = movementMatrix.GetRow(1);
		movementVector2 = movementMatrix2.GetRow(1);
		movementVectorBullet = movementMatrixBullet.GetRow(1);
		movementVectorBullet2 = movementMatrixBullet2.GetRow(1);
		fPlayer1Accelleration = 0.f;
		fPlayer2Accelleration = 0.f;
		//Switch statement for the different states the menu can be at.
		switch (level) {
		case GameManager::MENU:
			//Sets a boolean false for allowing player to go to help screen/area
			if (UG::IsKeyUp(UG::KEY_2)) {
				bStopSystemJump = false;
			}
			//If the player presses 2 go to the help menu
			if (UG::IsKeyDown(UG::KEY_2) && bStopSystemJump == false) {
				level = HELP;
				vManager.Deinitialise();
				vManager.InitialiseHelp();
			}
			//If the player presses 1 play the game (start on first level)
			if (UG::IsKeyDown(UG::KEY_1)) {
				//Loop through this array reseting it in case it is not already
				bHasBeenSeen[0] = false;
				bHasBeenSeen[1] = false;
				bHasBeenSeen[2] = false;
				bHasBeenSeen[3] = false;
				bHasBeenSeen[4] = false;
				bHasBeenSeen[5] = false;
				bHasBeenSeen[6] = false;
				bHasBeenSeen[7] = false;
				bHasBeenSeen[8] = false;
				bPlayer1BulletLaunched = false;
				bPlayer2BulletLaunched = false;
				bStopPlayer1ShootJump = true;
				bStopPlayer2ShootJump = true;
				level = FIRST_LEVEL;
				vManager.Deinitialise();
				vManager.InitialiseLevel1();
				vManager.InitialiseCombat();
				vManager.InitialisePauseScreen();
				Positioning();
			}
			//If the user presses escape then quit the application
			if (UG::IsKeyDown(UG::KEY_ESCAPE)) {
				UG::Close();
			}
			break;
		case GameManager::HELP:
			if (UG::IsKeyUp(UG::KEY_2)) {
				bStopSystemJump = true;
			}
			//If the player presses 2 go to the main menu.
			if (UG::IsKeyDown(UG::KEY_2) && bStopSystemJump == true) {
				level = MENU;
				vManager.Deinitialise();
				vManager.InitialiseMenu();			
			}
			//If the player presses 1 play the game (start on first level)
			if (UG::IsKeyDown(UG::KEY_1)) {
				bHasBeenSeen[0] = false;
				bHasBeenSeen[1] = false;
				bHasBeenSeen[2] = false;
				bHasBeenSeen[3] = false;
				bHasBeenSeen[4] = false;
				bHasBeenSeen[5] = false;
				bHasBeenSeen[6] = false;
				bHasBeenSeen[7] = false;
				bHasBeenSeen[8] = false;
				bPlayer1BulletLaunched = false;
				bPlayer2BulletLaunched = false;
				bStopPlayer1ShootJump = true;
				bStopPlayer2ShootJump = true;
				level = FIRST_LEVEL;
				vManager.Deinitialise();
				vManager.InitialiseLevel1();
				vManager.InitialiseCombat();
				vManager.InitialisePauseScreen();
				Positioning();
			}
			//If the user presses escape then quit the application
			if (UG::IsKeyDown(UG::KEY_ESCAPE)) {
				UG::Close();
			}
			break;
		// Intentional fallthrough
		case GameManager::FIRST_LEVEL: 
		case GameManager::SECOND_LEVEL: 
		case GameManager::THIRD_LEVEL: 
			//If the game is not paused
			if (bIsPaused == false) {

				Powerups();

				for (int i = 0; i < aiScores[0]; i++) {
					UG::DrawSprite(vManager.aiHeartsBlue[i]);
				}
				for (int i = 0; i < aiScores[1]; i++) {
					UG::DrawSprite(vManager.aiHeartsRed[i]);
				}
				temporaryPositionVector = movementVector.normalised() * -5;
				temporaryPositionVector2 = movementVector2.normalised() * -5;
				//Go to the this function to check all the relevant box collisions
				BoxCollisionCheck();
				//Go to this function to check the inputs for the players vehicle
				CheckInput();
				//Go to this function to check the scores of the players
				CheckScores();
				//Sets a boolean false for allowing player to go to help screen/area
				if (UG::IsKeyUp(UG::KEY_ESCAPE)) {
					bStopPauseJump = false;
				}
				//If the player presses 2 go to the help menu
				if (UG::IsKeyDown(UG::KEY_ESCAPE) && bStopPauseJump == false) {
					bIsPaused = true;
				}
				//If this player is not dead
				if (bPlayer1IsDead == false) {
					//Go to the update function in scene for player 1 tank and turret
					pTank1->Update(dt);
					pTurret1->Update(dt);
					//Draw player 1 tank and it's child turret
					pTank1->Draw();
					pTurret1->Draw();
				}
				//If this player is not dead
				if (bPlayer2IsDead == false) {
					//Go to the update function in scene for player 1 tank and turret
					pTank2->Update(dt);
					pTurret2->Update(dt);
					//Draw player 2 tank and it's child turret
					pTank2->Draw();
					pTurret2->Draw();
				}
				if (bPlayer1BulletLaunched == true) {
					fCurrentVelocityBullet += 4.0f * dt;
					fCurrentVelocityBullet -= fCurrentVelocityBullet * 0.0f;
					if (fabs(fCurrentVelocityBullet) > fMaxVelocityBullet) {
						fCurrentVelocityBullet = fMaxVelocityBullet * sinf(fCurrentVelocityBullet);
					}
					if (fabs(fCurrentVelocityBullet) > FLT_EPSILON) {
						movementVectorBullet *= fCurrentVelocityBullet;
						pBullet1->MoveSprite(movementVectorBullet);
					}
					pBullet1->Update(dt);
					pBullet1->Draw();
				}
				if (bPlayer2BulletLaunched == true) {
					fCurrentVelocityBullet2 += 4.0f * dt;
					fCurrentVelocityBullet2 -= fCurrentVelocityBullet2 * 0.0f;
					if (fabs(fCurrentVelocityBullet2) > fMaxVelocityBullet2) {
						fCurrentVelocityBullet2 = fMaxVelocityBullet2 * sinf(fCurrentVelocityBullet2);
					}
					if (fabs(fCurrentVelocityBullet2) > FLT_EPSILON) {
						movementVectorBullet2 *= fCurrentVelocityBullet2;
						pBullet2->MoveSprite(movementVectorBullet2);
					}
					pBullet2->Update(dt);
					pBullet2->Draw();
				}
			}		
			//Pause here
			else {
				//Sets a boolean false for allowing player to go to help screen/area
				if (UG::IsKeyUp(UG::KEY_ESCAPE)) {
					bStopPauseJump = true;
				}
				//If the player presses 2 go to the help menu
				if (UG::IsKeyDown(UG::KEY_ESCAPE) && bStopPauseJump == true) {
					bIsPaused = false;
				}
				if (UG::IsKeyDown(UG::KEY_TAB)) {
					pTank1->SetPosition(CVector2(iSetScreenWidth * 0.25f, iSetScreenHeight * 0.5f));
					pTank2->SetPosition(CVector2(iSetScreenWidth * 0.75f, iSetScreenHeight * 0.5f));
					bIsPaused = false;
					level = MENU;
					vManager.Deinitialise();
					vManager.InitialiseMenu();
					aiScores[0] = 9;
					aiScores[1] = 9;
				}
				vManager.RenderPause();
			}
			break;
		case GameManager::P1WIN:
		case GameManager::P2WIN:
			if (UG::IsKeyDown(UG::KEY_SPACE)) {
				bIsPaused = false;
				level = MENU;
				pTank1->SetPosition(CVector2(iSetScreenWidth * 0.25f, iSetScreenHeight * 0.5f));
				pTank2->SetPosition(CVector2(iSetScreenWidth * 0.75f, iSetScreenHeight * 0.5f));
				vManager.Deinitialise();
				vManager.InitialiseMenu();
				aiScores[0] = 9;
				aiScores[1] = 9;
			}
			break;
		default:
			break;
		}
		vManager.Render();
		UG::ClearScreen();
	} 
	//Do this while UG process is running
	while (UG::Process());
	//Close the application
	UG::Dispose();
}
//This is a function to do an OBB collision check on the two tanks and bullets
void GameManager::OBBCollisionCheck() {		
	if (pTank2->obbBox->CheckOBBCollision(pTank1->obbBox)) {
		pTank2->MoveSprite(temporaryPositionVector2);
		pTank1->MoveSprite(temporaryPositionVector);
	}
	else if (bPlayer1BulletLaunched == true && pBullet1->obbBox->CheckOBBCollision(pTank2->obbBox)) {
	}
	else if (bPlayer2BulletLaunched == true && pBullet2->obbBox->CheckOBBCollision(pTank1->obbBox)) {
	}
}
//This is a function to do box collision checks, the collisions are the tanks then this goes through to OBB check
void GameManager::BoxCollisionCheck() {

	UG::DrawSprite(aiPowerups);

	if (pTank1->GetPosition(2)[0] - 15 < pTank2->GetPosition(2)[0] + 15
		&& pTank1->GetPosition(2)[0] + 15 > pTank2->GetPosition(2)[0] - 15
		&& pTank1->GetPosition(2)[1] - 15 < pTank2->GetPosition(2)[1] + 15
		&& pTank1->GetPosition(2)[1] + 15 > pTank2->GetPosition(2)[1] - 15
		) {
		OBBCollisionCheck();
	}
	if (bPlayer1BulletLaunched == true && pBullet1->GetPosition(2)[0] - 15 < pTank2->GetPosition(2)[0] + 15
		&& pBullet1->GetPosition(2)[0] + 15 > pTank2->GetPosition(2)[0] - 15
		&& pBullet1->GetPosition(2)[1] - 15 < pTank2->GetPosition(2)[1] + 15
		&& pBullet1->GetPosition(2)[1] + 15 > pTank2->GetPosition(2)[1] - 15
		) {
		aiScores[1] -= 1;
		bPlayer1BulletLaunched = false;
	}
	if (bPlayer1BulletLaunched == true && pBullet1->GetPosition(2)[0] - 15 < 0
		|| pBullet1->GetPosition(2)[0] + 15 > 720
		|| pBullet1->GetPosition(2)[1] - 15 < 0
		|| pBullet1->GetPosition(2)[1] + 15 > 750
		) {	
		bPlayer1BulletLaunched = false;
		pBullet1->SetPosition(CVector2(pTank1->GetPosition(2)[0], pTank1->GetPosition(2)[1]));
	}
	if (bPlayer2BulletLaunched == true && pBullet2->GetPosition(2)[0] - 15 < pTank1->GetPosition(2)[0] + 15
		&& pBullet2->GetPosition(2)[0] + 15 > pTank1->GetPosition(2)[0] - 15
		&& pBullet2->GetPosition(2)[1] - 15 < pTank1->GetPosition(2)[1] + 15
		&& pBullet2->GetPosition(2)[1] + 15 > pTank1->GetPosition(2)[1] - 15
		) {
		aiScores[0] -= 1;
		bPlayer2BulletLaunched = false;
	}
	if (bPlayer2BulletLaunched == true && pBullet2->GetPosition(2)[0] - 15 < 0
		|| pBullet2->GetPosition(2)[0] + 15 > 720
		|| pBullet2->GetPosition(2)[1] - 15 < 0
		|| pBullet2->GetPosition(2)[1] + 15 > 750
		) {
		bPlayer2BulletLaunched = false;
		pBullet2->SetPosition(CVector2(pTank2->GetPosition(2)[0], pTank2->GetPosition(2)[1]));
	}
	//Pushes player 1 back if they collide with barb wire but will send player back to start if manage to make their way out of map boundry
	if (pTank1->GetPosition(2)[0] - 15 < 30
		|| pTank1->GetPosition(2)[0] + 15 > 690
		|| pTank1->GetPosition(2)[1] - 15 < 30
		|| pTank1->GetPosition(2)[1] + 15 > 720
		) {
		if (pTank1->GetPosition(2)[0] - 15 < 0
			|| pTank1->GetPosition(2)[0] + 15 > 720
			|| pTank1->GetPosition(2)[1] - 15 < 0
			|| pTank1->GetPosition(2)[1] + 15 > 750
			) {
			pTank1->SetPosition(CVector2(720.0f * 0.25f, 750 * 0.5f));
		}
		else {
			pTank1->MoveSprite(temporaryPositionVector);
		}
	}
	//Pushes player 2 back if they collide with barb wire but will send player back to start if manage to make their way out of map boundry
	if (pTank2->GetPosition(2)[0] - 15 < 30
		|| pTank2->GetPosition(2)[0] + 15 > 690
		|| pTank2->GetPosition(2)[1] - 15 < 30
		|| pTank2->GetPosition(2)[1] + 15 > 720
		) {
		if (pTank1->GetPosition(2)[0] - 15 < 0
			|| pTank2->GetPosition(2)[0] + 15 > 720
			|| pTank2->GetPosition(2)[1] - 15 < 0
			|| pTank2->GetPosition(2)[1] + 15 > 750
			) {
			pTank2->SetPosition(CVector2(720.0f * 0.75f, 750 * 0.5f));
		}
		else {
			pTank2->MoveSprite(temporaryPositionVector2);
		}
	}
	//Switch statement for the level collision		
	switch (level) {
	case GameManager::FIRST_LEVEL:
		if (pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[3] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[3] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[5] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
				pTank1->MoveSprite(temporaryPositionVector);	
			}
		else if (pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[11] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[5] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[20] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[20] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
		}
		if (pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[3] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[3] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[5] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
		}
		else if (pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[11] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[5] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[20] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[20] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
		}
		//Random collider 1
	if (bHasBeenSeen[0] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[15] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[3] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[0] = true;
			RandomGeneration();
		}
		//Random collider 2
		else if (bHasBeenSeen[1] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[14] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[14] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[4] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[4] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[1] = true;
			RandomGeneration();
		}
		//Random collider 3
		else if (bHasBeenSeen[2] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[13] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[13] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[5] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[5] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[2] = true;
			RandomGeneration();
		}
		//Random collider 1
		if (bHasBeenSeen[0] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[15] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[3] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[0] = true;
			RandomGeneration();
		}
		//Random collider 2
		else if (bHasBeenSeen[1] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[14] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[14] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[4] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[4] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[1] = true;
			RandomGeneration();
		}
		//Random collider 3
		else if (bHasBeenSeen[2] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[13] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[13] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[5] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[5] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[2] = true;
			RandomGeneration();
		}
		break;
	case GameManager::SECOND_LEVEL:
		if (pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[15] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[3] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
			//Random collider 4
			if (bHasBeenSeen[3] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
				&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[15] - 15
				&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[3] + 15
				&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
				) {
				pTank1->MoveSprite(temporaryPositionVector);
				bHasBeenSeen[3] = true;
				RandomGeneration();
			}
			//Random collider 5
			else if (bHasBeenSeen[4] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[14] + 15
				&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[14] - 15
				&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[4] + 15
				&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[4] - 15
				) {
				pTank1->MoveSprite(temporaryPositionVector);
				bHasBeenSeen[4] = true;
				RandomGeneration();
			}
			//Random collider 6
			else if (bHasBeenSeen[5] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[13] + 15
				&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[13] - 15
				&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[5] + 15
				&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[5] - 15
				) {
				pTank1->MoveSprite(temporaryPositionVector);
				bHasBeenSeen[5] = true;
				RandomGeneration();
			}
			//Random collider 4
			if (bHasBeenSeen[3] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
				&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[15] - 15
				&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[3] + 15
				&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
				) {
				pTank2->MoveSprite(temporaryPositionVector);
				bHasBeenSeen[3] = true;
				RandomGeneration();
			}
			//Random collider 5
			else if (bHasBeenSeen[4] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[14] + 15
				&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[14] - 15
				&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[4] + 15
				&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[4] - 15
				) {
				pTank2->MoveSprite(temporaryPositionVector);
				bHasBeenSeen[4] = true;
				RandomGeneration();
			}
			//Random collider 6
			else if (bHasBeenSeen[5] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[13] + 15
				&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[13] - 15
				&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[5] + 15
				&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[5] - 15
				) {
				pTank2->MoveSprite(temporaryPositionVector);
				bHasBeenSeen[5] = true;
				RandomGeneration();
			}
		}
		else if (pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[13] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[5] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[20] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[20] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
		}
		if (pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[4] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[4] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[7] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
		}
		else if (pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[13] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[5] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[20] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[20] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
		}
		break;
	case GameManager::THIRD_LEVEL:
		//Random collider 7
		if (bHasBeenSeen[6] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[15] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[3] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[6] = true;
			RandomGeneration();
		}
		//Random collider 8
		else if (bHasBeenSeen[7] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[14] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[14] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[4] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[4] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[7] = true;
			RandomGeneration();
		}
		//Random collider 9
		else if (bHasBeenSeen[8] == false && pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[13] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[13] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[5] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[5] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[8] = true;
			RandomGeneration();
		}
		//Random collider 7
		if (bHasBeenSeen[6] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[15] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[3] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[6] = true;
			RandomGeneration();
		}
		//Random collider 8
		else if (bHasBeenSeen[7] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[14] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[14] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[4] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[4] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[7] = true;
			RandomGeneration();
		}
		//Random collider 9
		else if (bHasBeenSeen[8] == false && pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[13] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[13] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[5] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[5] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
			bHasBeenSeen[8] = true;
			RandomGeneration();
		}
		if (pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[2] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[2] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[9] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
		}
		else if (pTank1->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
			&& pTank1->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[5] - 15
			&& pTank1->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[20] + 15
			&& pTank1->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[20] - 15
			) {
			pTank1->MoveSprite(temporaryPositionVector);
		}

		if (pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[2] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[2] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[9] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[3] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
		}
		else if (pTank2->GetPosition(2)[0] - 15 < vManager.a_fSpritePositionsX[15] + 15
			&& pTank2->GetPosition(2)[0] + 15 > vManager.a_fSpritePositionsX[5] - 15
			&& pTank2->GetPosition(2)[1] - 15 < vManager.a_fSpritePositionsY[20] + 15
			&& pTank2->GetPosition(2)[1] + 15 > vManager.a_fSpritePositionsY[20] - 15
			) {
			pTank2->MoveSprite(temporaryPositionVector);
		}
		break;
	default:
		break;

	}
}
//Check input function checks the players vehicle input when on a level
void GameManager::CheckInput() {
	//If the game is not paused
	if (bIsPaused == false) {
		//If this player is not dead
		if (bPlayer1IsDead == false) {
			//Player1 movement
			//Forwards movement
			if (movementVector[2] < 300 && UG::IsKeyDown(UG::KEY_W)) {
				fPlayer1Accelleration += 1.25f;
				fPlayer1Drag = 0.f;
			}
			//Backwards movement
			if (UG::IsKeyDown(UG::KEY_S)) {
				fPlayer1Accelleration -= 1.25f;
				fPlayer1Drag = 0.f;
			}
			if (!UG::IsKeyDown(UG::KEY_W) && !UG::IsKeyDown(UG::KEY_S)) {
				fPlayer1Drag = 0.08f;
			}
			fCurrentVelocity += fPlayer1Accelleration * dt;
			fCurrentVelocity -= fCurrentVelocity * fPlayer1Drag;
			if (fabs(fCurrentVelocity) > fMaxVelocity) {
				fCurrentVelocity = fMaxVelocity * sinf(fCurrentVelocity);
			}
			if (fabs(fCurrentVelocity) > FLT_EPSILON) {
				movementVector *= fCurrentVelocity;
				pTank1->MoveSprite(movementVector);
			}
			//Tank1 Rotation
			if (UG::IsKeyDown(UG::KEY_A) && bPlayer1BulletLaunched == false) {
				pTank1->RotationZAxis(-0.02f);
				pBullet1->RotationZAxis(-0.02f);
			}
			if (UG::IsKeyDown(UG::KEY_D) && bPlayer1BulletLaunched == false) {
				pTank1->RotationZAxis(0.02f);
				pBullet1->RotationZAxis(0.02f);
			}
			//Turret1 Rotation
			if (UG::IsKeyDown(UG::KEY_Q) && bPlayer1BulletLaunched == false) {
				pTurret1->RotationZAxis(-0.035f);
				pBullet1->RotationZAxis(-0.035f);
			}
			if (UG::IsKeyDown(UG::KEY_E) && bPlayer1BulletLaunched == false) {
				pTurret1->RotationZAxis(0.035f);
				pBullet1->RotationZAxis(0.035f);
			}
			//Fire
			if (UG::IsKeyDown(UG::KEY_SPACE) && bPlayer1BulletLaunched == false && bStopPlayer1ShootJump == true) {
				bStopPlayer1ShootJump = false;
			}
			else if (UG::IsKeyDown(UG::KEY_SPACE) && bPlayer1BulletLaunched == false && bStopPlayer1ShootJump == false) {
				pBullet1->SetPosition(CVector2(pTank1->GetPosition(2)[0], pTank1->GetPosition(2)[1]));
				bPlayer1BulletLaunched = true;
				bStopPlayer1ShootJump = true;
			}
		}
		//If this player is not dead
		if (bPlayer2IsDead == false) {
			//Player2 movement
			//Forwards movement
			if (UG::IsKeyDown(UG::KEY_UP)) {
				fPlayer2Accelleration += 1.25f;
				fPlayer2Drag = 0.f;
			}
			//Backwards movement
			if (UG::IsKeyDown(UG::KEY_DOWN)) {
				fPlayer2Accelleration -= 1.25f;
				fPlayer2Drag = 0.f;
			}
			if (!UG::IsKeyDown(UG::KEY_UP) && !UG::IsKeyDown(UG::KEY_DOWN)) {
				fPlayer2Drag = 0.08f;
			}
			fCurrentVelocity2 += fPlayer2Accelleration * dt;
			fCurrentVelocity2 -= fCurrentVelocity2 * fPlayer2Drag;
			if (fabs(fCurrentVelocity2) > fMaxVelocity2) {
				fCurrentVelocity2 = fMaxVelocity2 * sinf(fCurrentVelocity2);
			}
			if (fabs(fCurrentVelocity2) > FLT_EPSILON) {
				movementVector2 *= fCurrentVelocity2;
				pTank2->MoveSprite(movementVector2);
			}
			//Tank2 Rotation
			if (UG::IsKeyDown(UG::KEY_LEFT) && bPlayer2BulletLaunched == false) {
				pTank2->RotationZAxis(-0.02f);
				pBullet2->RotationZAxis(-0.02f);
			}
			if (UG::IsKeyDown(UG::KEY_RIGHT) && bPlayer2BulletLaunched == false) {
				pTank2->RotationZAxis(0.02f);
				pBullet2->RotationZAxis(0.02f);
			}
			//Turret2 Rotation
			if (UG::IsKeyDown(UG::KEY_RIGHT_CONTROL) && bPlayer2BulletLaunched == false) {
				pTurret2->RotationZAxis(-0.035f);
				pBullet2->RotationZAxis(-0.035f);
			}
			if (UG::IsKeyDown(UG::KEY_KP_0) && bPlayer2BulletLaunched == false) {
				pTurret2->RotationZAxis(0.035f);
				pBullet2->RotationZAxis(0.035f);
			}
			//Fire
			if (UG::IsKeyDown(UG::KEY_ENTER) && bPlayer2BulletLaunched == false && bStopPlayer2ShootJump == true) {
				bStopPlayer2ShootJump = false;
			}
			else if (UG::IsKeyDown(UG::KEY_ENTER) && bPlayer2BulletLaunched == false && bStopPlayer2ShootJump == false) {
				pBullet2->SetPosition(CVector2(pTank2->GetPosition(2)[0], pTank2->GetPosition(2)[1]));
				bPlayer2BulletLaunched = true;
				bStopPlayer2ShootJump = true;
			}
		}

	}
}
//Check scores function checks the players score input when on a level
void GameManager::CheckScores() {
		//Score check for players and if scores certain value the levels will switch or show win screen
		if (aiScores[0] < 7 || (aiScores[1] < 7)) {
 			if (aiScores[0] < 4 || (aiScores[1] < 4)) {
				if (level != P2WIN && aiScores[0] <= 3) {
					vManager.Deinitialise();
					vManager.InitialiseP2VictoryScreen();
					level = P2WIN;
					bPlayer1IsDead = false;
					bPlayer2IsDead = false;
					aiScores[0] = 9;
					aiScores[1] = 9;
				}
				else if (level != P1WIN && aiScores[1] <= 3) {
					vManager.Deinitialise();
					vManager.InitialiseP1VictoryScreen();
					level = P1WIN;
					bPlayer1IsDead = false;
					bPlayer2IsDead = false;
					aiScores[0] = 9;
					aiScores[1] = 9;
				}
				else if (level != THIRD_LEVEL) {
					level = THIRD_LEVEL;
					vManager.Deinitialise();
					vManager.InitialiseLevel3();
					vManager.InitialiseCombat();
					bPlayer1IsDead = false;
					bPlayer2IsDead = false;
				}
			}
			else if (level != SECOND_LEVEL) {
				level = SECOND_LEVEL;
				vManager.Deinitialise();
				vManager.InitialiseLevel2();
				vManager.InitialiseCombat();
				bPlayer1IsDead = false;
				bPlayer2IsDead = false;
			}
		}
	}
//Randomly generates a value from between the specified amounts within the iPowerupRange
void GameManager::RandomGeneration() {
	std::mt19937 range;
	range.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> iPowerupRange(1,6);
	iPowerupRange(range);
	switch (iPowerupRange(range)) {
	case 1:
		//P1 damage
		aiScores[0] -= 1;
		break;
	case 2:
		//P2 damage
		aiScores[1] -= 1;
		break;
	case 3:
		if (aiScores[0] < 9) {
			aiScores[0] += 1;
		}
		else {
			aiScores[1] -= 1;
		}
		//P1 heal
		break;
	case 4:
		//P2 heal
		if (aiScores[1] < 9) {
			aiScores[1] += 1;
		}
		else {
			aiScores[0] -= 1;
		}
		break;
	case 5:
		//P1 speed
		fVehicle1Speed += 1.0f;
		break;
	case 6:
		//P2 speed
		fVehicle2Speed += 1.0f;
		break;
	default:
		break;
	}
}
//This function checks which of the powerups have not yet been taken and renders the relevant ones
void GameManager::Powerups() {
	if (level == FIRST_LEVEL) {
		if (bHasBeenSeen[0] == false) {
			UG::DrawSprite(vManager.aiLevel1ConcreteBlock[0]);
		}
		if (bHasBeenSeen[1] == false) {
			UG::DrawSprite(vManager.aiLevel1ConcreteBlock[1]);
		}
		if (bHasBeenSeen[2] == false) {
			UG::DrawSprite(vManager.aiLevel1ConcreteBlock[2]);
		}
	}
	else if (level == SECOND_LEVEL) {
		if (bHasBeenSeen[3] == false) {
			UG::DrawSprite(vManager.aiLevel2ConcreteBlock[0]);
		}
		if (bHasBeenSeen[4] == false) {
			UG::DrawSprite(vManager.aiLevel2ConcreteBlock[1]);
		}
		if (bHasBeenSeen[5] == false) {
			UG::DrawSprite(vManager.aiLevel2ConcreteBlock[2]);
		}
	}
	else if (level == THIRD_LEVEL) {
		if (bHasBeenSeen[6] == false) {
			UG::DrawSprite(vManager.aiLevel3ConcreteBlock[0]);
		}
		if (bHasBeenSeen[7] == false) {
			UG::DrawSprite(vManager.aiLevel3ConcreteBlock[1]);
		}
		if (bHasBeenSeen[8] == false) {
			UG::DrawSprite(vManager.aiLevel3ConcreteBlock[2]);
		}
	}
}