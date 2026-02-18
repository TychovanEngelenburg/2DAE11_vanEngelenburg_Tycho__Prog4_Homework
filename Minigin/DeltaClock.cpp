#include "DeltaClock.h"

// .h includes
#include <chrono>

double dae::DeltaClock::m_deltaTime = 0.0;

double dae::DeltaClock::GetDeltaTime() noexcept
{
	return m_deltaTime;
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
