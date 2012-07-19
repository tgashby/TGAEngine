/**
 * @file BoundingBox.cpp
 *
 * @author Tag Ashby
 * @date 7/2012
 * 
 */

#include "BoundingBox.h"

namespace TGA
{
   BoundingBox::BoundingBox( int x, int y, int width, int height )
   {
      bounds.x = x;
      bounds.y = y;
      bounds.w = width;
      bounds.h = height;
   }

   int BoundingBox::getWidth()
   {
      return bounds.w;
   }

   int BoundingBox::getHeight()
   {
      return bounds.h;
   }

   int BoundingBox::getX()
   {
      return bounds.x;
   }

   int BoundingBox::getY()
   {
      return bounds.y;
   }

   void BoundingBox::setX( int newX )
   {
      bounds.x = newX;
   }

   void BoundingBox::setY( int newY )
   {
      bounds.y = newY;
   }

}
