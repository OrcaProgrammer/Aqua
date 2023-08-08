#include <Sim_pch.h>
#include "Application.h"


void Application::run() {

	m_Window = new Window(1600, 800, "Aqua Simulator");

	std::string shaderName = "simpleShader";
	std::string vertShaderPath = ".\\src\\Simulator\\Shaders\\" + shaderName + ".vert";
	std::string fragShaderPath = ".\\src\\Simulator\\Shaders\\" + shaderName + ".frag";
	Shader* testShader = new Shader(vertShaderPath.c_str(), fragShaderPath.c_str());

	Renderer renderer;
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