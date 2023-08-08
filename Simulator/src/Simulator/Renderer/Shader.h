#ifndef SHADER_H
#define SHADER_H


#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Shader
{
public:

	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
};

#endif