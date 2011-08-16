# CMake Build File for TGA Engine
# author: Tag Ashby <tgashby@calpoly.edu>

cmake_minimum_required(VERSION 2.8)

project(TGAEngine)

macro(ADD_FRAMEWORK fwname path appname)
	find_library(FRAMEWORK_${fwname}
		NAMES ${fwname}
		PATHS ${path}

		PATH_SUFFIXES Frameworks
		NO_DEFAULT_PATH
	)

	if( ${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
		message(ERROR ": Framework ${fwname} not found")
	else()
		target_link_libraries(${appname} ${FRAMEWORK_${fwname}})
		message(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
	endif()
endmacro(ADD_FRAMEWORK)
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
   src/Engine.cpp
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
   include/Engine.h
)

# Non-System Libraries

set(
	LIB_FOLDER
	${CMAKE_CURRENT_SOURCE_DIR}/lib
	CACHE STRING "Path to libraries" FORCE
)

# SDL
set(
	SDL_FOLDER
	${LIB_FOLDER}/sdl-1.3
	CACHE STRING "Path to SDL 1.3" FORCE
)

find_library(
	SDL_LIBRARY
	NAMES SDL-1.3.0 SDL
	PATHS ${SDL_FOLDER}
	PATH_SUFFIXES Apple Win32
	NO_DEFAULT_PATH
)

find_library(
	SDLMAIN_LIBRARY
	NAMES SDLmain
	PATHS ${SDL_FOLDER}
	PATH_SUFFIXES Apple Win32
	NO_DEFAULT_PATH
)

find_library(
	TGA_ENGINE_LIBRARY
	NAMES TGAEngine
	PATHS ${LIB_FOLDER}/TGAEngine
	PATH_SUFFIXES Apple Win32
	NO_DEFAULT_PATH
)

# SDL_Image
set(
	SDL_IMG_FOLDER
	${LIB_FOLDER}/SDL_image
	CACHE STRING "Path to SDL_image 1.2" FORCE
)

# System Libraries

# OpenGL
find_package(
	OpenGL REQUIRED
)

# Deal with Platform Specific things

if (APPLE)
    add_custom_command(TARGET TGAEngine
		PRE_LINK
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${LIB_FOLDER}/SDL_image.framework /Library/SDL_image.framework
	)
	
	ADD_FRAMEWORK(Cocoa /System/Libray/ Animation-Calibrator)
	ADD_FRAMEWORK(SDL_image /Library/ Animation-Calibrator)
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

add_library(TGAEngine SHARED
	${INCLUDES}
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
