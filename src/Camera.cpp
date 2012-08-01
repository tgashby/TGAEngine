#include "Camera.h"

namespace TGA
{
	Camera::Camera()
	{
      xPos = yPos = 0;
	}

	Camera::~Camera(void)
	{
	}

	void Camera::moveOver(GLfloat xVal, GLfloat yVal)
	{
		// Update camera xPos (+=)
		xPos += xVal;

		// Update camera yPos (-=)
		yPos -= yVal;
	}

	void Camera::setPosition(GLfloat xPos, GLfloat yPos)
	{
		// Set xPos
		this->xPos = xPos;

		// Set yPos
		this->yPos = yPos;
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

