#ifndef IMGUIWINDOW_H
#define IMGUIWINDOW_H
#include <memory>
#include "ImGUI/imgui_CacheTester.h"

namespace dae
{
	class imgui_Window
	{
	public:
		void Render();

		imgui_Window();

		~imgui_Window() = default;
		imgui_Window(imgui_Window const& other) = delete;
		imgui_Window(imgui_Window&& other) = delete;
		imgui_Window& operator=(imgui_Window const& other) = delete;
		imgui_Window& operator=(imgui_Window&& other) = delete;

	private:
		std::unique_ptr<imgui_CacheTester> m_stressTestWindow;

	};
}
#endif // !IMGUIWINDOW_H
