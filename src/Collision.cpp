/**
 * @file Collision.cpp
 *
 * @author Tag Ashby
 * @date 7/2012
 * 
 */

#include "Collision.h"

namespace TGA
{
   bool Collision::checkCollision(BoundingBox b1, BoundingBox b2)
   {
      if (SDL_HasIntersection(&b1.bounds, &b2.bounds))
      {
         return true;
      }
      return false;
   }

   void Collision::handleCollisions(Collidable& c1, Collidable& c2)
   {
      if (checkCollision(c1.getBounds(), c2.getBounds()))
      {
         c1.handleCollision(c2);
         c2.handleCollision(c1);
      }
   }

   void Collision::handleAllCollisions( Collidable& c1, std::vector<Collidable*> collection )
   {
      for (std::vector<Collidable*>::iterator i = collection.begin(); i < collection.end(); i++)
      {
         Collision::handleCollisions(c1, *(*i));
      }
   }

}
