#include <Sim_pch.h>
#include "EventManager.h"

EventManager* EventManager::m_Instance = 0;

EventManager::EventManager() {}

EventManager* EventManager::get() {
	if (m_Instance == 0)
		m_Instance = new EventManager;

	return m_Instance;
}

void EventManager::addKeyEvent(KeyEvent* e) {
	m_KeyEvents.push_back(e);
}

void EventManager::pollKeyEvents(KeyCode key, KeyAction action) {

	for (KeyEvent* e : m_KeyEvents) {
		if (e->isActive(key, action))
			e->callback();
	}
}

int EventManager::sizeOfKeyEvents() {
	return m_KeyEvents.size();
}