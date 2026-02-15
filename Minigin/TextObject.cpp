#include <stdexcept>
#include <SDL3_ttf/SDL_ttf.h>
#include "TextObject.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"

#pragma region Game_loop
void dae::TextObject::Update(double deltaTime)
{
	deltaTime;

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

void dae::TextObject::Render() const
{
	if (m_textTexture != nullptr)
	{
		auto const& pos = m_transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
	}
}
#pragma endregion Game_loop

void dae::TextObject::SetText(std::string_view text)
{
	m_text = text;
	m_needsUpdate = true;
}

void dae::TextObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y);
}

void dae::TextObject::SetColor(SDL_Color const& color)
{
	m_color = color;
	m_needsUpdate = true;
}

dae::TextObject::TextObject(std::string_view text, std::shared_ptr<Font> font, SDL_Color const& color)
	: m_needsUpdate(true), m_text(text), m_color(color), m_font(std::move(font)), m_textTexture(nullptr)
{
}
