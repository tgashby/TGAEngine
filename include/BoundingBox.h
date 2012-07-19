/**
 * @file BoundingBox.h
 *
 * @author Tag Ashby
 * @date 7/2012
 * 
 */
#pragma once

#include <SDL.h>

namespace TGA
{
   /**
    * @class BoundingBox
    *
    * @brief Represents the boundaries of an entity.
    *
    * The width and height of a bounding box should not change,
    * and that's why there's no methods for setting those values.
    */
   class BoundingBox 
   {

   friend class Collision;

   public:
      /**
      * BoundingBox
      *
      * Create a bounding box with the given dimensions.
      * @param int x - the x position of the box
      * @param int y - the y position of the box
      * @param int width - the width of the box
      * @param int height - the height of the box 
      */
      BoundingBox(int x, int y, int width, int height);

      /**
      * getWidth
      *
      * Get the box's width.
      * @return int - the box width
      */
      int getWidth ();

      /**
      * getHeight
      *
      * Gets the box's height.
      * @return int - the box height
      */
      int getHeight ();

      /**
      * getX
      *
      * Gets the box's x value.
      * @return int - the x value
      */
      int getX ();

      /**
      * getY
      *
      * Gets the box's y value.
      * @return int - the y value
      */
      int getY ();

      /**
      * setX
      *
      * Set the box's x position.
      * @param int newX - the new x position
      */
      void setX (int newX);

      /**
      * setY
      *
      * Sets the box's y position.
      * @param int newY - the new y position
      */
      void setY (int newY);

   private:
      SDL_Rect bounds;
   };
}