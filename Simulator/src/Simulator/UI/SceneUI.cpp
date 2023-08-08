#include "Sim_pch.h"
#include "SceneUI.h"

SceneUI::SceneUI(unsigned int textureId) {
	m_TextureColorBuffer = reinterpret_cast<ImTextureID>(textureId);
}

void SceneUI::Draw() {

	ImGui::Begin("Scene");
	ImGui::Image(m_TextureColorBuffer, ImGui::GetContentRegionAvail(), ImVec2(0, 1), ImVec2(1, 0));
	ImGui::End();
}