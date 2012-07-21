/**
 * @file Timer.cpp
 *
 * @author Tag Ashby
 * @date 7/2012
 * 
 */
#include "Timer.h"

namespace TGA
{
   Uint32 Timer::getTicks()
   {
      return SDL_GetTicks();
   }
}
