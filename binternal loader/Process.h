#pragma once

#include <windows.h>

#include <vector>

#include "Window.h"

class Process
{
public:
	
	Process(void* userdata = NULL);
	// Overriding
	virtual void OnUserCreate();
	virtual bool OnWindowCreated(Window* window);

	void Initialize();
	inline void SetPublicMutex(const HANDLE newMutex)
	{
		CloseHandle(PublicMutex);
		PublicMutex = newMutex;
	}
	inline HANDLE CreateNewMutex(const char* mID)
	{
		return CreateMutex(NULL, FALSE, mID);
	}
	inline HANDLE GetMutex()
	{
		return PublicMutex;
	};


	Window* New(const char* fileName);

private:
	HANDLE PublicMutex;

	std::vector<Window*> WindowList;


};