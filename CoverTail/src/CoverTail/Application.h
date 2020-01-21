#pragma once

#include "Core.h"

namespace CoverTail {

	class CoreTail_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// This is defined in a Client
	Application* CreateApplication();
}

