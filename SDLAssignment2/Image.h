#pragma once

#include <string>
#include <SDL.h>
#include "Screen.h"

class Image
{

public:

	Image();
	~Image() {}

	void SetResolution(int width, int height);
	bool Load(const std::string& filename, Screen& screen);
	void Unload();
	void Render(int xPos, int yPos, Screen& screen);

private:

	SDL_Texture* m_image;
	SDL_Point m_resolution;

};

