solution("TGAEngine")
	configurations({"Debug", "Release"})

	project("TGAEngine")
		kind("StaticLib")
		language("C++")
		files({
			"../include/**.h",
			"../src/**.cpp"
			})
		includedirs({
			"../include",
			"../include/**"
			})
		libdirs({
			"../lib",
			"../lib/**"
			})

		links({
			"SDL2.framework",
			"OpenGL.framework"
			})

		configuration("Debug")
			defines({"DEBUG"})

		configuration("Release")
			defines({"NDEBUG"})
