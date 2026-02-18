#include "Components/FPS_Display.h"
#include "GameObject.h"
#include "Components/TextComponent.h"
#include <format>
#include <string>
#include "DeltaClock.h"

void dae::FPS_Display::Start()
{
	m_textComp = m_gameObject->GetComponent<TextComponent>();
	assert(m_textComp && "FPS_Display missing TextComponent on GameObject!");
}

void dae::FPS_Display::FixedUpdate()
{
}

void dae::FPS_Display::Update()
{
	//m_accuTime += DeltaClock::GetDeltaTime();
	//++m_frameCount;
	//if (m_accuTime >= m_accuTimePerSec)
	//{
	//	m_averageFPS = 1 / (m_accuTime / m_frameCount);

	//	UpdateDisplay();
	//	m_accuTime -= m_accuTimePerSec;
	//	m_frameCount -= m_averageFPS;
	//}

	m_averageFPS = 1.0 / DeltaClock::GetDeltaTime();
	UpdateDisplay();
}

void dae::FPS_Display::UpdateDisplay()
{

	std::string const fpsText{ std::format("{:.2f}", m_averageFPS) };
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