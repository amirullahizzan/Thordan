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
	SetMainWindowText("C++ ��b �W������");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ---------------
	// ����������
	// ---------------
	KeyInputInit();
	PadInputInit();
	MouseInputInit();
	GameInit();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();
		// ---------------
		// �X�V����
		// ---------------
		KeyInputUpdate();
		PadInputUpdate();
		MouseInputUpdate();
		GameUpdate();

		// ---------------
		// �`�揈��
		// ---------------
		ClearDrawScreen();
		GameDraw();
		ScreenFlip();
	}

	// ---------------
	// �I������
	// ---------------
	KeyInputExit();
	PadInputExit();
	MouseInputExit();
	GameExit();

	DxLib_End();

	return 0;
}
