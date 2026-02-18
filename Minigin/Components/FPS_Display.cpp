#include "Components/FPS_Display.h"
#include "GameObject.h"
#include "Components/TextComponent.h"
#include "DeltaClock.h"

#include <format>
#include <string>
#include <cassert>

#pragma region Game_Loop
void dae::FPS_Display::Start()
{
	m_textComp = m_gameObject->GetComponent<TextComponent>();
	assert(m_textComp && "FPS_Display requires a TextComponent on it's GameObject!");
}

void dae::FPS_Display::Update()
{
	m_accuTime += DeltaClock::GetDeltaTime();
	++m_frameCount;
	if (m_accuTime >= m_accuTimePerSec)
	{
		m_averageFPS = m_frameCount / m_accuTime;

		UpdateDisplay();
		m_accuTime -= m_accuTimePerSec;
		m_frameCount -= m_averageFPS;
	}
}
#pragma endregion Game_Loop

void dae::FPS_Display::UpdateDisplay()
{

	std::string const fpsText{ std::format("{:.1f} FPS", m_averageFPS) };
	m_textComp->SetText(fpsText);
}

dae::FPS_Display::FPS_Display()
	: Component()
	, m_textComp{}
	, m_accuTime{}
	, m_frameCount{}
	, m_averageFPS{}
{
}
