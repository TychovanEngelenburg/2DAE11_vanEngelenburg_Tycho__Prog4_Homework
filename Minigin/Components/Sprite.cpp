#include "Components/Sprite.h"
#include "GameObject.h"
#include "Renderer.h"
#include "ResourceManager.h"

void dae::Sprite::SetTexture(std::string_view filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}


#pragma region Game_Loop
void dae::Sprite::Render() const
{
	auto const& pos{ m_gameObject->GetTransform().GetPosition() };
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}
dae::Sprite::Sprite(std::string_view filename)
	: m_texture{ ResourceManager::GetInstance().LoadTexture(filename) }
{
}
#pragma endregion Game_Loop