#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/detail/type_vec3.hpp>
#include <glm/fwd.hpp>
#include <vector>

namespace dae
{
	class Transform final
	{
	public:
		glm::vec3 const& GetPosition();
		glm::vec3 const& GetLocalPosition();

		Transform* GetParent() const noexcept;
		int GetChildCount() const noexcept;
		Transform* GetChildAt() const noexcept;

		void SetParent(Transform* parent, bool keepWorldPos = false);

		//void SetPosition(float x, float y, float z = 0);
		void SetPosition( glm::vec3 const& pos);
		void SetLocalPosition( glm::vec3 const& pos);
		void SetPositionDirty();

		void UpdateWorldPos();
		void Translate(float x, float y, float z = 0);
		void Translate(glm::vec3 const& diff);

		Transform(glm::vec3 const& pos = {0.f, 0.f, 0.f});

	private:
		bool m_positionDirty;
		glm::vec3 m_worldPosition;
		glm::vec3 m_localPosition;

		Transform* m_parent;
		std::vector<Transform*> m_children;

		bool IsChildOf(Transform* obj);
		void AddChild(Transform* child);
		void RemoveChild(Transform* child);
	};
}
#endif // !TRANSFORM_H
