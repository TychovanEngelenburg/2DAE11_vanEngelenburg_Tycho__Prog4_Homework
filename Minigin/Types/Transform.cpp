#include "Types/Transform.h"

// .h includes
#include <glm/detail/type_vec3.hpp>
#include <glm/fwd.hpp>

const glm::vec3& dae::Transform::GetPosition() const noexcept
{
	return m_position;
}

void dae::Transform::SetPosition(float x, float y, float z)
{
	this->SetPosition({ x, y, z });
}

void dae::Transform::SetPosition(glm::vec3 const& position)
{
	m_position = position;
}

void dae::Transform::Translate(float x, float y, float z)
{
	this->Translate({ x, y, z });
}

void dae::Transform::Translate(glm::vec3 const& difference)
{
	m_position += difference;
}

dae::Transform::Transform(glm::vec3 const& pos)
	: m_position{ pos }
{
}
