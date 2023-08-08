#pragma once

#include "Simulator/ImGui/ImGuiUI.h"

class SceneUI : public ImGuiUI
{
private:
	ImTextureID m_TextureColorBuffer;

public:
	SceneUI(unsigned int textureId);
	virtual void Draw();
};

