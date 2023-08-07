#include <Sim_pch.h>
#include "Application.h"


void Application::run() {

	m_Window = new Window(1600, 800, "Aqua Simulator");


	UIRenderer uiRenderer(m_Window);
	uiRenderer.Init();
	uiRenderer.AddUIElement(new ConsoleUI());


	setEventCallbacks();

	
	while (m_Running) {

		m_Window->PollEvents();

		uiRenderer.BeginFrame();
		uiRenderer.DrawElements();
		uiRenderer.EndFrame();

		m_Window->SwapBuffers();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

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