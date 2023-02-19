#pragma once

#include <windows.h>

#include <stdio.h>

class Window
{
public:
	Window(const char* filePath);
	~Window();

	inline int GetID() { return id; }
	inline void SetID(const int newID) { id = newID; }

	inline bool IsCreated() { return wcreated; }
	
	inline bool IsMutexCaught() { return mutex_caught; }
	inline void SetMutexCaught(const bool mcaught) { mutex_caught = mcaught; };

	inline STARTUPINFO* GetSI() { return &StartupInfo; }
	inline PROCESS_INFORMATION* GetPI() { return &ProcessInformation; }
	inline HWND GetHWND() { return win_ptr; }
	inline void SetHWND(const HWND new_hwnd) { win_ptr = new_hwnd; }

	
	inline void SetTitle(const char* tName) { SetWindowText(win_ptr, tName); }

	void Kill();
	bool InjectDLL(const char* dllPath);

private:
	int id = 0;
	bool wcreated = false;
	bool mutex_caught = false;

	STARTUPINFO StartupInfo = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION ProcessInformation;
	HWND win_ptr = nullptr;
protected:
};

