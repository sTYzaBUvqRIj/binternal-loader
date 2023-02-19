


#include "Window.h"




Window::Window(const char* filePath)
{
	if (CreateProcess(filePath, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &StartupInfo, &ProcessInformation))
		wcreated = true;
}

Window::~Window()
{
	if (ProcessInformation.hProcess != NULL)
		TerminateProcess(ProcessInformation.hProcess, 0);
	CloseHandle(ProcessInformation.hThread);
}

void Window::Kill()
{

    TerminateProcess(ProcessInformation.hProcess, 9);
    CloseHandle(ProcessInformation.hThread);
    this->win_ptr = nullptr;
    this->mutex_caught = false;
}

bool Window::InjectDLL(const char* dllpath)
{
    if (ProcessInformation.hProcess == NULL)
        return false;
    void* loc = VirtualAllocEx(ProcessInformation.hProcess, 0, strlen(dllpath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (loc) {
        WriteProcessMemory(ProcessInformation.hProcess, loc, dllpath, strlen(dllpath) + 1, 0);
        printf("Writing DLL path to process\n");
    }
    else {
        printf("Failed allocating!\n");
        return false;
    }

    const HANDLE hThread = CreateRemoteThread(ProcessInformation.hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);
    if (hThread) {
        printf("DLL Injected!\n");
        CloseHandle(hThread);
    }
    else {
        printf("Injection Failed!\n");
        return false;
    }
    return true;
}