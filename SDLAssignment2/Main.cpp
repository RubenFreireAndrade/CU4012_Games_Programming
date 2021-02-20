#include <iostream>
#include <SDL.h>
#include "Image.h"
#include "Input.h"
#include "Screen.h"

bool isGameRunning = true;

int main(int argc, char* argv[])
{
	Screen screen;
	Input input;
	Image background;
	Image hero;

	if (!screen.Initialize("My game", 1280, 720))
	{
		return 0;
	}

	//===========================================
	//MAIN GAME LOOP
	//===========================================

	background.Load("Assets/Images/City_1280x720.png", screen);
	background.SetResolution(1280, 720);

	hero.Load("Assets/Images/Hero.png", screen);
	hero.SetResolution(512, 512);

	while (isGameRunning)
	{
		screen.Clear();
		input.Update();

		if (input.IsWindowClosed())
		{
			isGameRunning = false;
		}

		if (input.GetKeyDown() == SDLK_ESCAPE)
		{
			isGameRunning = false;
		}

		static float xPos = 0.0f;
		xPos += 0.9f;

		background.Render(0, 0, screen);
		hero.Render(xPos, 100, screen);

		screen.Present();
	}

	hero.Unload();
	background.Unload();
	screen.Shutdown();
	return 0;
}