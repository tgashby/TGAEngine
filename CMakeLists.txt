# CMake Build File for TGA Engine
# author: Tag Ashby <tgashby@calpoly.edu>

cmake_minimum_required(VERSION 2.8)

project(TGAEngine)

# Sources
set(
   SOURCES
   src/Animation.cpp
   src/AnimationManager.cpp
   src/InputManager.cpp
   src/Texture.cpp
   src/TextureManager.cpp
   src/Font.cpp
   src/FontManager.cpp
   src/Camera.cpp
   src/GraphicsManager.cpp
   src/Sound.cpp
   src/SoundManager.cpp
   src/StateManager.cpp
   src/ProcessManager.cpp
   src/Process.cpp
   src/App.cpp
)

# Includes
set(
   INCLUDES
   include/Animation.h
   include/AnimationManager.h
   include/InputManager.h
   include/Key.h
   include/ProjIncludes.h
   include/Texture.h
   include/TextureManager.h
   include/Singleton.h
   include/Font.h
   include/FontManager.h
   include/Camera.h
   include/GraphicsManager.h
   include/Sound.h
   include/SoundManager.h
   include/State.h
   include/Purpose.h
   include/StateManager.h
   include/ProcessManager.h
   include/Process.h
   include/App.h
)

# Non-System Libraries

# SDL
set(
   SDL_FOLDER
   ${CMAKE_CURRENT_SOURCE_DIR}/lib/sdl-1.3
   CACHE STRING "Path to SDL 1.3" FORCE
)

find_library(
   SDL_LIBRARY
   NAMES SDL-1.3.0 SDL
   PATHS ${SDL_FOLDER}
   PATH_SUFFIXES local/lib VisualC/SDL/Win32/Release
   NO_DEFAULT_PATH
)

# SDL_Image
set(
   SDL_IMG_FOLDER
   ${SDL_IMG_FOLDER} ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL_image
   CACHE STRING "Path to SDL_image 1.2" FORCE
)

# System Libraries

# OpenGL
find_package(
   OpenGL REQUIRED
)

# Deal with Platform Specific things
set(
   EXTRA_LIBS
   ""
)

if (APPLE)
   FIND_LIBRARY(COCOA_LIBRARY Cocoa)
   FIND_LIBRARY(SDL_IMG_LIBRARY SDL_image)
   MARK_AS_ADVANCED (
		COCOA_LIBRARY
		SDL_IMG_LIBRARY
   )
   SET(EXTRA_LIBS ${COCOA_LIBRARY} ${SDL_IMG_LIBRARY})
endif()

if(WIN32)	
	find_library(
	   SDL_IMG_LIBRARY
	   NAMES SDL_image
	   PATHS ${SDL_IMG_FOLDER}
	   PATH_SUFFIXES lib
	   NO_DEFAULT_PATH
	)
endif()

# Include the Includes
include_directories(
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${SDL_FOLDER}/include
   ${SDL_IMG_FOLDER}/include
)

add_library(TGAEngine
	${SOURCES}
)

# Link all the libraries
target_link_libraries(
   TGAEngine
   ${OPENGL_LIBRARIES}
   ${SDL_LIBRARY}
   ${SDL_IMG_LIBRARY}
   ${EXTRA_LIBS}
)
