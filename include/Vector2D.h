#pragma once

namespace TGA
{
	class Vector2D
	{
	public:
		Vector2D(double x, double y);
		~Vector2D(void);

		Vector2D operator+(Vector2D);
		Vector2D operator-(Vector2D);
		Vector2D scalarProduct(int);
		Vector2D normalize();

		double dotProduct(Vector2D);
		double length();
		double distanceFrom(Vector2D);

	private:
		double x, y;
	};
}
