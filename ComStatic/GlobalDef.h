#ifndef GLOBALDEF_H_H_
#define GLOBALDEF_H_H_
#include <Windows.h>
#include <Shlwapi.h>

#define SFV_SERVICE_NAME           L"DbgService"
#define SFV_SERVICE_DISPLAY_NAME   L"DbgService"
#define SFV_SERVICE_DESCRIPTION    L"DbgService����"

#define SFV_NOTIFY_NAME L"Global\\{784BC5BC-25D1-4861-8FED-38CFF9428877}"

#define PATH_SERVICE_CACHE L"software\\vdebug\\runner"
#define RUNNER_EVENT32  (L"dbg32_%ls")
#define RUNNER_EVENT64  (L"dbg64_%ls")
#define SERVICE_EVENT   (L"service_%ls")

#if WIN64 || _WIN64
#define REG_VDEBUG_CACHE    L"SoftWare\WOW6432Node\\vdebug\\config\\dbgport"
#else
#define REG_VDEBUG_CACHE    L"SoftWare\\vdebug\\config\\dbgport"
#endif

#define UNIQUE_DEBUG    L"debug"    //������

enum DebuggerStatus
{
    em_dbg_status_init,
    em_dbg_status_busy,
    em_dbg_status_free
};

struct ProcMonInfo {
    DWORD procUnique;
    DWORD procPid;
    std::ustring procPath;
    std::ustring procCmd;
    BOOL x64;
    std::ustring startTime;
    DWORD sessionId;
    DWORD parentPid;
    std::ustring procDesc;
    std::ustring procUser;
    std::ustring procUserSid;

    ProcMonInfo() {
        procUnique = 0;
        procPid = 0;
        sessionId = 0;
        x64 = FALSE;
        parentPid = 0;
    }
};

static std::mstring GetBaseDir() {
#if WIN64 || _WIN64
    HMODULE m = GetModuleHandleA("ComLib64.dll");
#else
    HMODULE m = GetModuleHandleA("ComLib32.dll");
#endif

    char buffer[512];
    GetModuleFileNameA(m, buffer, 512);
    PathAppendA(buffer, "..");
    return buffer;
}

static std::mstring GetConfigDbPath() {
    return (GetBaseDir() + "\\db\\cfg.db");
}

static std::mstring GetSymbolDbPath() {
    return (GetBaseDir() + "\\db\\symbol.db");
}
#endif //GLOBALDEF_H_H_