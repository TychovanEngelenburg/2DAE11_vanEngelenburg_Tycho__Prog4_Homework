#ifndef MINIGIN_H
#define MINIGIN_H

#include <filesystem>
#include <functional>
#include <memory>

#include "DeltaClock.h"

namespace dae
{
	class Minigin final
	{
	public:
		void Run(const std::function<void()>& load);
		void RunOneFrame();
		void Close();

		explicit Minigin(std::filesystem::path const& dataPath);
		~Minigin();
		Minigin(Minigin const& other) = delete;
		Minigin(Minigin&& other) = delete;
		Minigin& operator=(Minigin const& other) = delete;
		Minigin& operator=(Minigin&& other) = delete;
	private:
		std::unique_ptr<DeltaClock> m_deltaClock;
		double m_lag;
		bool m_quit;
	};
}
#endif // !MINIGIN_H