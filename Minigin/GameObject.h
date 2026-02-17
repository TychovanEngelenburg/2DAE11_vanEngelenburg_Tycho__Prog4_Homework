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
#include <algorithm>
#include <stdexcept>

namespace dae
{
	class Texture2D;
	class GameObject final
	{
	public:

		Transform const& GetTransform();
		std::string_view GetName();
		bool IsDestroyed();

		void SetPosition(float x, float y);
		void Destroy();
		//void SetName(std::string_view name);

		template<typename T, typename... Args>
		void AddComponent(Args&&... args);

		template<typename T>
		bool HasComponent();

		template<typename T>
		auto GetComponent() -> std::optional<T*>;

		template<typename T>
		void RemoveComponent();


		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render() const;
		virtual void LateUpdate();

		GameObject(std::string_view name, glm::vec3 pos = {0.f, 0.f, 0.f});
		~GameObject();

		// TODO: Implement Copy and Move constructors
		GameObject(GameObject const& other) = delete;
		GameObject(GameObject&& other) = delete;

		GameObject& operator=(GameObject const& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform;
		std::string m_name;
		bool m_active;
		bool m_destroyed;
		std::unordered_map<std::type_index, std::unique_ptr<Component> > m_components;
	};


	template<typename T, typename... Args>
	inline void GameObject::AddComponent(Args&&... args)
	{
		static_assert(std::derived_from<T, Component>, "Attempted to add a non-component to component list!");

		if (HasComponent<T>())
		{
			throw std::runtime_error("Attempted to add duplicate entry to component list!");
		}

		auto component{ std::make_unique<T>(std::forward<Args>(args)...) };
		
		component->m_gameObject = this;
		m_components.emplace(std::type_index(typeid(T)), std::move(component));
	}

	template<typename T>
	inline bool GameObject::HasComponent()
	{
		return m_components.contains(std::type_index(typeid(T)));
	}

	template<typename T>
	inline auto GameObject::GetComponent() -> std::optional<T*>
	{
		auto it = m_components.find(std::type_index(typeid(T)));
		if (it == m_components.end())
		{
			return {};
		}

		// Opted to go for static_cast instead of dynamic because type is known and verified existent.
		return static_cast<T*>(it->second.get());
	}

	template<typename T>
	inline void GameObject::RemoveComponent()
	{
		m_components.erase(std::type_index(typeid(T)));
	}
}
#endif // !GAMEOBJECT_H