#pragma once

namespace TGA
{
	class Camera
	{
	public:
		Camera(GLfloat xPos, GLfloat yPos);
		~Camera(void);

		void moveOver(GLfloat xVal, GLfloat yVal);
		void setPosition(GLfloat xPos, GLfloat yPos);

		GLfloat getX();
		GLfloat	getY();

	private:
		GLfloat xPos, yPos;
	};
}


