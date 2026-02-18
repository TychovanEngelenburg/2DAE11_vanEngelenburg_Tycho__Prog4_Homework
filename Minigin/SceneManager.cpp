#include "SceneManager.h"

// .h includes
#include "Scene.h"

#include <memory>
#include <vector>

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

void dae::SceneManager::Render() const
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

void dae::SceneManager::End()
{
	for (auto const& scene : m_scenes)
	{
		scene->End();
	}
}
#pragma endregion Game_Loop

dae::Scene& dae::SceneManager::CreateScene()
{
	// TODO: Look into why std::make_unique<Scene>() doesn't work here.
	m_scenes.emplace_back(new Scene());
	return *m_scenes.back();
}
