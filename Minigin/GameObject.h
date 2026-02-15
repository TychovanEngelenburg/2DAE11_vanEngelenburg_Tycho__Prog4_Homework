#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <memory>
#include "Transform.h"

namespace dae
{
	class Texture2D;
	class GameObject 
	{
	public:
		GameObject() = default;
		virtual ~GameObject();
		GameObject( GameObject const& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(GameObject const& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		virtual void Update(double deltaTime);
		virtual void FixedUpdate(double fixedDeltaTime);
		virtual void Render() const;

		void SetTexture(std::string const& filename);
		void SetPosition(float x, float y);
	private:
		Transform m_transform{};
		std::shared_ptr<Texture2D> m_texture{};
	};
}
#endif // !GAMEOBJECT_H