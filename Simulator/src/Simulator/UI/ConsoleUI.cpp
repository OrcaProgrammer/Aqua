#include "Sim_pch.h"
#include "ConsoleUI.h"

void ConsoleUI::Draw() {
	ImGui::Begin("Console", &m_Open);
	ImGui::Separator();
	ImGui::BeginChild("scrolling");

	for (ConsoleLine line : m_Lines) {
		ImGui::PushStyleColor(ImGuiCol_Text, line.color);
		ImGui::Text(line.text.c_str());
		ImGui::PopStyleColor();
	}

	if (m_AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
		ImGui::SetScrollHereY(1.0f);

	ImGui::EndChild();
	ImGui::End();
}


void ConsoleUI::AddLine(ConsoleLine line) {
	m_Lines.push_back(line);
}


std::vector<ConsoleLine> ConsoleUI::m_Lines = {};