#include "WinMain.h"
#include "GameMain.h"

#include <Windows.h>

#include "../MainMenu.h"
#include "../StartGame.h"
#include "../StageData.h"

//IMPLEMENTATION

// =====================================================
//		初期化
//	ゲーム開始直後に最初に1回だけ実行される関数
//	最初の値を変数に入れたいときに使う
// =====================================================

//WHAT THIS GAME IS ABOUT:
//PLAYER JUKES AOE AND RUN AROUND THE MAP WHILE HITTING THE BOSS, DEFEATING HIM WITHIN THE TIME LIMIT


//MAKE a global var if you want to use it inside each Functions

MainMenu mainmenu;
StartGame startgame;
StartGame::Player player;
StageData stagedata;
StageData::AOECircle aoecircle(0,0,0);

int window_time = 0;
int start_time = 0;

int x;
int y;
int displaytime = 0;

void DrawAOE()
{
	
	
		int kari_data = 0;
		//while (true) {
		DrawFormatString(20, 20, WHITE, "%d秒", start_time, 0);
		//}
		//while cannot be used inside GameDraw()
		//DrawString(WINDOW_W / 2 - 150, 200 + 100, start_time, WHITE, 0);
		DrawCircleAA(x, y, 60, 60, ORANGE, 1, 0);
	
	
}

void GameInit()
{
	window_time = GetNowCount();
	PlayMusic("data/Thordan.mp3", DX_PLAYTYPE_LOOP);
	mainmenu.InitMainMenu();
	DrawAOE();
}



void CalculateAOE()
{
	start_time = (GetNowCount() - window_time) / 1000;
	if (mainmenu.bMainMenu == false) 
	{
		if (start_time > 3 && start_time < 6)
		{


			x = 500;
			y = 500;

		}
		else
		{
			x = 0;
			y = 0;
		}
	}
}

void GameUpdate()
{
	mainmenu.UpdateMainMenu();
	player.PlayerControl();
	//aoecircle.LoadWarningAOE(500, 500);
	CalculateAOE();
	
}



void GameDraw()
{
	
	mainmenu.DrawMainMenu();
	startgame.StartStage(stagedata);
	startgame.DrawPlayer(player, stagedata);
	DrawAOE();

	//aoecircle.DrawWarningAOE();

	
	
}

void GameExit()
{


}

//aoecircle.InvokeWarningAOE();
	//WaitTimer(1000);
	//Sleep(1000);