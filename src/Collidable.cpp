/**
 * @file Collidable.cpp
 *
 * @author Tag Ashby
 * @date 7/2012
 * 
 */

#include "Collidable.h"

namespace TGA
{
   BoundingBox Collidable::getBounds()
   {
      return bounds;
   }

   Collidable::Collidable( BoundingBox b )
      : bounds(b)
   {
   }
}


