#include <algorithm>
#include "Scene.h"

using namespace dae;

void Scene::Add(std::unique_ptr<GameObject> object)
{
	assert(object != nullptr && "Cannot add a null GameObject to the scene.");
	m_objects.emplace_back(std::move(object));
}

void Scene::Remove(GameObject const& object)
{
	m_objects.erase(
		std::remove_if(
			m_objects.begin(),
			m_objects.end(),
			[&object](auto const& ptr) { return ptr.get() == &object; }
		),
		m_objects.end()
	);
}

void Scene::RemoveAll()
{
	m_objects.clear();
}

#pragma region Game_Loop
void dae::Scene::Start()
{
	for (auto& object : m_objects)
	{
		object->Start();
	}
}

void Scene::FixedUpdate()
{
	for (auto& object : m_objects)
	{
		object->FixedUpdate();
	}
}

void Scene::Update()
{
	for(auto& object : m_objects)
	{
		object->Update();
	}
}

void Scene::Render() const
{
	for (auto const& object : m_objects)
	{
		object->Render();
	}
}

void dae::Scene::LateUpdate()
{
	for (auto objectIt{m_objects.begin()}; objectIt != m_objects.end();)
	{
		if (objectIt->get()->IsDestroyed())
		{
			m_objects.erase(objectIt);
		}
		else
		{
			objectIt->get()->LateUpdate();
			++objectIt;
		}
	}
}
#pragma endregion Game_Loop

dae::Scene::~Scene()
{
	m_objects.clear();
}



