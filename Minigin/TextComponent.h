#ifndef TEXTUREOBJECT_H
#define TEXTUREOBJECT_H

#include <string>
#include <memory>
#include "Component.h"
#include <cstdint>
#include <SDL3/SDL_pixels.h>

namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent final : public Component
	{
	public:

		std::string GetText();

		void SetText(std::string_view text);
		void SetOffset(float x, float y);
		void SetColor(SDL_Color const& color);
	
		void Update() override;
		void Render() const override;

		TextComponent(std::string_view text, std::string_view fontFile, uint8_t size, SDL_Color const& color = { 255, 255, 255, 255 });
		
		~TextComponent() override = default;
		TextComponent(TextComponent const& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(TextComponent const& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;

	private:
		bool m_needsUpdate{};
		std::string m_text{};
		
		SDL_Color m_color{ 255, 255, 255, 255 };

		std::shared_ptr<Font> m_font{};
		std::shared_ptr<Texture2D> m_textTexture{};
	};
}
#endif // !TEXTUREOBJECT_H
