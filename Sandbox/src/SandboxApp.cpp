#include <CoverTail.h>

class Sandbox : public CoverTail::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

CoverTail::Application* CoverTail::CreateApplication()
{
	return new Sandbox();
}

 