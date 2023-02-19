
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <windows.h>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <string>

#include "Process.h"

std::string growtopiaPath = "";
std::string dllPath = "";

class GrowtopiaProcess : public Process
{
public:
    void OnUserCreate()
    {

    }

    bool OnWindowCreated(Window* window)
    {
        if (window->IsCreated())
            return true;
		return false;
    }
};

inline bool IsExist(const char* path)
{
    struct stat sb;
    return stat(path, &sb) == 0;
}

int main(const int argc, const char** argv)
{
    SetConsoleTitle("B'INTERNAL Injector!");
    if (__argc == 2) {
        dllPath = std::string(__argv[1]); // dllpath should be first args

        char gtPath[MAX_PATH] = { 0 };
        sprintf(gtPath, "%s\\Growtopia\\Growtopia.exe", getenv("LOCALAPPDATA"));
        BACK:
        system("cls");
        if (!IsExist(gtPath)) {
            printf("Couldn't find Growtopia at %s. Input growtopia path: ", gtPath);
            memset(gtPath, 0, MAX_PATH);
            scanf("%s", &gtPath[0]);
            goto BACK;
        }
        
        growtopiaPath = std::string(gtPath);
        GrowtopiaProcess* process = new GrowtopiaProcess();
        process->Initialize();
        Window* window = process->New(growtopiaPath.c_str());;
        if (window) {
            printf("Injecting... please wait 5 sec\n");
            Sleep(5000);
            window->InjectDLL(dllPath.c_str());
        }
        delete process;
    }
    else
        fprintf(stderr, "Drag dll file to this app when open\n");
    system("pause");
    return EXIT_SUCCESS;
}
