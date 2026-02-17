#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#if _DEBUG && __has_include(<vld.h>)
#include <vld.h>
#endif

#include "Minigin.h"
#include "SceneManager.h"

#include "Components/TextComponent.h"
#include "Components/FPS_Display.h"
#include <glm/fwd.hpp>
#include "Scene.h"
#include "Components/Sprite.h"
#include <filesystem>
#include <utility>
namespace fs = std::filesystem;

static void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene();
	scene;

	auto object = std::make_unique<dae::GameObject>("Background");
	object->AddComponent<dae::Sprite>("background.png");
	scene.Add(std::move(object));

	object = std::make_unique<dae::GameObject>( "Logo", glm::vec3(358.f, 180.f, 0.f));
	object->AddComponent<dae::Sprite>("logo.png");
	scene.Add(std::move(object));

	object = std::make_unique<dae::GameObject>("Header_Text",  glm::vec3(292.f, 20.f, 0.f));
	/*auto textComp = */ object->AddComponent<dae::TextComponent>("Programming 4 Assignment", "Lingua.otf", 36);
	//textComp->SetColor({ 255, 255, 0, 255 });
	scene.Add(std::move(object));

	object = std::make_unique<dae::GameObject>("FPS_Counter");
	//textComp->SetColor({ 255, 255, 0, 255 });
	object->AddComponent<dae::TextComponent>("00", "Lingua.otf", 36);
	object->AddComponent<dae::FPS_Display>();
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
