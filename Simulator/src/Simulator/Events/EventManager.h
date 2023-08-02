#pragma once

#include <deque>
#include "Simulator/Events/KeyEvent.h"

class EventManager
{
private:
	std::deque<KeyEvent*> m_KeyEvents;
public:

	~EventManager();

	void addKeyEvent(KeyEvent* e);
	void pollKeyEvents(KeyCode key, KeyAction action);
	int sizeOfKeyEvents();
};