#include "Components/Component.h"

#pragma region Game_Loop
void dae::Component::Start() {}

void dae::Component::FixedUpdate() {}

void dae::Component::Update() {}

void dae::Component::Render() const {}

void dae::Component::LateUpdate() {}

void dae::Component::End() {}
#pragma endregion Game_Loop

dae::Component::Component()
	: m_gameObject{}
	, m_active{ true }
{
}
