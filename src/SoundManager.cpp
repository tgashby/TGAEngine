/**
 * @file SoundManager.cpp
 *
 * @author Tag Ashby
 * @date 8/2012
 * 
 */

#include "SoundManager.h"

namespace TGA
{
   SoundManager::SoundManager()
   {
      SDL_Init(SDL_INIT_AUDIO);

      // open 44.1KHz, signed 16bit, system byte order,
      //      stereo audio, using 1024 byte chunks
      if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1) {
         printf("Mix_OpenAudio: %s\n", Mix_GetError());
      }

      // load support for the OGG and MOD sample/music formats
      int flags = MIX_INIT_OGG | MIX_INIT_MOD;
      int initted = Mix_Init(flags);
      if ((initted & flags) != flags) {
         printf("Mix_Init: Failed to init required ogg and mod support!\n");
         printf("Mix_Init: %s\n", Mix_GetError());
      }
   }

   void SoundManager::addSound( Sound* sound, std::string soundName )
   {
      sounds.insert(sounds.begin(), std::pair<std::string, Sound*>(soundName, sound));
   }

   void SoundManager::removeSound( std::string soundName )
   {
      sounds.erase(soundName);
   }

   void SoundManager::playSound( std::string soundName, int loops )
   {
      sounds[soundName]->play(loops);
   }

   void SoundManager::pauseSound( std::string soundName )
   {
      sounds[soundName]->pause();
   }

   void SoundManager::removeAllSounds()
   {
      for (std::map<std::string, Sound*>::iterator i = sounds.begin(); i != sounds.end(); i++)
      {
         delete (*i).second;
      }

      sounds.clear();
   }

   void SoundManager::addMusic( Music* musicTrack, std::string musicName )
   {
      music.insert(music.begin(), std::pair<std::string, Music*>(musicName, musicTrack));
   }

   void SoundManager::removeMusic( std::string musicName )
   {
      music.erase(musicName);
   }

   void SoundManager::playMusic( std::string musicName, int loops )
   {
      music[musicName]->play(loops);
   }

   void SoundManager::pauseMusic( std::string musicName )
   {
      music[musicName]->pause();
   }

   void SoundManager::removeAllMusic()
   {
      for (std::map<std::string, Music*>::iterator i = music.begin(); i != music.end(); i++)
      {
         delete (*i).second;
      }

      music.clear();
   }

   void SoundManager::pauseAllSounds()
   {
      for (std::map<std::string, Sound*>::iterator i = sounds.begin(); i != sounds.end(); i++)
      {
         (*i).second->pause();
      }
   }
}