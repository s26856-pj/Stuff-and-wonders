#include <Windows.h>
#include <tchar.h>

void przypomnij_o_commit() {
    MessageBox(NULL, _T("Klaudia Słońce, zrób commit!"), _T("Przypomnienie o commicie"), MB_ICONINFORMATION | MB_OK);
}

int main() {
    // Ustawiamy czas przypomnienia (20 minut w milisekundach)
    DWORD czas_przypomnienia = 20 * 60 * 1000;

    while (true) {
        Sleep(czas_przypomnienia);
        przypomnij_o_commit();
    }

    return 0;
}
