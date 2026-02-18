#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/detail/type_vec3.hpp>
#include <glm/fwd.hpp>

namespace dae
{
	class Transform final
	{
	public:
		const glm::vec3& GetPosition() const noexcept;

		void SetPosition(float x, float y, float z = 0);
		void SetPosition( glm::vec3 const& position);
		void Translate(float x, float y, float z = 0);
		void Translate(glm::vec3 const& difference);

		Transform(glm::vec3 const& pos = {0.f, 0.f, 0.f});

	private:
		glm::vec3 m_position;
	};
}
#endif // !TRANSFORM_H
