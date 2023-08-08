#include "Sim_pch.h"
#include "Shader.h"


Shader::Shader(const char* vertexPath, const char* fragmentPath) {

	std::string vertexShaderCode;
	std::string fragmentShaderCode;
	std::ifstream vertShaderFile;
	std::ifstream fragShaderFile;

	// ensure ifstream objects can throw exceptions:
	vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);


	// read in shader code
	try
	{
		// open files
		vertShaderFile.open(vertexPath);
		fragShaderFile.open(fragmentPath);

		// create temp string storage
		std::stringstream vertStream, fragStream;

		// read files
		vertStream << vertShaderFile.rdbuf();
		fragStream << fragShaderFile.rdbuf();

		// close files
		vertShaderFile.close();
		fragShaderFile.close();

		// convert stream to strings
		vertexShaderCode = vertStream.str();
		fragmentShaderCode = fragStream.str();
	}
	catch (std::ifstream::failure e)
	{
		AQ_DEBUG_ERROR("Failed to read shader files!");
	}
	AQ_DEBUG_TRACE("Shader files read successfully.");

	// create shader objects
	const char* vertexSourceCode = vertexShaderCode.c_str();
	const char* fragmentSourceCode = fragmentShaderCode.c_str();

	unsigned int vertShaderID, fragShaderID;
	vertShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);


	// compile vertex shader code
	glShaderSource(vertShaderID, 1, &vertexSourceCode, NULL);
	glCompileShader(vertShaderID);

	int success;
	char infolog[512];
	glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertShaderID, 512, NULL, infolog);
		AQ_DEBUG_ERROR("Failed to compile vertex shader!");
		AQ_DEBUG_ERROR(infolog);
	}
	AQ_DEBUG_TRACE("Vertex shader compiled successfully.");


	// compile fragment shader code
	glShaderSource(fragShaderID, 1, &fragmentSourceCode, NULL);
	glCompileShader(fragShaderID);

	glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragShaderID, 512, NULL, infolog);
		AQ_DEBUG_ERROR("Failed to compile fragment shader!");
		AQ_DEBUG_ERROR(infolog);
	}
	AQ_DEBUG_TRACE("Fragment shader complied successfully.");


	// link shaders to program
	ID = glCreateProgram();
	glAttachShader(ID, vertShaderID);
	glAttachShader(ID, fragShaderID);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infolog);
		AQ_DEBUG_ERROR("Failed to link shaders!");
		AQ_DEBUG_ERROR(infolog);
	}
	AQ_DEBUG_TRACE("Shaders linked successfully.");


	// delete shaders
	glDeleteShader(vertShaderID);
	glDeleteShader(fragShaderID);
}

void Shader::use() {
	glUseProgram(ID);
}