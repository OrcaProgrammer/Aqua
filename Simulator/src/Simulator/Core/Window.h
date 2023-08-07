#pragma once

#include "Simulator/Events/EventManager.h"
#include "Simulator/Events/KeyEvent.h"

#include <string>

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
	void PollEvents();
	void SwapBuffers();
	void CloseWindow();
	bool IsWindowActive();

	GLFWwindow* GetWindow();

};

