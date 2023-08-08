#pragma once

#include <string>
#include <vector>
#include "Simulator/ImGui/ImGuiUI.h"

struct ConsoleLine {
	std::string text;
	ImVec4 color;
};

class ConsoleUI : public ImGuiUI
{
private:
	bool m_Open;
	bool m_AutoScroll = true;
	static std::vector<ConsoleLine> m_Lines;

public:
	virtual void Draw();
	static void AddLine(ConsoleLine line);
};

