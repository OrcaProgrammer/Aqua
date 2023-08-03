#pragma once

#include "Aqua/Core/Logger.h"
#include "Simulator/Events/EventManager.h"
#include "Simulator/Events/KeyEvent.h"

class Window
{
private:
	GLFWwindow* m_Window;
	int m_Width;
	int m_Height;
	std::string m_Title;

public:
	
	Window(int width, int height, std::string title);
	~Window();

	void SetEventCallbacks();
	void Update();
	void CloseWindow();
	bool IsWindowActive();

};

