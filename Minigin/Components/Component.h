#ifndef COMPONENT_H
#define COMPONENT_H

namespace dae
{
	class GameObject;
	class Component
	{
	public:
		virtual ~Component() = default;
		Component(Component const& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(Component const& other) = delete;
		Component& operator=(Component&& other) = delete;

	protected:
		friend class GameObject;

		GameObject* m_gameObject;
		bool m_active;

		virtual void Start();
		virtual void FixedUpdate();
		virtual void Update();
		virtual void Render() const;
		virtual void LateUpdate();
		virtual void End();
		Component();

	};
}
#endif // !COMPONENT_H
