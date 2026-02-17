#include <stdexcept>
#include <SDL3_ttf/SDL_ttf.h>
#include "ResourceManager.h"
#include "Renderer.h"
#include "Types/Texture2D.h"
#include "Types/Font.h"
#include <filesystem>

void dae::ResourceManager::Init(std::filesystem::path const& dataPath)
{
	m_dataPath = dataPath;

	if (!TTF_Init())
	{
		throw std::runtime_error(std::string("Failed to load support for fonts: ") + SDL_GetError());
	}
}

std::shared_ptr<dae::Texture2D> dae::ResourceManager::LoadTexture(std::filesystem::path const& file)
{
	auto const fullPath = m_dataPath / file;
	auto const filename = std::filesystem::path(fullPath).filename().string();

	if (m_loadedTextures.find(filename) == m_loadedTextures.end())
	{
		auto texture{ std::make_shared<Texture2D>(fullPath) };
		m_loadedTextures.insert(std::pair(filename, std::move(texture)));
	}
	return m_loadedTextures.at(filename);
}

std::shared_ptr<dae::Font> dae::ResourceManager::LoadFont(std::filesystem::path const& file, uint8_t size)
{
	auto const fullPath = m_dataPath / file;
	auto const filename = std::filesystem::path(fullPath).filename().string();

	auto const key = std::pair<std::string, uint8_t>(filename, size);

	if (m_loadedFonts.find(key) == m_loadedFonts.end())
	{
		auto font{ std::make_shared<Font>(fullPath, size) };
		m_loadedFonts.insert(std::pair(key, std::move(font)));
	}
	return m_loadedFonts.at(key);
}

void dae::ResourceManager::UnloadUnusedResources()
{
	for (auto it = m_loadedTextures.begin(); it != m_loadedTextures.end();)
	{
		if (it->second.use_count() <= 1)
		{
			it = m_loadedTextures.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto it = m_loadedFonts.begin(); it != m_loadedFonts.end();)
	{
		if (it->second.use_count() <= 1)
		{
			it = m_loadedFonts.erase(it);
		}
		else
		{
			++it;
		}
	}
}

dae::ResourceManager::~ResourceManager()
{
	m_loadedFonts.clear();
	m_loadedTextures.clear();

	TTF_Quit();
}
