#pragma once

#include <vector>
#include "Simulator/Renderer/Shader.h"


class Renderer
{
private:
	unsigned int m_VAO, m_VBO, m_EBO, m_FBO, m_TextureColorBuffer;
	Shader* m_Shader;
	std::vector<float> m_Vertices;
	std::vector<unsigned int> m_Indices;

public:
	void Init();
	void Render();

	void SetShader(Shader* shader);
	void AddVertex(float vertex);
	void AddIndice(unsigned int indice);

	unsigned int GetTexID();
};

