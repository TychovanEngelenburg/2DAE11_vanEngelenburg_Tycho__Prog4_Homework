#ifndef SPRITE_H
#define SPRITE_H

#include "Components/Component.h"
#include "Types/Texture2D.h"
#include <memory>

namespace dae
{
	class Sprite final : public Component
	{
	public:
		void SetTexture(std::string_view filename);

		void Render() const override;

		Sprite(std::string_view filename);
		// TODO: Texture offset/scaling?

		~Sprite() override = default;

		Sprite(Sprite const& other) = delete;
		Sprite(Sprite&& other) = delete;
		Sprite& operator=(Sprite const& other) = delete;
		Sprite& operator=(Sprite&& other) = delete;

	private:
		// TODO: Centralized texture loading.
		std::shared_ptr<Texture2D> m_texture;
	};
}
#endif // !SPRITE_H
