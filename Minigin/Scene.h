#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <string>
#include <vector>
#include "GameObject.h"

namespace dae
{
	class Scene final
	{
	public:
		void Add(std::unique_ptr<GameObject> object);
		void Remove(GameObject const& object);
		void RemoveAll();

		void Start();
		void FixedUpdate();
		void Update();
		void Render() const;
		void LateUpdate();

		~Scene();
		Scene(Scene const& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(Scene const& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private:
		friend class SceneManager;
		explicit Scene() = default;

		std::vector<std::unique_ptr<GameObject>> m_objects{};
	};
}
#endif // !SCENE_H