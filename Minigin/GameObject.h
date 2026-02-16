#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <unordered_map>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <optional>

#include <concepts>
#include <type_traits>

#include "Transform.h"
#include "Component.h"
#include <cassert>
#include <glm/fwd.hpp>

namespace dae
{
	class Texture2D;
	class GameObject final
	{
	public:

		Transform const& GetTransform();

		void SetPosition(float x, float y);
		//void SetName(std::string_view name);

		template<typename T>
		void AddComponent(std::unique_ptr<T>);

		template<typename T>
		bool HasComponent();

		template<typename T>
		auto GetComponent() -> std::optional<T>;

		std::string_view GetName();

		virtual void Update(double deltaTime);
		virtual void FixedUpdate(double fixedDeltaTime);
		virtual void Render() const;

		GameObject(std::string_view name, glm::vec3 pos = {0.f, 0.f, 0.f});

	private:
		Transform m_transform;
		std::string m_name;
		std::unordered_map<std::type_index, std::unique_ptr<Component> > m_components;
	};


	template<typename T>
	inline void GameObject::AddComponent(std::unique_ptr<T> component)
	{
		static_assert(std::derived_from<T, Component>, "Attempted to add a non-component to component list!");


		assert(!HasComponent<T>());

		component->SetOwner(this);
		m_components.emplace(std::type_index(typeid(T)), std::move(component));
	}

	template<typename T>
	inline bool GameObject::HasComponent()
	{
		return m_components.contains(std::type_index(typeid(T)));
	}

	template<typename T>
	inline auto GameObject::GetComponent() -> std::optional<T>
	{
		auto it = m_components.find(std::type_index(typeid(T)));
		if (it != m_components.end)
		{
			return;
		}

		// Opted to go for static_cast instead of dynamic because type is known and verified existent.
		return static_cast<T*>(it->second.get());
	}
}
#endif // !GAMEOBJECT_H