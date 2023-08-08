#include "Sim_pch.h"
#include "UIRenderer.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <filesystem>

UIRenderer::UIRenderer(Window* window) {
	m_Window = window;
}

void UIRenderer::Init() {
	
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	ImGui_ImplGlfw_InitForOpenGL(m_Window->GetWindow(), true);
	ImGui_ImplOpenGL3_Init();

	io.Fonts->AddFontFromFileTTF(".\\res\\fonts\\TitilliumWeb-1eq2.ttf", 22.0f);

	ImGui::StyleColorsDark();
}

void UIRenderer::BeginFrame() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
}

void UIRenderer::DrawElements() {
	for (ImGuiUI* el : m_Elements) {
		el->Draw();
	}
}

void UIRenderer::EndFrame() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

UIRenderer::~UIRenderer() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void UIRenderer::AddUIElement(ImGuiUI* element) {
	m_Elements.push_back(element);
}