#include "SceneManager.h"
#include "Scene.h"

#pragma region Game_Loop
void dae::SceneManager::FixedUpdate(double fixedDeltaTime)
{
	for (auto& scene : m_scenes)
	{
		scene->FixedUpdate(fixedDeltaTime);
	}
}

void dae::SceneManager::Update(double deltaTime)
{
	for(auto& scene : m_scenes)
	{
		scene->Update(deltaTime);
	}
}

void dae::SceneManager::Render()
{
	for (auto const& scene : m_scenes)
	{
		scene->Render();
	}
}
#pragma endregion Game_Loop

dae::Scene& dae::SceneManager::CreateScene()
{
	m_scenes.emplace_back(new Scene());
	return *m_scenes.back();
}
