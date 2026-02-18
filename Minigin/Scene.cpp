#include "Scene.h"

#include <algorithm>
#include <cassert>

// .h includes
#include <memory>
#include <vector>
#include "GameObject.h"


void dae::Scene::Add(std::unique_ptr<GameObject> object)
{
	assert(object != nullptr && "Cannot add a null GameObject to the scene.");
	m_objects.emplace_back(std::move(object));
}

void dae::Scene::Remove(GameObject const& object)
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

void dae::Scene::RemoveAll()
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

void dae::Scene::FixedUpdate()
{
	for (auto& object : m_objects)
	{
		object->FixedUpdate();
	}
}

void dae::Scene::Update()
{
	for(auto& object : m_objects)
	{
		object->Update();
	}
}

void dae::Scene::Render() const
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

void dae::Scene::End()
{
	for (auto const& object : m_objects)
	{
		object->End();
	}
}
#pragma endregion Game_Loop

dae::Scene::~Scene()
{
	m_objects.clear();
}
