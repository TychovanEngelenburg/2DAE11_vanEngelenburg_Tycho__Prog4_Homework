#ifndef ORBITER_H
#define ORBITER_H
#include "Component.h"

/// <summary>
/// Rudamentary/temporary component to demonstrate the scenegraph.
/// </summary>
namespace dae
{
	class GameObject;
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
