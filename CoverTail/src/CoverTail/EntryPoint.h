#pragma once

#ifdef CT_PLATFORM_WINDOWS

extern CoverTail::Application* CoverTail::CreateApplication();
 
int main(int argc, char** argv)
{
	printf("CoverTail Engine with logging");

	CoverTail::Log::Init();
	CT_CORE_WARN("Init Log!");
	int a = 5;
	CT_CORE_INFO("Client Init Log Var = {a}", a);

	auto app = CoverTail::CreateApplication();
	app->Run();
	delete app;

	
}
#endif