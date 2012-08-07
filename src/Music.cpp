/**
 * @file Music.cpp
 *
 * @author Tag Ashby
 * @date 8/2012
 * 
 */

#include "Music.h"

namespace TGA
{
   Music::Music( std::string fileName )
   {
      music = Mix_LoadMUS(fileName.c_str());

      if (!music)
      {
         std::cout << "Music load error: " << Mix_GetError() << "\n";
      }
   }

   void Music::play( int loops )
   {
      Mix_PlayMusic(music, loops);
   }

   void Music::pause()
   {
      Mix_PauseMusic();
   }
}