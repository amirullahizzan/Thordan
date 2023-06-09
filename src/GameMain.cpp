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

StartGame startgame;
StartGame::Player player;
StageData stagedata;
StageData::AOECircle aoecircle(0,0,0);


int window_time = 0;
int start_time = 0;


float x;
float y;
int displaytime = 0;


void DrawAOE()
{
		int kari_data = 0;
		DrawFormatString(20, 20, WHITE, "%d秒", start_time, 0);
		//DrawString(WINDOW_W / 2 - 150, 200 + 100, start_time, WHITE, 0);
		DrawCircleAA(x, y, 60, 60, ORANGE, 1, 0);
	
	
}



void GameInit()
{
	player.hp = 100;
	window_time = GetNowCount();
	PlayMusic("data/Thordan.mp3", DX_PLAYTYPE_LOOP);
	mainmenu.InitMainMenu();
	DrawAOE();
}


struct AOE
{
public:
	bool isplayerhit = false;
	//int enemydamage;
	int ax = 0;
	int ay = 0;
	int bx = 0;
	int by = 0;
	int rad = 80;

	void TriggerDamage()
	{
		if (!isplayerhit)
		{
		player.hp -= 10;
		isplayerhit = true;
		}
		//TODO reset on other AOE
		//exit(0);
	}

	void CheckCollAOE(const StartGame::Player& player, AOE& aoe)
	{
		float dx = aoe.bx - player.bx;
		float dy = aoe.by - player.by;
		float distance = sqrt(dx*dx + dy*dy);

		if (isGame && distance <= player.rad + aoe.rad)
		{
			aoe.TriggerDamage();
		}

	}

	int aoeduration = 3;
	
void CalculateAOE(float x, float y, int timespawn)
{
	
	DrawCircle(ax, ay, rad, ORANGE, 1, 1);
	DrawCircle(bx, by, rad, RED, 1, 1);
	
	if (gametimer.tickseconds >= timespawn)
	{
		ax = x;
		ay = y;
		
	}
	if (gametimer.tickseconds >= timespawn+aoeduration)
	{
		bx = ax;
		by = ay;
		ax = 0;
		ay = 0;
		if (gametimer.tickseconds >= aoeduration + 1 + timespawn)
		{
			bx = 0;
			by = 0;
		}
	}
}
};



AOE aoe;
void GameUpdate()
{
	gametimer.SecondsTick();
	mainmenu.UpdateMainMenu();
	player.PlayerControl();
	aoe.CheckCollAOE(player,aoe);
	
}

struct HPManager
{
public:
	void DrawHPBar()
	{
		if(isGame == true)
		{
		int x1 = 100;
		int y1 = 650;
		int x2 = x1+100;
		int y2 = y1+30;
		DrawString(x1 + 15, y1 - 25, "HP", WHITE, 0);
		DrawFillBox(x1, y1, x2 + player.hp, y2, GREEN);
		

		int x3 = 100;
		int y3 = 650;
		int x4 = x3 + 200;
		int y4 = y3 + 30;
		DrawLineBox(x3, y3, x4, y4, WHITE);
		}
	}
};

struct SkillBar
{
	void Draw()
	{
		if(mainmenu.isMainmenu == false)
		{
		int x1 = 60;
		int y1 = 550;
		DrawFillBox(x1, y1, x1 + x1, y1+x1, GRAY); //四角
		}
	}

	void Timer()
	{

	}
};


void GameDraw()
{
	if (isMainmenu)
	{
		mainmenu.DrawMainMenu();

	}
	startgame.StartStage(stagedata);
	aoe.CalculateAOE(600, 450, 3);
	aoe.CalculateAOE(700, 550, 5);
	startgame.DrawPlayer(player, stagedata);
	HPManager hpmanager;
	hpmanager.DrawHPBar();
	SkillBar skillbar;
	skillbar.Draw();
	
	
}

void GameExit()
{


}
