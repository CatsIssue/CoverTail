#pragma once

#ifdef CT_PLATFORM_WINDOWS

extern CoverTail::Application* CoverTail::CreateApplication();

int main(int argc, char** argv)
{
	printf("CoverTail Engine");

	auto app = CoverTail::CreateApplication();
	app->Run();
	delete app;

	
}
#endif