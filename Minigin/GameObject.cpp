#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::Transform const& dae::GameObject::GetTransform()
{
	return m_transform;
}

std::string_view dae::GameObject::GetName()
{
	return m_name;
}

bool dae::GameObject::IsDestroyed()
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
void dae::GameObject::Update()
{
	for (auto& component : m_components)
	{
		if (!component.second->m_active)
		{
			continue;
		}
		component.second->Update();
	}
}

void dae::GameObject::FixedUpdate()
{
	for (auto& component : m_components)
	{
		if (!component.second->m_active)
		{
			continue;
		}
		component.second->FixedUpdate();
	}
}

void dae::GameObject::Render() const
{
	for (auto& component : m_components)
	{
		if (!component.second->m_active)
		{
			continue;
		}
		component.second->Render();
	}
}

void dae::GameObject::LateUpdate()
{
	for (auto& component : m_components)
	{
		if (!component.second->m_active)
		{
			continue;
		}
		component.second->LateUpdate();
	}
}
#pragma endregion

dae::GameObject::GameObject(std::string_view name, glm::vec3 pos)
	: m_name{ name }
	, m_transform{ pos }
	, m_components{}
	, m_active{true}
	, m_destroyed{}
{
	m_transform.SetPosition(pos);
}

dae::GameObject::~GameObject()
{
	m_components.clear();
}

