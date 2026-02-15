#ifndef MINIGIN_H
#define MINIGIN_H

#include <string>
#include <functional>
#include <filesystem>
#include <chrono>

namespace dae
{
	class Minigin final
	{
	public:
		void Run(const std::function<void()>& load);
		void RunOneFrame();

		explicit Minigin(std::filesystem::path const& dataPath);
		~Minigin();
		Minigin(Minigin const& other) = delete;
		Minigin(Minigin&& other) = delete;
		Minigin& operator=(Minigin const& other) = delete;
		Minigin& operator=(Minigin&& other) = delete;
	private:
		static float constexpr m_fixedDeltaTime{ 0.2f };
		std::chrono::steady_clock::time_point m_lastFrameTime{}; // TODO: change the way timekeeping is handled.
		double m_Lag{};

		bool m_quit{};
	};
}
#endif // !MINIGIN_H