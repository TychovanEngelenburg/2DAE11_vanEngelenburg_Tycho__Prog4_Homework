#include "GameObject.h"

// .h includes
#include "Components/Component.h"
#include "Types/Transform.h"

#include <string_view>
#include <memory>
#include <glm/fwd.hpp>

dae::Transform const& dae::GameObject::GetTransform() const noexcept
{
	return m_transform;
}

std::string_view dae::GameObject::GetName() const noexcept
{
	return m_name;
}

bool dae::GameObject::IsDestroyed() const noexcept
{
	return m_destroyed;
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::Destroy()
{
	m_destroyed = true;
}

#pragma region Game_Loop
void dae::GameObject::Start()
{
	for (auto& component : m_components)
	{
		component->Start();
	}
}
void dae::GameObject::Update()
{
	for (auto& component : m_components)
	{
		if (!component->IsActive())
		{
			continue;
		}
		component->Update();
	}
}

void dae::GameObject::FixedUpdate()
{
	for (auto& component : m_components)
	{
		if (!component->IsActive())
		{
			continue;
		}
		component->FixedUpdate();
	}
}

void dae::GameObject::Render() const
{
	for (auto& component : m_components)
	{
		if (!component->IsActive())
		{
			continue;
		}
		component->Render();
	}
}

void dae::GameObject::LateUpdate()
{
	for (auto& component : m_components)
	{
		if (!component->IsActive())
		{
			continue;
		}
		component->LateUpdate();
	}
}

void dae::GameObject::End()
{
	for (auto& component : m_components)
	{
		component->End();
	}
}
#pragma endregion

dae::GameObject::GameObject(std::string_view name, glm::vec3 pos)
	: m_transform{ pos }
	, m_name{ name }
	, m_active{true}
	, m_destroyed{}
	, m_components{}
{
	m_transform.SetPosition(pos);
}

dae::GameObject::~GameObject()
{
	m_components.clear();
}
