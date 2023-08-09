#include <Windows.h>
#include "..\mydll\mydll.h"
typedef void(__cdecl* HelloWorldFunc)();

int main() 
{
    LPCWSTR file = L"E:\\Code_Files_Tutorial\\C_Cpp_Codes\\mydll\\x64\\Release\\mydll.dll";
    HMODULE dllHandle = LoadLibrary(file);
    if (dllHandle)
    {
        HelloWorldFunc func = (HelloWorldFunc)GetProcAddress(dllHandle, "HelloWorldFromDLL");
        if (func)
        {
            func(); 
        }
        FreeLibrary(dllHandle);
    }
    return 0;
}
