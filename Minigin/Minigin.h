#pragma once
#include <string>
#include <functional>
#include <filesystem>
#include <chrono>

namespace dae
{
	class Minigin final
	{
	public:
		explicit Minigin(const std::filesystem::path& dataPath);
		~Minigin();
		void Run(const std::function<void()>& load);
		void RunOneFrame();

		Minigin(const Minigin& other) = delete;
		Minigin(Minigin&& other) = delete;
		Minigin& operator=(const Minigin& other) = delete;
		Minigin& operator=(Minigin&& other) = delete;
	private:
		static float constexpr m_fixedDeltaTime{ 0.2f };
		std::chrono::steady_clock::time_point m_lastFrameTime{}; // TODO: change the way timekeeping is handled.
		double m_Lag{};

		bool m_quit{};
	};
}