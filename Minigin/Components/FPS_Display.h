#ifndef FPS_DISPLAY_H
#define FPS_DISPLAY_H

#include <cstdint>
#include "Components/Component.h"

namespace dae
{
	class TextComponent;
	class FPS_Display final : public Component
	{
	public:
		void Start() override;
		void FixedUpdate() override;
		void Update() override;

		FPS_Display();
	private:
		void UpdateDisplay();

		static double constexpr m_accuTimePerSec{ 1 };
		TextComponent* m_textComp;
		double m_accuTime;
		double m_frameCount;
		double m_averageFPS;
	};
}
#endif // !FPS_DISPLAY_H
