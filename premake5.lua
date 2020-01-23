workspace "CoverTail" 
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CoverTail"
	location "CoverTail"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include",
		"CoverTail/src"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CT_PLATFORM_WINDOWS",
			"CT_BUILD_DLL"
		}

		postbuildcommands
		{ 
			("{COPY} %{cfg.buildtarget.relpath}  ../bin/"..outputdir.."/%{prj.name}");
		}
	
	filter "configurations:Debug"
		defines "CT_DEBUG"
		optimize "On" 

	filter "configurations:Release"
		defines "CT_RELEASE"
		optimize "On" 

	filter "configurations:Dist"
		defines "CT_DIST"
		optimize "On" 



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")


	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CoverTail/vendor/spdlog/include",
		"CoverTail/src"
	}
	
	links 
	{
		"CoverTail"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CT_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{ 
			("{COPY} %{cfg.buildtarget.relpath}  ../bin/" ..outputdir.. "Sandbox");
		}
	
	filter "configurations:Debug"
		defines "CT_DEBUG"
		optimize "On" 

	filter "configurations:Release"
		defines "CT_RELEASE"
		optimize "On" 

	filter "configurations:Dist"
		defines "CT_DIST"
		optimize "On" 
