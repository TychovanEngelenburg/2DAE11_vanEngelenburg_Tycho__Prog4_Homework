#include <SDL3/SDL_main.h>

#if _DEBUG && __has_include(<vld.h>)
#include <vld.h>
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "Scene.h"

#include "GameObject.h"
#include "Components/TextComponent.h"
#include "Components/FPS_Display.h"
#include "Components/Sprite.h"
#include "Components/Orbiter.h"

#include <glm/fwd.hpp>
#include <filesystem>
#include <utility>
#include <memory>
#include <SDL3/SDL_main_impl.h>

// TODO: When engine becomes a library this should be handled externally.
static void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene();

	auto object = std::make_unique<dae::GameObject>("Background");
	{
		object->AddComponent<dae::Sprite>("background.png");
		scene.Add(std::move(object));
	}

	object = std::make_unique<dae::GameObject>("OrbitParent", glm::vec3(292.f, 20.f, 0.f));
	{
		//object->GetTransform().Rotate(45);
		scene.Add(std::move(object));
	}

	object = std::make_unique<dae::GameObject>("Logo", glm::vec3(358.f, 180.f, 0.f));
	{
		object->AddComponent<dae::Sprite>("logo.png");
		object->AddComponent<dae::Orbiter>(50.f, -1.f);
		object->GetTransform().SetParent(&scene.GetObjectByName("OrbitParent")->GetTransform());

		scene.Add(std::move(object));
	}

	object = std::make_unique<dae::GameObject>("Header_Text", glm::vec3(292.f, 20.f, 0.f));
	{
		auto& textComp = object->AddComponent<dae::TextComponent>("Programming 4 Assignment", "Lingua.otf", 36);
		textComp.SetColor({ 255, 255, 0, 255 });

		object->AddComponent<dae::Orbiter>(30.f, 5.f);
		object->GetTransform().SetParent(&scene.GetObjectByName("Logo")->GetTransform());

		scene.Add(std::move(object));
	}

	object = std::make_unique<dae::GameObject>("FPS_Counter");
	{
		auto& textComp = object->AddComponent<dae::TextComponent>("00", "Lingua.otf", 36);
		textComp.SetColor({ 255, 255, 0, 255 });
		object->AddComponent<dae::FPS_Display>();
		scene.Add(std::move(object));
	}

}


int main(int, char* [])
{
#if __EMSCRIPTEN__
	std::filesystem::path data_location = "";
#else
	std::filesystem::path data_location = "./Data/";
	if (!std::filesystem::exists(data_location))
		data_location = "../Data/";
#endif
	dae::Minigin engine(data_location);
	engine.Run(load);
	return 0;
}
