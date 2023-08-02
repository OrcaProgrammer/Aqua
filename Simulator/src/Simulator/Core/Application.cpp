#include "Application.h"

void Application::run() {

	Window mainWindow(800, 600, "Test Window");

	while (m_Running) {
		mainWindow.Update();
		m_Running = mainWindow.IsWindowActive();
	}
}