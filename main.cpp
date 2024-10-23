#include "paket.h"

int main()
{
    user U;
    paketData PD;
    createListUser(U);
    createListPaketData(PD);
    menuUtama(U, PD);
    cout << "**** PROGRAM SELESAI ****" << endl;
}
