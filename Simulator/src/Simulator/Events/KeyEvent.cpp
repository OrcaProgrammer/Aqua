#include <Sim_pch.h>
#include "KeyEvent.h"

void KeyEvent::handle(KeyCode key, KeyAction action) {
	m_Key = key;
	m_Action = action;
}

void KeyEvent::setCallback(std::function<void()> callback) {
	m_Callback = callback;
}

void KeyEvent::callback() {
	m_Callback();
}

bool KeyEvent::isActive(KeyCode key, KeyAction action) {
	return (key == m_Key) && (action == m_Action);
}