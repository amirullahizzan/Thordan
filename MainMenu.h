
#pragma once

//h files are declaration and definition, cpp files are implementations

class MainMenu //class can act as a script object
{
public:
    bool bMainMenu =false;


void InitMainMenu()
{
	bMainMenu = true;

}

float fStartfontsize = 2;
int xdec = 0;
void DrawMainMenu()
{
	if (bMainMenu == true)
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
	extern bool bisGame;
	bool keyEnter = CheckHitKey(KEY_INPUT_ENTER);
	if (keyEnter == TRUE && bMainMenu == true)
	{
		bMainMenu = false;
		
		bisGame = true;
		//printf("Main Menu is %d", bMainMenu);
	}

	ShakeText();
}

void ShakeText()
{
	if (bMainMenu == true)
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