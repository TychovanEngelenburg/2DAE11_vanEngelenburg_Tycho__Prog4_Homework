#include <stdexcept>
#include <SDL3_ttf/SDL_ttf.h>
#include "Components/TextComponent.h"
#include "Renderer.h"
#include "Types/Font.h"
#include "Types/Texture2D.h"
#include "GameObject.h"
#include "Components/Component.h"
#include "ResourceManager.h"

void dae::TextComponent::SetText(std::string_view text)
{
	m_text = text;
	m_needsUpdate = true;
}

void dae::TextComponent::SetOffset(float x, float y)
{
	m_gameObject->SetPosition(x, y);
}

void dae::TextComponent::SetColor(SDL_Color const& color)
{
	m_color = color;
	m_needsUpdate = true;
}

#pragma region Game_loop
void dae::TextComponent::Update()
{
	if (m_needsUpdate)
	{
		auto const surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), m_text.length(), m_color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}

		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		
		SDL_DestroySurface(surf);
		m_textTexture = std::make_shared<Texture2D>(texture);
		m_needsUpdate = false;
	}
}

void dae::TextComponent::Render() const
{
	if (m_textTexture != nullptr)
	{
		auto const& pos = m_gameObject->GetTransform().GetPosition();
		Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
	}
}
std::string dae::TextComponent::GetText()
{
	return m_text;
}
#pragma endregion Game_loop


dae::TextComponent::TextComponent(std::string_view text, std::string_view fontFile, uint8_t size, SDL_Color const& color)
	: Component()
	, m_needsUpdate(true)
	, m_text(text)
	, m_color(color)
	, m_font(dae::ResourceManager::GetInstance().LoadFont(fontFile, size))
	, m_textTexture(nullptr)
{

}
