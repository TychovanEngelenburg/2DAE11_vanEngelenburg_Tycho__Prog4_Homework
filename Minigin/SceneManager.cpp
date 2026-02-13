#include "SceneManager.h"
#include "Scene.h"

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
	for (const auto& scene : m_scenes)
	{
		scene->Render();
	}
}

dae::Scene& dae::SceneManager::CreateScene()
{
	m_scenes.emplace_back(new Scene());
	return *m_scenes.back();
}
