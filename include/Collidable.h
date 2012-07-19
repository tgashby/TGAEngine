/**
 * @file Collidable.h
 *
 * @author Tag Ashby
 * @date 7/2012
 * 
 */
#pragma once

#include "BoundingBox.h"

namespace TGA
{
   /**
    * @class Collidable
    *
    * @brief "Interface" to attach to anything that can be collided with.
    *
    */
   class Collidable 
   {
   public:
      /**
      * handleCollision
      *
      * Updates the collidable entity based on what it collided with.
      * @param Collidable collidedWith - the collidable entity collided with
      */
      virtual void handleCollision (Collidable& collidedWith) = 0;

      
      /**
      * getType
      *
      * Returns the type of this collidable.
      * @warning up to you to keep your IDs unique.
      * @return int - the unique specifier for this Collidable.
      */
      virtual int getType() = 0;

      /**
      * getBounds
      *
      * Returns the boundaries of this collidable.
      * @return TGA::BoundingBox - the bounds of the collidable
      */
      BoundingBox getBounds ();

   protected:
      BoundingBox bounds;
      int id;
   };
}
