#include <stdexcept>
#include <SDL3_ttf/SDL_ttf.h>
#include "Types/Font.h"
#include <filesystem>

TTF_Font* dae::Font::GetFont() const {
	return m_font;
}

dae::Font::Font(std::filesystem::path const& fullPath, float size) : m_font(nullptr)
{
	auto pathString{ fullPath.string()};
	m_font = TTF_OpenFont(pathString.c_str(), size);
	if (m_font == nullptr) 
	{
		throw std::runtime_error(std::string("Failed to load font: ") + SDL_GetError());
	}
}

dae::Font::~Font()
{
	TTF_CloseFont(m_font);
}
