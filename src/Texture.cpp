#include "Texture.h"
#include "TextureManager.h"

namespace TGA
{
	Texture::Texture()
	{
		// Initialize all members with default values
		texture = 0;
		fileName = "";
		width = 0;
		height = 0;
	}

	Texture::Texture(std::string fileName)
	{
		this->fileName = fileName;
		if (!loadTexture(fileName))
		{
         std::cout << "Error loading texture from file: " << fileName << "\n";
         std::cout << "Texture not loaded. Retry with texture.loadTexture(fileName)\n";
		}
	}

	Texture::~Texture()
	{
	}

	bool Texture::loadTexture(std::string imgFileName)
	{
		SDL_Surface* image;

		try 
      {
			image = IMG_Load(imgFileName.c_str());
		} 
      catch(...) 
      {
			std::cout << "Error: " << SDL_GetError() << std::endl;
			return false;
		}

		if(image == NULL)
		{
			std::cout << "Error: " << SDL_GetError() << std::endl;
			return false;
		}

		// Format the image to be more usable with OGL
      SDL_PixelFormat RGBAFormat;
      RGBAFormat.palette = 0;
      RGBAFormat.BitsPerPixel = 32; 
      RGBAFormat.BytesPerPixel = 4;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
      RGBAFormat.Rmask = 0xFF000000; RGBAFormat.Rshift =  0; RGBAFormat.Rloss = 0;
      RGBAFormat.Gmask = 0x00FF0000; RGBAFormat.Gshift =  8; RGBAFormat.Gloss = 0;
      RGBAFormat.Bmask = 0x0000FF00; RGBAFormat.Bshift = 16; RGBAFormat.Bloss = 0;
      RGBAFormat.Amask = 0x000000FF; RGBAFormat.Ashift = 24; RGBAFormat.Aloss = 0;
#else
      RGBAFormat.Rmask = 0x000000FF; RGBAFormat.Rshift = 24; RGBAFormat.Rloss = 0;
      RGBAFormat.Gmask = 0x0000FF00; RGBAFormat.Gshift = 16; RGBAFormat.Gloss = 0;
      RGBAFormat.Bmask = 0x00FF0000; RGBAFormat.Bshift =  8; RGBAFormat.Bloss = 0;
      RGBAFormat.Amask = 0xFF000000; RGBAFormat.Ashift =  0; RGBAFormat.Aloss = 0;
#endif

      SDL_Surface *conv = SDL_ConvertSurface(image, &RGBAFormat, SDL_SWSURFACE);
      SDL_FreeSurface(image);

      image = conv;

		fileName = imgFileName;

		width = image->w;
		height = image->h;

		glGenTextures(1, &texture);

		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
      
		SDL_FreeSurface(image);

		Singleton<TextureManager>::GetSingletonPtr()->addTexture(this);
		return true;
	}

   bool Texture::reset()
   {
      return loadTexture(this->fileName);
   }

	void Texture::deleteMe()
	{
		Singleton<TextureManager>::GetSingletonPtr()->removeTexture(this);
	}

   void Texture::draw( float xPos, float yPos, float scaleX /*= 1*/, float scaleY /*= 1*/, float rotation /*= 0*/ )
   {
      glPushMatrix();

      glMatrixMode(GL_TEXTURE);

      glBindTexture(GL_TEXTURE_2D, texture);

      glLoadIdentity();

      glMatrixMode(GL_MODELVIEW);

      glTranslatef(Singleton<Camera>::GetSingletonPtr()->getX(), Singleton<Camera>::GetSingletonPtr()->getY(), 0.0f);

      glTranslatef(xPos + (float)width / 2, 0, 0);
      glScalef(scaleX, scaleY, 1);
      if (rotation != 0)
      {
         glRotatef(rotation, 0, 0, 1);
      }
      glTranslatef(-(xPos + (float)width / 2), 0, 0);

      glBegin(GL_QUADS);

         glTexCoord2f(0.0f, 0.0f);
         glVertex2f(xPos, yPos);

         glTexCoord2f(1.0f, 0.0f);
         glVertex2f(xPos + width, yPos);

         glTexCoord2f(1.0f, 1.0f);
         glVertex2f(xPos + width, yPos + height);

         glTexCoord2f(0.0f, 1.0f);
         glVertex2f(xPos, yPos + height);

      glEnd();

      glColor3f(1.0f, 1.0f, 1.0f);

      glPopMatrix();
   }

   void Texture::drawSection( float xPos, float yPos, SDL_Rect section, float scaleX /*= 1*/, float scaleY /*= 1*/, float rotation /*= 0*/ )
   {
      drawSection(xPos, yPos, section.x, section.y, section.w, section.h, scaleX, scaleY, rotation);
   }

   void Texture::drawSection( float xPos, float yPos, int sectX, int sectY, int sectWidth, int sectHeight, float scaleX /*= 1*/, float scaleY /*= 1*/, float rotation /*= 0*/ )
   {
      glPushMatrix();

      glMatrixMode(GL_TEXTURE);

      glBindTexture(GL_TEXTURE_2D, texture);

      glLoadIdentity();

      glScalef(1/(float)width, 1/(float)height, 1);

      glMatrixMode(GL_MODELVIEW);

      glTranslatef(Singleton<Camera>::GetSingletonPtr()->getX(), Singleton<Camera>::GetSingletonPtr()->getY(), 0.0f);

      glTranslatef(xPos + (float)sectWidth / 2, 0, 0);
      glScalef(scaleX, scaleY, 1);
      if (rotation != 0)
      {
         glRotatef(rotation, 0, 0, 1);
      }
      glTranslatef(-(xPos + (float)sectWidth / 2), 0, 0);

      glBegin(GL_QUADS);

         glTexCoord2f((GLfloat)sectX, (GLfloat)sectY);
         glVertex2f(xPos, yPos);

         glTexCoord2f((GLfloat)(sectX + sectWidth), (GLfloat)sectY);
         glVertex2f(xPos + sectWidth, yPos);

         glTexCoord2f((GLfloat)(sectX + sectWidth), (GLfloat)(sectY + sectHeight));
         glVertex2f(xPos + sectWidth, yPos + sectHeight);

         glTexCoord2f((GLfloat)sectX, (GLfloat)(sectY + sectHeight));
         glVertex2f(xPos, yPos + sectHeight);

      glEnd();

      glColor3f(1.0f, 1.0f, 1.0f);

      glPopMatrix();
   }

	GLsizei Texture::getWidth()
	{
		return width;
	}

	GLsizei Texture::getHeight()
	{
		return height;
	}
}