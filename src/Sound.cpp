/**
 * @file Sound.cpp
 *
 * @author Tag Ashby
 * @date 8/2012
 * 
 */

#include "Sound.h"

namespace TGA
{
   Sound::Sound( std::string fileName )
   {
      sound = Mix_LoadWAV(fileName.c_str());
      if(!sound) 
      {
         std::cout << "Sound Load Error: " << Mix_GetError() << "\n";
      }
      soundChannel = -1;
   }

   void Sound::play( int loops )
   {
      soundChannel = Mix_PlayChannel(-1, sound, loops);
   }

   void Sound::pause()
   {
      if (soundChannel != -1)
      {
         Mix_Pause(soundChannel);
      }
   }

}