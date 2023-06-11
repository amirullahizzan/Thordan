
#include "src/WinMain.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

#include "StageData.h"

	bool isGame = false;
	bool isMainMenu = false;

struct MainMenu
{
public:
	bool isMainmenu = false;

	void InitMainMenu()
	{
		isMainmenu = true;
	}

	float fStartfontsize = 2;
	int xdec = 0;
	void DrawMainMenu()
	{
		if (isMainmenu == true)
		{
			float fBigfontsize = 4;
			DrawExtendString(WINDOW_W / 2 - 270, 200, fBigfontsize, fBigfontsize, "Dragon's Reprise", YELLOW, 0);
			DrawString(WINDOW_W / 2 - 150, 200 + 100, "Race to the end before the time is up", WHITE, 0);


			DrawExtendString(WINDOW_W / 2 - 120 - xdec, 200 + 400, fStartfontsize, fStartfontsize, "Press Enter to Start", WHITE, 0);
		}
		else return;

	}

	void UpdateMainMenu()
	{
		extern bool isGame;
		bool keyEnter = CheckHitKey(KEY_INPUT_ENTER);
		if (keyEnter == TRUE && isMainmenu == true)
		{
			isMainmenu = false;

			isGame = true;
		}

		ShakeText();
	}

	void ShakeText()
	{
		if (isMainmenu == true)
		{

			bool bFlag = false;
			if (fStartfontsize < 2 && bFlag == false)
			{
				fStartfontsize = fStartfontsize + 0.01f;
				xdec += 1;
				if (fStartfontsize > 2)
					bFlag = true;

			}
			else
			{
				bFlag = true;
				fStartfontsize = 1.5;
				xdec = 0;


				if (fStartfontsize < 1 && bFlag == true)
				{
					bFlag = false;
				}
			}
		}
	}


};


struct GameTimer
{
	int tickms;
	int tickseconds;

	int MsTick()
	{
		tickms++;
		return tickms;
	}

	void SecondsTick()
	{
		if (MsTick() > 60)
		{
			tickseconds++;
			tickms = 0;
		}
	}



};


struct StartGame //class can act as a script object
{
public:
	
struct Player
{
public:
	int hp = 0;
	float bx = 255, by = 255; //data members
	const int basespeed = 1;
	int rad = 25;
	int spawnx = WINDOW_W /2, spawny = WINDOW_H / 2 + 250; //data members

	//Player(float xpos, float ypos) : x(xpos), y(ypos) {} //Constructor

	void Move(int ax, int ay)
	{
		
		bx += ax * basespeed;
		by += ay * basespeed;
		//printf("Move Function Called");
	}
	
	

	void PlayerControl()
	{
		bool keyLeft = CheckHitKey(KEY_INPUT_LEFT);
		bool keyRight = CheckHitKey(KEY_INPUT_RIGHT);
		bool keyUp = CheckHitKey(KEY_INPUT_UP);
		bool keyDown = CheckHitKey(KEY_INPUT_DOWN);
		bool keySpace = IsKeyOn(KEY_INPUT_SPACE);
		//TODO Change to WASD

		//auto x = 1;
		//auto y = 1.1;
		
		
		
		if (keySpace == TRUE)
		{
			printf("%d", isGame);


			//toggle
			/*if(btest ==true)
			{
			btest = false;
			printf("BOOL = %d ",btest);
			}
			else if (btest ==false)
			{
				btest = true;
				printf("BOOL = %d ", btest);
			}*/
		}
		if (keyLeft == TRUE && isGame == true)
		{
			Move(-1, 0);
			printf("Left");
		}

		if (keyRight == TRUE && isGame == true)
		{
			Move(1, 0);
			printf("Right");
		}

		if (keyUp == TRUE&& isGame == true)
		{
			Move(0, -1);
			printf("Up");
		}

		if (keyDown == TRUE && isGame == true)
		{
			Move(0, 1);
			printf("Down");
		}
		if (IsMouseRepeat(MOUSE_INPUT_LEFT)) //gets a mouse click
		{
			//pos_x = GetMouseX();
			//pos_y = GetMouseY();
		}
		//if (isKeyOn(KEY_INPUT_SPACE))
		//if (IsMouseOn(MOUSE_INPUT_LEFT)) //gets a mouse click
		//if (isKeyRepeat(KEY_INPUT_SPACE))
	}

	



private:
	bool btest = false;
	
};
//END OF PLAYER CLASS





void DrawArena(StageData& stagedata)
{
	//printf("%d", this->xa);
	stagedata.loadStage1(stagedata);
	
	// if succeed loadStage2();
}

bool bSpawned = false;

void SetPlayerSpawn(Player& player)
{
	
	//get a Spawn Pos and set it to the player ONCE
	if (bSpawned == false)
	{
		player.bx = player.spawnx;
		player.by = player.spawny;
		//printf("%f", player.bx);
		//printf("%f", player.by);
		bSpawned = true;
	}

}

void DrawPlayer(Player& player, StageData stagedata)
{
	if (mainmenu.isMainmenu == false)
	{ 
	SetPlayerSpawn(player);
	DrawCircle(player.bx, player.by, player.rad+3, BLACK, 1, 1);
	DrawCircle(player.bx, player.by, player.rad, YELLOW, 1, 1);
	CheckPlayerBoundary(player, stagedata);
	}
	//printf("%d", player.bx);
	//printf("%d", player.by);
}



void SpawnEnemy(StageData stagedata)
{

}

void CheckPlayerBoundary(Player& player, StageData& stagedata)
{
	//pythagorean formula
	double distance = sqrt(pow(player.bx - stagedata.arenax, 2) + pow(player.by - stagedata.arenay, 2));
	if (distance > stagedata.rad) 
	{ 
		//printf(" dist %d ",distance);
		exit(0);
	}
}


void StartStage(StageData& stagedata)
{
	if (mainmenu.isMainmenu == false)
	{
	
		isGame = true;
		DrawArena(stagedata);
		
		//SpawnEnemy(stageData);
	}

}



};

StartGame startgame;




