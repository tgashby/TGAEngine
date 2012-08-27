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
   Sound::Sound(std::string fileName)
   {
      sound = Mix_LoadWAV(fileName.c_str());
      if(!sound) 
      {
         std::cout << "Sound Load Error: " << Mix_GetError() << "\n";
      }
      soundChannel = -1;
   }

   void Sound::play(int loops)
   {
      if (soundChannel != -1)
      {
         if (Mix_Paused(soundChannel))
         {
            Mix_Resume(soundChannel);
         }
         else
         {
            soundChannel = Mix_PlayChannel(soundChannel, sound, loops);
         }
      }
      else
      {
         soundChannel = Mix_PlayChannel(-1, sound, loops);
      }
      
      if(soundChannel == -1)
      {
         printf("Mix_PlayChannel: %s\n",Mix_GetError());
         // may be critical error, or maybe just no channels were free.
         // you could allocated another channel in that case...
      }
   }

   void Sound::pause()
   {
      if (soundChannel != -1)
      {
         Mix_Pause(soundChannel);
      }
   }
}