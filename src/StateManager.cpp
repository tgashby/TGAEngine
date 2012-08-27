/**
 * @file StateManager.cpp
 *
 * @author Tag Ashby
 * @date 8/2012
 * 
 */
#include "StateManager.h"
#include <iostream>


namespace TGA
{
   void StateManager::PushState( State* state )
   {
      states.push_back(state);
   }
   
   void StateManager::UpdateCurrentState()
   {
      if (!states.front()->update())
      {
         PopState();
      }
   }
   
   void StateManager::DrawCurrentState()
   {
      states.front()->draw();
   }
   
   void StateManager::PopState()
   {
      if (!states.empty())
      {
         states.pop_back();
      }
      else
      {
         std::cout << "ERROR: Last state trying to be popped.\n";
      }
   }
}
