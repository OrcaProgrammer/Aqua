
#include "Simulator/Core/Application.h"

int main() {
	
	Application* app = new Application();
	app->run();
	delete app;

	return 0;
}