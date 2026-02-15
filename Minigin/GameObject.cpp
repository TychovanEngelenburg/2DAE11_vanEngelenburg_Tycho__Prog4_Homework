#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject() = default;

#pragma region Game_Loop
void dae::GameObject::Update(double deltaTime)
{
	deltaTime; 
	// No implementation yet.
}

void dae::GameObject::FixedUpdate(double fixedDeltaTime)
{
	fixedDeltaTime;
	// No implementation yet.
}

void dae::GameObject::Render() const
{
	auto const& pos = m_transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}
#pragma endregion

void dae::GameObject::SetTexture(std::string const& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}
