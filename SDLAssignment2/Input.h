#pragma once

#include <SDL.h>

struct MousePos
{
	int x;
	int y;
};

class Input
{

public:

	Input();
	void Update();

	char GetKeyUp();
	char GetKeyDown();

	int GetMouseButtonUp();
	int GetMouseButtonDown();

	bool IsKeyPressed();
	bool IsMouseClicked();
	bool IsWindowClosed();

	const MousePos& GetMousePosition();

private:

	char m_keyUp;
	char m_keyDown;

	bool m_isKeyPressed;
	bool m_isMouseClicked;
	bool m_isWindowClosed;

	int m_mouseButtonUp;
	int m_mouseButtonDown;

	MousePos m_mousePosition;

};