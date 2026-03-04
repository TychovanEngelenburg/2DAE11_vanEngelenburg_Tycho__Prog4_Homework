#include "imgui_window.h"


void dae::imgui_Window::Render()
{
	m_stressTestWindow->RenderCacheTestWindow();
}  

dae::imgui_Window::imgui_Window()
	: m_stressTestWindow{ std::make_unique<dae::imgui_CacheTester>() }
{
}
