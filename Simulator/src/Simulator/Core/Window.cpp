#include <Sim_pch.h>
#include "Window.h"

Window::Window(int width, int height, std::string title) :
	m_Width{ width }, m_Height{ height }, m_Title{ title } {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);

	if (!m_Window) {
		Logger::Error("GLFW window failed to create!");
		glfwTerminate();
	}
	else
		Logger::Trace("GLFW window created successfully.");

	glfwMakeContextCurrent(m_Window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		Logger::Error("Failed to initialise GLAD!");
	else
		Logger::Trace("GLAD initialised successfully.");

	glViewport(0, 0, m_Width, m_Height);
}

Window::~Window() {
	delete m_Window;
}

void Window::SetEventCallbacks(EventManager manager) {
	
	m_EvtManager = manager;
	glfwSetWindowUserPointer(m_Window, this);

	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mode) {
		Window& self = *static_cast<Window*>(glfwGetWindowUserPointer(window));
		KeyCode keyUsed = static_cast<KeyCode>(key);
		KeyAction actionDone = static_cast<KeyAction>(action);
		self.m_EvtManager.pollKeyEvents(keyUsed, actionDone);
	});
}

void Window::Update() {
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Window::CloseWindow() {
	glfwSetWindowShouldClose(m_Window, true);
}

bool Window::IsWindowActive() {
	return !glfwWindowShouldClose(m_Window);
}