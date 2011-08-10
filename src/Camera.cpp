#include "Camera.h"

namespace TGA
{
	Camera::Camera(GLfloat xPos, GLfloat yPos)
	{
		// Set this xPos to xPos
		// Set this yPos to yPos
	}


	Camera::~Camera(void)
	{
	}

	void Camera::moveOver(GLfloat xVal, GLfloat yVal)
	{
		// Update camera xPos (+=)

		// Update camera yPos (-=)
	}

	void Camera::setPosition(GLfloat xPos, GLfloat yPos)
	{
		// Set xPos

		// Set yPos
	}

	GLfloat Camera::getX()
	{
		// RETURN xPos
		return xPos;
	}

	GLfloat Camera::getY()
	{
		// RETURN yPos
		return yPos;
	}
}

