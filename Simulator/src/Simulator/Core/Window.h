#pragma once

#include <string>
#include <GlAD/glad.h>
#include <GLFW/glfw3.h>

#include "Aqua/Core/Logger.h"

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

	void Update();
	bool IsWindowActive();

};

