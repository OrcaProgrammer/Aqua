#include "Application.h"

void Application::run() {

	Logger::Log("Log ", "message");
	Logger::Trace("Trace message");
	Logger::Info("Info message");
	Logger::Warn("Warning message");
	Logger::Error("Error message with ", 0, " errors detected.");
}