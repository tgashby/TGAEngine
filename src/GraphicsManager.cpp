#include "GraphicsManager.h"

namespace TGA
{
	GraphicsManager::GraphicsManager()
	{
		// Set loaded to false
	}
	
	
	GraphicsManager::~GraphicsManager()
	{
		// Call shutDown()
	}

	void GraphicsManager::init(int screenWidth /*= 1024*/, int screenHeight /*= 512*/, 
	 std::string winTitle /*= "Sandstorms"*/)
	{
		// Call SDL_INIT(SDL_EVERYTHING)

		// Set the SDL GL Attributes
		/*SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);*/

		// Create the window

		// Create the GL context

		// InitGL
	}

	void GraphicsManager::shutDown()
	{
		// IF it was ever loaded
			// Delete the window
			// Delete the gl context

		// SDL_Quit()
	}

	void GraphicsManager::swapBuffers()
	{
		// IF it was loaded
			// Call SDL_GL_SwapWindow(window)
	}

	void GraphicsManager::resizeWindow(int screenWidth, int screenHeight)
	{
		// IF it was loaded
			// Destory the GL context
			// Destroy the previous window

			// Create a new window (window = SDL_CreateWindow.....)
			// Create a new GL context

			// Call initGL

			// Reload all textures
		// ENDIF
	}

	void GraphicsManager::toggleFullScreen()
	{
		//Call SDL_SetWindowFullscreen(window, isFullScreen)

		// IF fullscreen

			// Hide the cursor (SDL_ShowCursor(SDL_DISABLE))

		// Else

			// Unhide the cursor
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
