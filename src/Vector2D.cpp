#include "Vector2D.h"
#include <math.h>

namespace TGA
{
	Vector2D::Vector2D(double xComp, double yComp)
		: x(xComp), y(yComp) {}


	Vector2D::~Vector2D() {}

   Vector2D& Vector2D::operator+=(Vector2D rhs)
   {
      this->x = this->x + rhs.x;
      this->y = this->y + rhs.y;

      return *this;
   }

	Vector2D Vector2D::operator+(Vector2D vec2)
	{
      Vector2D result = *this;

      result += vec2;

      return result;
	}

   Vector2D& Vector2D::operator-=(Vector2D rhs)
   {
      this->x = this->x - rhs.x;
      this->y = this->y - rhs.y;

      return *this;
   }

	Vector2D Vector2D::operator-(Vector2D vec2)
	{
      Vector2D result = *this;

      result -= vec2;

		return result;
	}

	Vector2D Vector2D::operator*(double mult)
	{
		return Vector2D(this->x * mult, this->y * mult);
	}

	Vector2D Vector2D::normalize()
	{		
		return Vector2D(this->x / length(), this->y / length());
	}

	double Vector2D::dotProduct(Vector2D vec2)
	{
		return this->x * vec2.x + this->y * vec2.y;
	}

	double Vector2D::length()
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}

	double Vector2D::distanceFrom(Vector2D vec2)
	{
		return (*this - vec2).length();
	}

	double Vector2D::getX()
	{
		return x;
	}

	double Vector2D::getY()
	{
		return y;
	}

   void Vector2D::setX(double x)
   {
      this->x = x;
   }

   void Vector2D::setY(double y)
   {
      this->y = y;
   }

   std::ostream& operator<<(std::ostream& os, const Vector2D& v)
   {
      return os << "(" << v.x << ", " << v.y << ")\n";
   }
}

