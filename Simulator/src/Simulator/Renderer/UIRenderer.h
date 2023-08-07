#pragma once

#include <deque>
#include "Simulator/Core/Window.h"
#include "Simulator/ImGui/ImGuiUI.h"

class UIRenderer
{
private:
	Window* m_Window;
	std::deque<ImGuiUI*> m_Elements;
public:

	UIRenderer(Window* window);
	~UIRenderer();

	void Init();
	void BeginFrame();
	void DrawElements();
	void EndFrame();

	void AddUIElement(ImGuiUI* element);
	void RemoveUIElement(const char* name);
};

