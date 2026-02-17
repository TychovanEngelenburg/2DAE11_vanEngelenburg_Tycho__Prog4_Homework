#include "Component.h"
#include "GameObject.h"

void dae::Component::SetOwner(GameObject* gameObject)
{
	m_gameObject = gameObject;
}

#pragma region Game_Loop
void dae::Component::FixedUpdate()
{
}

void dae::Component::Update()
{
}

void dae::Component::Render() const
{
}
void dae::Component::LateUpdate() const
{
}
#pragma endregion Game_Loop

dae::Component::Component()
	: m_gameObject{}
	, m_active{true}
{
}
