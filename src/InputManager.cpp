#include "InputManager.h"

namespace TGA
{
	InputManager::InputManager() {}

	InputManager::~InputManager() {}

	bool InputManager::keyDown(Key key)
	{
		return keystates[key];
	}

	bool InputManager::update()
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_KEYDOWN:
				keystates[event.key.keysym.sym] = true;
				break;

			case SDL_KEYUP:
				keystates[event.key.keysym.sym] = false;
				break;

			case SDL_MOUSEBUTTONUP:
            mouseButtonDown = false;
				break;
               
         case SDL_MOUSEBUTTONDOWN:
            mouseButtonDown = true;
            break;

         case SDL_MOUSEMOTION:
            SDL_GetMouseState(&mouseX, &mouseY);
            break;

			case SDL_QUIT:
				return false;

         default:
            //std::cout << "Unknown event type: " << event.type;
            break;
			}
		}

		return true;
	}

	Vector2D InputManager::getMouseCoords()
	{
		return Vector2D(mouseX, mouseY);
	}
   
   bool InputManager::mouseDown()
   {
      return mouseButtonDown;
   }
};