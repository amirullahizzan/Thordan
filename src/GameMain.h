#include "WinMain.h"

//only include headers in headers.

void GameInit();
void GameUpdate();
void GameDraw();
void GameExit();

#pragma once

//h files are declaration and definition, cpp files are implementations

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

MainMenu mainmenu;

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

GameTimer gametimer;