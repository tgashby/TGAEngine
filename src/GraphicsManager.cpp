#include "GraphicsManager.h"

namespace TGA
{
	GraphicsManager::GraphicsManager()
	{
		// Set loaded to false
		isLoaded = false;
	}
	
	GraphicsManager::~GraphicsManager()
	{
		// Call shutDown()
		shutDown();
	}

	void GraphicsManager::init(int screenWidth /* = 1024 */, int screenHeight /* = 512 */, 
      std::string winTitle /* = "" */, int screenX /* = SDL_WINDOWPOS_CENTERED */, 
      int screenY /* = SDL_WINDOWPOS_CENTERED */)
	{
		this->winTitle = winTitle;
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;

		SDL_Init(SDL_INIT_VIDEO);
      
      // load support for the JPG and PNG image formats
      int flags = IMG_INIT_JPG|IMG_INIT_PNG;
      int initted= IMG_Init(flags);
      if((initted & flags) != flags) {
         printf("IMG_Init: Failed to init required jpg and png support!\n");
         printf("IMG_Init: %s\n", IMG_GetError());
         // handle error
      }

		// Set the SDL GL Attributes
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// Create the window
		window = SDL_CreateWindow(winTitle.c_str(), screenX, screenY, 
			screenWidth, screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		// Create the GL context
		glCtx = SDL_GL_CreateContext(window);

		// InitGL
		initGL();

		isLoaded = true;
	}

	void GraphicsManager::shutDown()
	{
		// IF it was ever loaded
		if(isLoaded)
		{
			// Delete the gl context
			SDL_GL_DeleteContext(glCtx);

			// Delete the window
			SDL_DestroyWindow(window);
		}
	}

	void GraphicsManager::swapBuffers()
	{
		// IF it was loaded
		if(isLoaded)
		{
			// Call SDL_GL_SwapWindow(window)
			SDL_GL_SwapWindow(window);
		}
	}

	void GraphicsManager::resizeWindow(int screenWidth, int screenHeight)
	{
		// IF it was loaded
		if(isLoaded)
		{
			// Destory the GL context
			SDL_GL_DeleteContext(glCtx);

			// Destroy the previous window
			SDL_DestroyWindow(window);

			// Create a new window (window = SDL_CreateWindow.....)
			window = SDL_CreateWindow(winTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
				screenWidth, screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

			// Create a new GL context
			glCtx = SDL_GL_CreateContext(window);

			// Call initGL
			initGL();

			// Reload all textures
			Singleton<TextureManager>::GetSingletonPtr()->resetTextures();
		}
		// ENDIF
	}

	void GraphicsManager::toggleFullScreen()
	{
      if (isLoaded)
      {
         isFullScreen = isFullScreen == SDL_TRUE ? SDL_FALSE : SDL_FALSE;

         //Call SDL_SetWindowFullscreen(window, isFullScreen)
         SDL_SetWindowFullscreen(window, isFullScreen);
      }
	}

	void GraphicsManager::initGL()
	{
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();

		glOrtho(0.0, screenWidth, screenHeight, 0.0, -1, 1);

		glDisable(GL_DEPTH_TEST);

		glClearColor(1, 1, 1, 1);

		glShadeModel(GL_SMOOTH);

		glMatrixMode(GL_MODELVIEW);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glLoadIdentity();
	}
}
