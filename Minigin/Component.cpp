#include "Component.h"
#include "GameObject.h"

void dae::Component::SetOwner(GameObject* gameObject)
{
	m_gameObject = gameObject;
}

void dae::Component::FixedUpdate(double fixedDeltaTime)
{
	fixedDeltaTime; // Prevent unreferenced parameter warning
}

void dae::Component::Update(double deltaTime)
{
	deltaTime; // Prevent unreferenced parameter warning
}

void dae::Component::Render() const
{
}

dae::Component::Component()
	: m_gameObject{}
{
}
