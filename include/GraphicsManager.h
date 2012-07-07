#pragma once
#include "ProjIncludes.h"
#include "TextureManager.h"

namespace TGA
{
	class GraphicsManager
	{
	public:
		GraphicsManager();
		~GraphicsManager();

		void init(int screenWidth = 1024, int screenHeight = 512, 
		 std::string winTitle = "Sandstorms", int screenX = SDL_WINDOWPOS_CENTERED, int screenY = SDL_WINDOWPOS_CENTERED);

		void shutDown();

		void swapBuffers();

		void resizeWindow(int screenWidth, int screenHeight);
		void toggleFullScreen();

	private:
		void initGL();

		int screenWidth;
		int screenHeight;

		bool isLoaded;
		SDL_bool isFullScreen;

		std::string winTitle;
		SDL_Window* window;
		SDL_GLContext glCtx;
	};
}


