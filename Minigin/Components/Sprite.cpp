#include "Components/Sprite.h"

#include "ResourceManager.h"
#include "Renderer.h"
#include "GameObject.h"

// .h includes
#include "Components/Component.h"
#include "Types/Texture2D.h"
#include <memory>
#include <filesystem>

void dae::Sprite::SetTexture(std::filesystem::path const& filePath)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filePath);
}


#pragma region Game_Loop
void dae::Sprite::Render() const
{
	auto const& pos{ m_gameObject->GetTransform().GetPosition() };
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}
dae::Sprite::Sprite(std::filesystem::path const& filePath)
	: m_texture{ ResourceManager::GetInstance().LoadTexture(filePath) }
{
}
#pragma endregion Game_Loop
