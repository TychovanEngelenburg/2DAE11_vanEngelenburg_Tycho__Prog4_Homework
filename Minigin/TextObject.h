#ifndef TEXTUREOBJECT_H
#define TEXTUREOBJECT_H

#include <string>
#include <memory>
#include "GameObject.h"
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextObject final : public GameObject // TODO: Implement association over inheritance.
	{
	public:
		void Update(double deltaTime) override;
		void Render() const override;

		void SetText(std::string_view text);
		void SetPosition(float x, float y);
		void SetColor(SDL_Color const& color);

		TextObject(std::string_view text, std::shared_ptr<Font> font, SDL_Color const& color = { 255, 255, 255, 255 });
		virtual ~TextObject() = default;
		TextObject(TextObject const& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(TextObject const& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;

	private:
		bool m_needsUpdate{};
		std::string m_text{};
		SDL_Color m_color{ 255, 255, 255, 255 };
		Transform m_transform{};
		std::shared_ptr<Font> m_font{};
		std::shared_ptr<Texture2D> m_textTexture{};
	};
}
#endif // !TEXTUREOBJECT_H
