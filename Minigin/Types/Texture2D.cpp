#include <stdexcept>
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include "Types/Texture2D.h"
#include "Renderer.h"


glm::vec2 dae::Texture2D::GetSize() const
{
	float w{}, h{};
	SDL_GetTextureSize(m_texture, &w, &h);
	return { w, h };
}

SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return m_texture;
}

dae::Texture2D::Texture2D(std::filesystem::path const& fullPath)
{
	auto pathStr{ fullPath.string() };
	SDL_Surface* surface = SDL_LoadPNG(pathStr.c_str());

	if (!surface)
	{
		throw std::runtime_error(
			std::string("Failed to load PNG: ") + SDL_GetError()
		);
	}

	m_texture = SDL_CreateTextureFromSurface(
		Renderer::GetInstance().GetSDLRenderer(),
		surface
	);

	SDL_DestroySurface(surface);

	if (!m_texture)
	{
		throw std::runtime_error(
			std::string("Failed to create texture from surface: ") + SDL_GetError()
		);
	}
}

dae::Texture2D::Texture2D(SDL_Texture* texture) : m_texture{ texture }
{
	assert(m_texture != nullptr);
}


dae::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_texture);
}