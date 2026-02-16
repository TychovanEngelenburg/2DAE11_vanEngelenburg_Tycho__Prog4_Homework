#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "Texture2D.h"
#include <memory>

namespace dae
{
	class Sprite : public Component
	{
	public:
		void SetTexture(std::string_view filename);

		void Render() const override;

		Sprite(std::string_view filename);
		// TODO: Texture offset/scaling?
	private:
		// TODO: Centralized texture loading.
		std::shared_ptr<Texture2D> m_texture;
	};
}
#endif // !SPRITE_H
