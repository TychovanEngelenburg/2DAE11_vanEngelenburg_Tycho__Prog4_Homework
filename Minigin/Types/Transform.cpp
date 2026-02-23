#include "Types/Transform.h"
#include <glm/detail/type_vec3.hpp>
#include <glm/fwd.hpp>
#include <vector>
#include <algorithm>

const glm::vec3& dae::Transform::GetPosition()
{
	if (m_positionDirty)
	{
		UpdateWorldPos();
	}
	return m_worldPosition;
}

glm::vec3 const& dae::Transform::GetLocalPosition()
{
	return m_localPosition;
}

dae::Transform* dae::Transform::GetParent() const noexcept
{
	return m_parent;
}

int dae::Transform::GetChildCount() const noexcept
{
	return  static_cast<int>(m_children.size());
}

dae::Transform* dae::Transform::GetChildAt() const noexcept
{
	return nullptr;
}

void dae::Transform::SetParent(Transform* parent, bool keepWorldPos)
{
	if (IsChildOf(parent) || parent == this || m_parent == parent)
	{
		return;
	}

	if (parent == nullptr)
	{
		SetLocalPosition(GetPosition());
	}
	else
	{
		if (keepWorldPos)
		{
			SetLocalPosition(GetPosition() - parent->GetPosition());
		}
		SetPositionDirty();
	}

	if (m_parent)
	{
		m_parent->RemoveChild(this);
	}

	m_parent = parent;

	if (m_parent)
	{
		m_parent->AddChild(this);
	}
}

bool dae::Transform::IsChildOf(Transform* child)
{

	if (std::find(m_children.begin(), m_children.end(), child) != m_children.end())
	{
		return true;
	}

	return false;
}

void dae::Transform::AddChild(Transform* child)
{
	if (child == nullptr)
	{
		return;
	}

	m_children.emplace_back(child);
}

void dae::Transform::RemoveChild(Transform* child)
{

	std::erase(m_children, child);

}

//void dae::Transform::SetPosition(float x, float y, float z)
//{
//	this->SetPosition({ x, y, z });
//}

void dae::Transform::SetPosition(glm::vec3 const& position)
{
	m_positionDirty = false;
	m_worldPosition = position;

	if (GetParent() == nullptr)
	{
		m_localPosition = position;
	}
	else
	{
		m_localPosition = position - GetParent()->GetPosition();
	}

}

void dae::Transform::SetLocalPosition(glm::vec3 const& pos)
{
	m_localPosition = pos;
	SetPositionDirty();
}

void dae::Transform::SetPositionDirty()
{
	m_positionDirty = true;
}

void dae::Transform::UpdateWorldPos()
{
	if (m_positionDirty)
	{
		if (GetParent() == nullptr)
		{
			m_worldPosition = m_localPosition;
		}
		else
		{
			m_worldPosition = GetParent()->GetPosition() + m_localPosition;
		}
	}
	m_positionDirty = false;
}

void dae::Transform::Translate(float x, float y, float z)
{
	this->Translate({ x, y, z });
}

void dae::Transform::Translate(glm::vec3 const& difference)
{
	m_worldPosition += difference;
}

dae::Transform::Transform(glm::vec3 const& pos)
	: m_positionDirty{ true }
	, m_worldPosition{ pos }
	, m_localPosition{}
	, m_parent{}
	, m_children{}
{
}





