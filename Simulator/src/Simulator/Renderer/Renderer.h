#pragma once

#include <vector>
#include "Simulator/Renderer/Shader.h"

class Renderer
{
private:
	unsigned int m_VAO, m_VBO, m_EBO, m_FBO, m_TextureColorBuffer;
	Shader* m_Shader;
	float* m_Data;

public:
	void Init();
	void Render();

	void SetShader(Shader* shader);
	void SetData(float* data);

	unsigned int GetTexID();
};

