#include <Sim_pch.h>
#include "Application.h"


void Application::run() {

	m_Window = new Window(1600, 800, "Aqua Simulator");

	std::string shaderName = "simpleShader";
	std::string vertShaderPath = ".\\src\\Simulator\\Shaders\\" + shaderName + ".vert";
	std::string fragShaderPath = ".\\src\\Simulator\\Shaders\\" + shaderName + ".frag";
	Shader* testShader = new Shader(vertShaderPath.c_str(), fragShaderPath.c_str());

	Aqua::AQUA2DFile file;
	file.read(".\\res\\2D files\\Cylinder_Sim.aqua2d");

	float vertices[] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
	   -0.5f, -0.5f, 0.0f,  // bottom left
	   -0.5f,  0.5f, 0.0f   // top left 
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	Renderer renderer;
	
	for (int i = 0; i < (sizeof(vertices) / sizeof(float)); i++) {
		renderer.AddVertex(vertices[i]);
	}
	for (int i = 0; i < (sizeof(indices) / sizeof(unsigned int)); i++) {
		renderer.AddIndice(indices[i]);
	}

	renderer.Init();
	renderer.SetShader(testShader);

	UIRenderer uiRenderer(m_Window);
	uiRenderer.Init();
	uiRenderer.AddUIElement(new ConsoleUI());
	uiRenderer.AddUIElement(new SceneUI(renderer.GetTexID()));

	setEventCallbacks();

	while (m_Running) {

		uiRenderer.BeginFrame();
		renderer.Render();
		uiRenderer.DrawElements();
		m_Window->ClearWindow();
		uiRenderer.EndFrame();

		m_Window->PollEvents();
		m_Window->SwapBuffers();

		m_Running = m_Window->IsWindowActive();
	}
}

void Application::setEventCallbacks() {

	EventManager* e_Manager = EventManager::get();

	KeyEvent* e_CloseWindow = new KeyEvent();
	e_CloseWindow->handle(KeyCode::ESCAPE, KeyAction::PRESSED);
	e_CloseWindow->setCallback([this]() {
		AQ_LOG("Escape key pressed!");
		this->getWindow()->CloseWindow();
		});

	KeyEvent* e_SpaceBar = new KeyEvent();
	e_SpaceBar->handle(KeyCode::SPACEBAR, KeyAction::PRESSED);
	e_SpaceBar->setCallback([]() {
		AQ_LOG("Spacebar pressed!");
		});

	KeyEvent* e_KeyA = new KeyEvent();
	e_KeyA->handle(KeyCode::KEY_A, KeyAction::PRESSED);
	e_KeyA->setCallback([]() {
		AQ_LOG("Key A pressed!");
		});

	e_Manager->addKeyEvent(e_CloseWindow);
	e_Manager->addKeyEvent(e_SpaceBar);
	e_Manager->addKeyEvent(e_KeyA);
	m_Window->SetEventCallbacks();
}

Window* Application::getWindow() {
	return m_Window;
}