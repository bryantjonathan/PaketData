#include <iostream>
using namespace std;
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define first_relation(P) P->first_relation

typedef struct elm_relation *adr_relation;
typedef struct elm_paketData *adr_paketData;
typedef struct elm_user *adr_user;

// # USER
struct infotype_user
{
    string nomor;
    int pulsa;
    int point;
};
struct elm_user
{
    infotype_user info;
    adr_user next;
    adr_relation first_relation;
};
struct user
{
    adr_user first;
};

// # PAKET DATA
struct infotype_paketData
{
    string namaPaket;
    int hargaPulsa, hargaPoint, point, kuota;
};

struct elm_paketData
{
    infotype_paketData info;
    adr_paketData next;
};

struct paketData
{
    adr_paketData first;
};

// # ELEMEN RELASI
struct infotype_relasi
{
    adr_paketData paketdata;
    int kuota;
};
struct elm_relation
{
    infotype_relasi info;
    adr_relation next;
};

// # ALL MENU
void tampilanAdmin(user &U, paketData &PD);
void tampilanUser(user &U, paketData PD);
void menuUtama(user &U, paketData &PD);

// #Create List
void createListUser(user &L);
void createListPaketData(paketData &L);

// #Create Element List
adr_user createElementUser(infotype_user X);
adr_paketData createElementPaketData(infotype_paketData X);
adr_relation createElementRelasi(infotype_relasi X);

// # insert Element List
void insertFirstUser(user &L, adr_user p);
void insertLastUser(user &L, adr_user p);
void insertFirstPaketData(paketData &L, adr_paketData p);
void insertLastPaketData(paketData &L, adr_paketData p);

// # Tambah Relasi
void tambahRelasi(adr_user &p, adr_relation r);

// # Searching User, PaketData, Relasi
adr_user searchingUser(user &L, string nama);
adr_paketData searchingPaketData(paketData &L, string nama);
adr_relation searchingRelasi(adr_user U, adr_paketData PD);

// # Print
void printPaketData(paketData L);
void printUser(user U);
void printUserdanPaket(user U);
void printRelasi(adr_user U);
void printPenggunaPaketDataTertentu(user U, adr_paketData PD);
void printPaketDataPenggunaTertentu(adr_user U);

// # Jumlah Paket Data
int jumlahPaketData(adr_user p);

// # Delete Relasi
void deleteLastRelasi(adr_user &U, adr_relation &hapus);
void deleteAllRelasi(adr_user &U);
void deleteRelasiTertentu(adr_user &U, adr_relation &hapus);

// # Delete User, Paket Data
void deleteUser(user &U, adr_user &p);
void deletePaketData(paketData &PD, user &U, adr_paketData &adrP);