#include <Windows.h>

HMODULE g_hThisMod = NULL;

BOOL WINAPI DllMain(HMODULE hThisModule, DWORD dwReason, LPVOID reserved)
{
    if (DLL_PROCESS_ATTACH == dwReason)
    {
        g_hThisMod = hThisModule;
        DisableThreadLibraryCalls(hThisModule);
    }
    else if (DLL_PROCESS_DETACH == dwReason)
    {
    }
    return TRUE;
}