#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>
#include "GameObject.h"
#include <string_view>

namespace dae
{
	class Scene final
	{
	public:
		GameObject* GetObj(std::string_view objName);

		// TODO: Look if it would be better to implement similar to addcomponent.
		void Add(std::unique_ptr<GameObject> object);
		void Remove(GameObject const& object);

		void Start();
		void FixedUpdate();
		void Update();
		void Render() const;
		void LateUpdate();
		void End();

		~Scene();
		Scene(Scene const& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(Scene const& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private:
		friend class SceneManager;
		explicit Scene() = default;

		std::vector<std::unique_ptr<GameObject>> m_objects;
		std::vector<GameObject*> m_deletionList;
	};
}
#endif // !SCENE_H
