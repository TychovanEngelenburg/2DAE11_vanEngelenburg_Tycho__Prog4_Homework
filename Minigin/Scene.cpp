#include "Scene.h"

#include "GameObject.h"
#include <algorithm>
#include <cassert>
#include <memory>
#include <string_view>
#include <utility>
#include <vector>


dae::GameObject* dae::Scene::GetObj(std::string_view objName)
{
	return std::find_if(m_objects.begin(), m_objects.end(), [&objName](auto const& ptr)
		{
			return ptr->GetName() == objName;
		})->get();
}

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

#pragma region Game_Loop
void dae::Scene::Start()
{
	for (auto& object : m_objects)
	{
		if (object->IsActive())
		{
			object->Start();
		}
	}
}

void dae::Scene::FixedUpdate()
{
	for (auto& object : m_objects)
	{
		if (object->IsActive())
		{
			object->FixedUpdate();
		}
	}
}

void dae::Scene::Update()
{
	for (auto& object : m_objects)
	{
		if (object->IsActive())
		{
			object->Update();
		}
	}
}

void dae::Scene::Render() const
{
	for (auto const& object : m_objects)
	{
		if (object->IsActive())
		{
			object->Render();
		}
	}
}

void dae::Scene::LateUpdate()
{

	for (auto const& object : m_objects)
	{
		if (object->IsActive())
		{
			object->LateUpdate();
		}


		std::erase_if(m_objects, [](std::unique_ptr<GameObject> const& object)
			{
				return object->IsDestroyed();
			});
	}

	for (auto const object : m_deletionList)
	{
		this->Remove(*object);
	}
}

void dae::Scene::End()
{
	for (auto const& object : m_objects)
	{
		if (object->IsActive())
		{
			object->End();
		}

	}
}
#pragma endregion Game_Loop

dae::Scene::~Scene()
{
	m_objects.clear();
}
