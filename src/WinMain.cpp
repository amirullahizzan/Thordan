#include "WinMain.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (AllocConsole()) {
		FILE *fp;
		freopen_s(&fp, "CONOUT$", "w", stdout);
		SetConsoleTitle("Debug Console");
	}
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("C++ 基礎 集中授業");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ---------------
	// 初期化処理
	// ---------------
	KeyInputInit();
	PadInputInit();
	MouseInputInit();
	GameInit();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();
		// ---------------
		// 更新処理
		// ---------------
		KeyInputUpdate();
		PadInputUpdate();
		MouseInputUpdate();
		GameUpdate();

		// ---------------
		// 描画処理
		// ---------------
		ClearDrawScreen();
		GameDraw();
		ScreenFlip();
	}

	// ---------------
	// 終了処理
	// ---------------
	KeyInputExit();
	PadInputExit();
	MouseInputExit();
	GameExit();

	DxLib_End();

	return 0;
}
