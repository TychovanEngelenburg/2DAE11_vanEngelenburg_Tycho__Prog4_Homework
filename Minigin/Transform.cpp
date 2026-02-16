#include "Transform.h"

void dae::Transform::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void dae::Transform::SetPosition(glm::vec3 const& position)
{
	m_position = position;
}

void dae::Transform::Translate(float x, float y, float z)
{
	Translate({ x, y, z });
}

void dae::Transform::Translate(glm::vec3 const& difference)
{
	m_position += difference;
}

dae::Transform::Transform(glm::vec3 pos)
	: m_position{ pos }
{
}
