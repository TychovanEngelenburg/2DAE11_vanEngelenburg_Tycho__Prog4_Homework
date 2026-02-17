#ifndef FPS_DISPLAY_H
#define FPS_DISPLAY_H

#include <cstdint>
#include "Component.h"

namespace dae
{
	class FPS_Display final : public Component
	{
	public:
		void FixedUpdate() override;
		void Update() override;

		FPS_Display();
	private:
		void UpdateDisplay();

		static double constexpr m_accuTimePerSec{ 1 };
		double m_accuTime;
		double m_frameCount;
	};
}
#endif // !FPS_DISPLAY_H
