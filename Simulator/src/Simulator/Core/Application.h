#pragma once

#include <Aqua.h>
#include "Simulator/Core/Window.h"
#include "Simulator/Events/EventManager.h"
#include "Simulator/Events/KeyEvent.h"
#include "Simulator/Renderer/UIRenderer.h"

#include "Simulator/UI/ConsoleUI.h"

class Application
{
private:
	bool m_Running = true;
	Window* m_Window;

public:
	void run();
	void setEventCallbacks();
	Window* getWindow();
};

