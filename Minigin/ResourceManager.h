#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <filesystem>
#include <map>
#include <memory>
#include <string>
#include <cstdint>
#include "Singleton.h"

namespace dae
{
	class Texture2D;
	class Font;
	class ResourceManager final : public Singleton<ResourceManager>
	{
	public:
		void Init(const std::filesystem::path& data);
		std::shared_ptr<Texture2D> LoadTexture(std::filesystem::path const& file);
		std::shared_ptr<Font> LoadFont(std::filesystem::path const& file, uint8_t size);

		void UnloadUnusedResources();
	private:
		friend class Singleton<ResourceManager>;
		std::filesystem::path m_dataPath;


		std::map<std::string, std::shared_ptr<Texture2D>> m_loadedTextures;
		std::map<std::pair<std::string, uint8_t>, std::shared_ptr<Font>> m_loadedFonts;

		ResourceManager() = default;
		~ResourceManager();
	};
}
#endif // !RESOURCEMANAGER_H