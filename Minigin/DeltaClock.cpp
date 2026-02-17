#include "DeltaClock.h"
#include <chrono>

double dae::DeltaClock::m_deltaTime = 0.0;

double dae::DeltaClock::GetDeltaTime()
{
	return m_deltaTime;
}

double dae::DeltaClock::GetFixedDeltaTime()
{
	static_assert(m_fixedDeltaTime > 0.0, "Deltatime must be a non-zero, positive value!");
	return m_fixedDeltaTime;
}

void dae::DeltaClock::Update()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	m_deltaTime = std::chrono::duration<double>( currentTime - m_lastTime).count();
	m_lastTime = currentTime;
}

dae::DeltaClock::DeltaClock()
	: m_lastTime{ std::chrono::high_resolution_clock::now() }
{
}