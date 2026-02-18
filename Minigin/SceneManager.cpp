#include "SceneManager.h"
#include "Scene.h"
#include "ResourceManager.h"

#pragma region Game_Loop
void dae::SceneManager::Start()
{
	for (auto& scene : m_scenes)
	{
		scene->Start();
	}
}

void dae::SceneManager::FixedUpdate()
{
	for (auto& scene : m_scenes)
	{
		scene->FixedUpdate();
	}
}

void dae::SceneManager::Update()
{
	for(auto& scene : m_scenes)
	{
		scene->Update();
	}
}

void dae::SceneManager::Render()
{
	for (auto const& scene : m_scenes)
	{
		scene->Render();
	}
}

void dae::SceneManager::LateUpdate()
{
	for (auto const& scene : m_scenes)
	{
		scene->LateUpdate();
	}
}
#pragma endregion Game_Loop

dae::Scene& dae::SceneManager::CreateScene()
{
	m_scenes.emplace_back(new Scene());
	return *m_scenes.back();
}
