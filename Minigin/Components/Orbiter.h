#ifndef ORBITER_H
#define ORBITER_H
#include "Component.h"

namespace dae
{
	class GameObject;
/// <summary>
/// Rudamentary/temporary component that makes an object orbit it's parent. (to demonstrate the scenegraph)
/// </summary>
	class Orbiter final : public Component
	{
	public:
		void FixedUpdate() override;

		Orbiter(GameObject& owner, float radius, float speed);

		~Orbiter() override = default;
		Orbiter(Orbiter const& other) = delete;
		Orbiter(Orbiter&& other) = delete;
		Orbiter& operator=(Orbiter const& other) = delete;
		Orbiter& operator=(Orbiter&& other) = delete;

	private:
		float m_radius;
		float m_speed;
		float m_rotationDegrees;
	};
}

#endif // !ORBITPARENT_H
