#include "Animation.h"
#include "AnimationManager.h"

namespace TGA
{
	Animation::Animation()
	{
		texture = NULL;

		currFrame = 0;
		lastUpdate = SDL_GetTicks();
		paused = false;
		done = false;
		repetitions = 0;

		Singleton<AnimationManager>::GetSingletonPtr()->addAnimation(this);
	}

	Animation::Animation(Texture* texture)
	{
      assert(texture);
		this->texture = texture;

		currFrame = 0;
		lastUpdate = SDL_GetTicks();
		paused = false;
		done = false;
		repetitions = 0;

		Singleton<AnimationManager>::GetSingletonPtr()->addAnimation(this);
	}

	Animation::~Animation()	{}

	void Animation::update()
	{
		if(texture != NULL && !paused && !done && frames.size() > 0)	
		{
			// IF enough time has passed
			if((SDL_GetTicks() - lastUpdate) > frames.at(currFrame).second)
			{
				currFrame++;

				lastUpdate = SDL_GetTicks();            

				if(currFrame == frames.size())
				{
					currFrame = 0;
               
               // IF it is not running indefinitely
               if(repetitions != -1)
               {
                  if(repetitions == 0)
                  {
                     done = true;
                     paused = true;
                  }
                  else 
                  {
                     repetitions--;
                  }
               }
				}
			}
		}
	}

	void Animation::pause()
	{
		paused = true;
	}
	
	void Animation::resume()
	{
      if (paused)
      {
         paused = false;

         lastUpdate = SDL_GetTicks();
      }
	}

	void Animation::reset()
	{
		currFrame = 0;

		done = false;
		paused = false;

		lastUpdate = SDL_GetTicks();
	}

	bool Animation::isDone()
	{
		return done;
	}

	bool Animation::isPaused()
	{
		return paused;
	}

	void Animation::deleteMe()
	{
		Singleton<AnimationManager>::GetSingletonPtr()->removeAnimation(this);
	}

	void Animation::addFrame(SDL_Rect frameRect, Uint32 delay)
	{
		frames.push_back(std::make_pair(frameRect, delay));
	}

	void Animation::deleteFrame(GLuint frameNum)
	{
		if(frameNum < frames.size())
		{
			frames.erase(frames.begin() + frameNum);
		}
	}

	void Animation::clearFrames()
	{
		frames.clear();
	}

	void Animation::goToFrame(GLuint frame)
	{
		if(frame < frames.size())
		{
			currFrame = frame;
			
			lastUpdate = SDL_GetTicks();
		}
	}

	void Animation::setRepetitions(int repetitions)
	{
      // This looks weird, I know. The way update is running, you get a "free"
      // full cycle, that's why I'm subtracting one from repetitions.
		this->repetitions = repetitions - 1;
      
      if (done)
      {
         reset();
      }
	}

	void Animation::setTexture(Texture* texture)
	{
		this->texture->deleteMe();

		this->texture = texture;
	}

	void Animation::setDelay(GLuint frame, Uint32 delay)
	{
		if(frame < frames.size())
		{
			frames.at(frame).second = delay;
		}
	}
	
	void Animation::setFrameBounds(GLuint frame, SDL_Rect newBounds)
	{
		if(frame < frames.size())
		{
			frames.at(frame).first = newBounds;
		}
	}

	void Animation::draw(GLfloat xPos, GLfloat yPos)
	{
		// IF the texture exists
		if(texture != NULL && frames.size() > 0)
		{
			SDL_Rect tempRect = frames.at(currFrame).first;

			texture->drawSection(xPos, yPos, tempRect.x, tempRect.y, tempRect.w, tempRect.h);
		}
	}

	GLuint Animation::getFrameCount()
	{
		return frames.size();
	}
   
   SDL_Rect Animation::getCurrentFrameDimensions()
   {
      return frames.at(currFrame).first;
   }

	std::string Animation::printFrames()
	{
		std::stringstream frameStr;

		for(unsigned int ndx = 0; ndx < frames.size(); ndx++)
		{
			frameStr << "Frame: " << ndx << "\n"
				 << "X: " << frames.at(ndx).first.x << "  Y: " << frames.at(ndx).first.y << "\n" 
				 << "Width: " << frames.at(ndx).first.w << "  Height: " << frames.at(ndx).first.h << "\n"
				 << "Delay: " << frames.at(ndx).second << "\n\n";
		}

		return frameStr.str();
	}
}
