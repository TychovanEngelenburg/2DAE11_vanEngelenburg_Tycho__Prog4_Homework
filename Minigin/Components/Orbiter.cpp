#include "Component.h"
#include "DeltaClock.h"
#include "GameObject.h"
#include "Orbiter.h"
#include <cmath>

void dae::Orbiter::FixedUpdate()
{
	m_rotationDegrees += m_speed * static_cast<float>(DeltaClock::GetFixedDeltaTime());

	GetOwner()->GetTransform().SetLocalPosition(
		{
			std::sin(m_rotationDegrees) * m_radius,
			std::cos(m_rotationDegrees) * m_radius,
			0.f
		});
}

dae::Orbiter::Orbiter(GameObject& owner, float radius, float speed)
	: Component{ owner }
	, m_radius{ radius }
	, m_speed{ speed }
	, m_rotationDegrees{}
{
}
