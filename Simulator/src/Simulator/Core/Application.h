#pragma once

#include <Aqua.h>
#include "Simulator/Core/Window.h"
#include "Simulator/Events/EventManager.h"
#include "Simulator/Events/KeyEvent.h"

class Application
{
private:
	bool m_Running = true;

public:
	void run();
};

