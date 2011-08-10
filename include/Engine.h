#pragma once

namespace TGA
{
	class Engine
	{
	public:
		Engine(void);
		~Engine(void);

		void Initalize();
		void Shutdown();

		SoundManager* Sounds;
		AnimationManager* Animations;
		TextureManager* Textures;
		FontManager* Fonts;
		Camera* GameCamera;
		GraphicsManager* Graphics;
		InputManager* Input;
	};
}

