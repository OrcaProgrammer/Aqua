#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

class ImGuiUI
{
public:
	const char* name;
	virtual void Draw() = 0;
};
