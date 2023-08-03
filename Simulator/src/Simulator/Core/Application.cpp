#include <Sim_pch.h>
#include "Application.h"


void Application::run() {

	Window mainWindow(800, 600, "Test Window");

	EventManager* e_Manager = EventManager::get();

	KeyEvent* e_CloseWindow = new KeyEvent();
	e_CloseWindow->handle(KeyCode::ESCAPE, KeyAction::PRESSED);
	e_CloseWindow->setCallback([&mainWindow]() {
		AQ_LOG("Escape key pressed!");
		mainWindow.CloseWindow(); 
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
	mainWindow.SetEventCallbacks();

	while (m_Running) {

		mainWindow.Update();
		m_Running = mainWindow.IsWindowActive();

	}
}