


#include "Process.h"

Process::Process(void* userdata)
{}

void Process::OnUserCreate()
{}

bool Process::OnWindowCreated(Window* window)
{
	return true;
}

void Process::Initialize()
{
	OnUserCreate();
	// initialize internal stuff
}

Window* Process::New(const char* fileName)
{
	Window* window = new Window(fileName);
	if (OnWindowCreated(window)) {
		WindowList.push_back(window);
		return window;
	}

	delete window;
	return NULL;
}