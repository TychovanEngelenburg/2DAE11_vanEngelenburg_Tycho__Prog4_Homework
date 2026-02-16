#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <vld.h>
#if _DEBUG && __has_include(<vld.h>)
#endif

#include "Minigin.h"
#include "SceneManager.h"

#include "TextComponent.h"
#include "Scene.h"
#include "Sprite.h"
#include <glm/fwd.hpp>
#include <filesystem>
namespace fs = std::filesystem;

static void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene();

	auto object = std::make_unique<dae::GameObject>("Background");
	auto sprite = std::make_unique<dae::Sprite>("background.png");
	object->AddComponent(std::move(sprite));
	scene.Add(std::move(object));

	object = std::make_unique<dae::GameObject>( "Logo", glm::vec3(358.f, 180.f, 0.f));
	sprite = std::make_unique<dae::Sprite>("logo.png");
	object->AddComponent(std::move(sprite));
	scene.Add(std::move(object));

	object = std::make_unique<dae::GameObject>("Header_Text",  glm::vec3(292.f, 20.f, 0.f));
	auto textComp = std::make_unique<dae::TextComponent>("Programming 4 Assignment", "Lingua.otf", 36);
	textComp->SetColor({ 255, 255, 0, 255 });
	object->AddComponent(std::move(textComp));
	scene.Add(std::move(object));
}


int main(int, char*[]) {
#if __EMSCRIPTEN__
	fs::path data_location = "";
#else
	fs::path data_location = "./Data/";
	if(!fs::exists(data_location))
		data_location = "../Data/";
#endif
	dae::Minigin engine(data_location);
	engine.Run(load);
    return 0;
}
