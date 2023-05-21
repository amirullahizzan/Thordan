#pragma once

#include <chrono>

extern MainMenu mainmenu;


class StageData
{
public:
	float arenax = 0;
	float arenay = 0;
	float rad = 0;
	StageData() {};
	
	//init //èâä˙âª
	//CTRL M M
	

		//constructor is args without function or return point
		float xa = WINDOW_W / 2, ya = WINDOW_H / 2;
		float radius = 360;

		class AOECircle
		{
		public:
			AOECircle(float x,float y,float radius) :  AOEposx1(x), AOEposy1(y),AOEradius(radius) {}
			
			float AOEradius = 40;
			float AOEposx1 = WINDOW_W / 2;
			float AOEposy1 = WINDOW_H / 2;

			
			bool is_spawned = false;
			int AOEDelay = 5;
			void LoadWarningAOE(float x, float y)
			{
				if (mainmenu.bMainMenu == false && is_spawned == false)
				{
				
					auto start_time = std::chrono::steady_clock::now();

				while (is_spawned == false)
				{
					auto current_time = std::chrono::steady_clock::now();
					auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count(); //template function, É¢a - É¢b
					if (elapsed_time >= AOEDelay)
					{
						AOEposx1 = x;
						AOEposy1 = y;
					
						is_spawned = true; 
						printf("AOEWarning released");
						break; //inner loops
					}
				}
				
					
				}

			}

			void DrawWarningAOE()
			{
				DrawCircleAA(AOEposx1, AOEposy1, AOEradius, 60, YELLOW, 1, 0);
			}

		};
	

	void loadStage1(StageData& stagedata)
	{
		arenax = stagedata.xa;
		arenay = stagedata.ya;
		rad = stagedata.radius;
		DrawCircleAA(arenax, arenay, rad, 60, WHITE, 1, 1);
		
	}

};


//STATIC FUNCTIONS.
//void InvokeWarningAOE()
//{
//	//DETACHING THREAD, AND CALL IT WITH THIS
//	// not good for micro stuff
//	if (mainmenu.bMainMenu == false && once == false)
//	{
//	std::thread t(&StageData::Stage1Data::AOECircle::LoadWarningAOE, this);
//	
//	m_bRemoveAOE = false;
//	once = true;
//	if (m_bRemoveAOE == false)
//	{
//		//InvokeHitAOE();
//		//AOEradius = 0; //disables the aoe effectively
//		
//	}
//	t.detach();
//	}
//}

//threading
		/*std::this_thread::sleep_for(std::chrono::seconds(AOEDelay));
		DrawWarningAOE();
		std::this_thread::sleep_for(std::chrono::seconds(AOEDespawn));
		printf("AOE has been disabled");*/
		//works but need better stuff
		//AOEradius = 0;
		//once = true;

	//init


