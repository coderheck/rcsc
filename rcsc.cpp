#include <iostream>
#include <filesystem>
#include <windows.h>

namespace fs = std::filesystem;

int main() {

    const char * subkey = "roblox-player\\shell\\open\\command";
    const char * valname = "version";
    char buffer[256];
    DWORD buffersize = sizeof(buffer);

    if (ERROR_SUCCESS == RegGetValueA(HKEY_CLASSES_ROOT, subkey, valname,
                                      RRF_RT_REG_SZ, nullptr, buffer, &buffersize)) { // retrieve RobloxPlayer version
        std::cout << "version: " << buffer << "\n";
    } else {
        std::cerr << "cannot get current RobloxPlayer version, try reinstalling Roblox";
        return 1;
    }


    fs::path robloxPath = "C:\\Program Files (x86)\\Roblox\\Versions";
    robloxPath /= buffer; //append version
    robloxPath /= "ClientSettings"; //append "ClientSettings"
    std::error_code err;

    if (fs::exists(robloxPath)) {
        std::cout << "found current ClientSettings, attempting to delete...\n";
        fs::remove_all(robloxPath, err); // delete current ClientSettings
        if (err) {
            std::cerr << "an error happened while deleting current ClientSettings: " << err.message();
            return 1;
        }
        std::cout << "delete success\n";
    }

    
    wchar_t settingsPath[1024] = {0};
    GetModuleFileNameW(nullptr, settingsPath, 1024);
    fs::path srcPath = fs::path(settingsPath).parent_path() / "ClientSettings/ClientAppSettings.json"; //file to copy

    try {
        fs::create_directories(robloxPath); // creating new ClientSettings folder
    } catch (const fs::filesystem_error & e) {
        std::cerr << "an error happened while making new ClientSettings folder: " << e.what();
    }

    try {
        fs::copy_file(srcPath, robloxPath / srcPath.filename(), fs::copy_options::overwrite_existing); // copying new ClientSettings to folder
    } catch (const fs::filesystem_error & e) {
        std::cerr << "an error happened while copying new ClientSettings: " << e.what();
        return 1;
    }


    std::cout << "copy ClientSettings success, exiting normally";
    Sleep(500);
    return 0;
}
