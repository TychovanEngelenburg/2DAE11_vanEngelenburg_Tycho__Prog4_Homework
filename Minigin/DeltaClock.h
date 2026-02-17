#ifndef DELTACLOCK_H
#define DELTACLOCK_H

#include <chrono>

namespace dae
{


	class DeltaClock
	{
	public:
		static double GetDeltaTime();
		static double GetFixedDeltaTime();

		void Update();

		DeltaClock();

	private:
		static double constexpr m_fixedDeltaTime{ 0.02 };
		static double m_deltaTime;
		std::chrono::high_resolution_clock::time_point m_lastTime;
	};
}
#endif // !DELTACLOCK_H
