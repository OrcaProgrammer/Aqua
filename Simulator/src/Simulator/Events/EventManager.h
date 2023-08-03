#pragma once

#include <deque>
#include "Simulator/Events/KeyEvent.h"

class EventManager
{
private:

	static EventManager* m_Instance;
	std::deque<KeyEvent*> m_KeyEvents;

protected:

	EventManager();

public:

	static EventManager* get();
	void addKeyEvent(KeyEvent* e);
	void pollKeyEvents(KeyCode key, KeyAction action);
	int sizeOfKeyEvents();
};