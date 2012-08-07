#include "Engine.h"

namespace TGA
{
	Engine::Engine()
	{
      initalize();
	}


	Engine::~Engine()
	{
      shutdown();
	}

	void Engine::initalize()
	{
		Animations = Singleton<AnimationManager>::GetSingletonPtr();
		Textures = Singleton<TextureManager>::GetSingletonPtr();
		GameCamera = Singleton<Camera>::GetSingletonPtr();
		Graphics = Singleton<GraphicsManager>::GetSingletonPtr();
		Input = Singleton<InputManager>::GetSingletonPtr();
      Sounds = Singleton<SoundManager>::GetSingletonPtr();
	}

	void Engine::shutdown()
	{
      delete Animations;
      delete Textures;
      delete GameCamera;
      delete Graphics;
      delete Input;
      delete Sounds;
	}

}
