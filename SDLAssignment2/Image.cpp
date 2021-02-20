#include <iostream>
#include "Image.h"
#include <SDL_image.h>

Image::Image()
{
	m_image = nullptr;
}

void Image::SetResolution(int width, int height)
{
	m_resolution = { width, height };
}

bool Image::Load(const std::string& filename, Screen& screen)
{
	SDL_Surface* rawImageData = IMG_Load(filename.c_str());

	if (!rawImageData)
	{
		std::cout << "Error loading image file." << std::endl;
		return false;
	}

	m_image = SDL_CreateTextureFromSurface(screen.GetRenderer(), rawImageData);

	return true;
}

void Image::Unload()
{
	SDL_DestroyTexture(m_image);
}

void Image::Render(int xPos, int yPos, Screen& screen)
{
	SDL_Rect sourceRect;
	SDL_Rect targetRect;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = m_resolution.x;
	sourceRect.h = m_resolution.y;

	targetRect.x = xPos;
	targetRect.y = yPos;
	targetRect.w = sourceRect.w;
	targetRect.h = sourceRect.h;

	SDL_Point centre{ m_resolution.x * 0.5f, m_resolution.y * 0.5f };

	SDL_RenderCopyEx(screen.GetRenderer(), m_image, &sourceRect, &targetRect, 0.0, &centre, SDL_FLIP_NONE);
}