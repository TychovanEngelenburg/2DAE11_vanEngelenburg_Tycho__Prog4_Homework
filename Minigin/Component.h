#ifndef COMPONENT_H
#define COMPONENT_H

namespace dae
{
	class GameObject;
	class Component
	{
	public:
		void SetOwner(GameObject* gameObject);

		virtual void FixedUpdate(double fixedDeltaTime);
		virtual void Update(double deltaTime);
		virtual void Render() const;

		Component();

	protected:
		GameObject* m_gameObject;
	};
}
#endif // !COMPONENT_H
