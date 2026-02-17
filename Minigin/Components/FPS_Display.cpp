#include "Components/FPS_Display.h"
#include "GameObject.h"
#include "Components/TextComponent.h"
#include <format>
#include <string>
#include "DeltaClock.h"

void dae::FPS_Display::FixedUpdate()
{
	//m_accuTime += DeltaClock::GetFixedDeltaTime();
	//++m_frameCount;
	//if (m_accuTime >= m_accuTimePerSec)
	//{
	//	UpdateDisplay();
	//	m_accuTime -= m_accuTimePerSec;
	//	m_frameCount = 0;
	//}
}

void dae::FPS_Display::Update()
{
	m_frameCount =1.0 / DeltaClock::GetDeltaTime();

	UpdateDisplay();
}

void dae::FPS_Display::UpdateDisplay()
{
	if (auto text{ m_gameObject->GetComponent<TextComponent>() })
	{
		std::string const fpsText{ std::format("{:.2f}", m_frameCount) };
		text.value()->SetText(fpsText);
	}
}

dae::FPS_Display::FPS_Display()
	: Component()
	, m_accuTime{}
	, m_frameCount{}
{
}