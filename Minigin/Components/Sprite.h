#ifndef SPRITE_H
#define SPRITE_H

#include "Components/Component.h"
#include "Types/Texture2D.h"

#include <memory>
#include <filesystem>

namespace dae
{
	class Sprite final : public Component
	{
	public:
		void SetTexture(std::filesystem::path const& filename);
		// TODO: Texture offset/scaling?

		void Render() const override;

		Sprite(std::filesystem::path const& filename);
		~Sprite() override = default;
		Sprite(Sprite const& other) = delete;
		Sprite(Sprite&& other) = delete;
		Sprite& operator=(Sprite const& other) = delete;
		Sprite& operator=(Sprite&& other) = delete;

	private:
		// TODO: No Shared_ptrs?
		std::shared_ptr<Texture2D> m_texture;
	};
}
#endif // !SPRITE_H
