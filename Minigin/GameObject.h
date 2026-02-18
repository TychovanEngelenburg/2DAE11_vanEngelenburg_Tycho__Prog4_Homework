#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Components/Component.h"
#include "Types/Transform.h"

#include <string>
#include <string_view>
#include <unordered_map>
#include <memory>
#include <typeindex>
#include <concepts>
#include <glm/fwd.hpp>
#include <algorithm>
#include <stdexcept>

namespace dae
{
	class Texture2D;
	class GameObject final
	{
	public:
		Transform const& GetTransform() const noexcept;
		std::string_view GetName() const noexcept;
		bool IsDestroyed() const noexcept;

		void SetPosition(float x, float y);
		void Destroy();
		//void SetName(std::string_view name);

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args);

		template<typename T>
		bool HasComponent() const;

		template<typename T>
		T* GetComponent() const;

		template<typename T>
		void RemoveComponent();

		void Start();
		void Update();
		void FixedUpdate();
		void Render() const;
		void LateUpdate();
		void End();

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
	inline T& GameObject::AddComponent(Args&&... args)
	{
		static_assert(std::derived_from<T, Component>, "Attempted to add a non-component to component list!");

		if (HasComponent<T>())
		{
			throw std::runtime_error("Attempted to add duplicate entry to component list!");
		}

		auto component{ std::make_unique<T>(std::forward<Args>(args)...) };
		auto& returnRef{ *component };
		component->m_gameObject = this;
		m_components.emplace(std::type_index(typeid(T)), std::move(component));
		return returnRef;
	}

	template<typename T>
	inline bool GameObject::HasComponent() const
	{
		return m_components.contains(std::type_index(typeid(T)));
	}

	template<typename T>
	inline T* GameObject::GetComponent() const
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
