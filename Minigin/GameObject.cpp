#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::Transform const& dae::GameObject::GetTransform()
{
	return m_transform;
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

//void dae::GameObject::SetName(std::string_view name)
//{
//	m_name = name;
//}

std::string_view dae::GameObject::GetName()
{
	return m_name;
}

#pragma region Game_Loop
void dae::GameObject::Update(double deltaTime)
{
	for (auto it{ m_components.begin() }; it != m_components.end(); ++it)
	{
		it->second->Update(deltaTime);
	}
}

void dae::GameObject::FixedUpdate(double fixedDeltaTime)
{
	for (auto it{ m_components.begin() }; it != m_components.end(); ++it)
	{
		it->second->FixedUpdate(fixedDeltaTime);
	}
}

void dae::GameObject::Render() const
{
	for (auto it{ m_components.begin() }; it != m_components.end(); ++it)
	{
		it->second->Render();
	}
}
#pragma endregion

dae::GameObject::GameObject(std::string_view name, glm::vec3 pos)
	: m_name{ name }
	, m_transform{ pos }
	, m_components{}
{
	m_transform.SetPosition(pos);
}