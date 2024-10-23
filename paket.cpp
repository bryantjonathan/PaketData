#include "paket.h"
#include <iostream>
using namespace std;
// #create list
void createListUser(user &L) { first(L) = NULL; }
void createListPaketData(paketData &L) { first(L) = NULL; }

// # Tampilan Admin
void tampilanAdmin(user &U, paketData &PD)
{
    int menu = 0, opsi = 0;
    string kembali = "y", subMenu, cari;
    adr_paketData p;
    adr_user adrUser, ketemu;
    infotype_user infoUser;
    infotype_paketData infoPaket;
    while (kembali == "y")
    {
        system("cls");

        subMenu = "y";
        cout << "--------- Anda Login sebagai Admin ---------" << endl;
        cout << "MENU:" << endl;
        cout << "1. Input data user" << endl;
        cout << "2. Input paket data" << endl;
        cout << "3. Lihat list user" << endl;
        cout << "4. Lihat list paket data" << endl;
        cout << "5. Hapus data user" << endl;
        cout << "6. Hapus data paket data" << endl;
        cout << "7. Cari data user" << endl;
        cout << "8. Cari data paket data" << endl;
        cout << "9. Tampilkan seluruh data user beserta paket data" << endl;
        cout << "10. Cari paket data dari user" << endl;
        cout << "11. Cari user dari paket data" << endl;
        cout << "12. Hapus paket data user" << endl;
        cout << "13. Jumlah paket data user" << endl;
        cout << "14. Keluar" << endl;
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1)
        { // Input data user
            system("cls");
            while (subMenu == "y")
            {

                cout << "Masukkan nomor: ";
                cin >> infoUser.nomor;
                ketemu = searchingUser(U, infoUser.nomor);
                if (ketemu == NULL)
                {

                    cout << "* INPUT DATA USER *" << endl;
                    cout << "Pulsa: ";
                    cin >> infoUser.pulsa;
                    cout << "Point: ";
                    cin >> infoUser.point;
                    cout << endl;

                    cout << "~ Opsi Input" << endl;
                    cout << "1. Insert First" << endl;
                    cout << "2. Insert Last" << endl;
                    cout << "Pilih: ";
                    cin >> opsi;
                    if (opsi == 1)
                    {
                        system("cls");
                        adrUser = createElementUser(infoUser);
                        insertFirstUser(U, adrUser);
                        cout << "< Data user berhasil ditambahkan >" << endl;
                        cout << "Tambah data user lagi (y/n)? ";
                        cin >> subMenu;
                        if (subMenu == "n")
                        {
                            kembali = "y";
                        }
                    }
                    else if (opsi == 2)
                    {
                        system("cls");
                        adrUser = createElementUser(infoUser);
                        insertLastUser(U, adrUser);
                        cout << "< Data user berhasil ditambahkan >" << endl;
                        cout << "Tambah data user lagi (y/n)? ";
                        cin >> subMenu;
                        if (subMenu == "n")
                        {
                            kembali = "y";
                        }
                    }
                    else
                    {
                        cout << "MASUKAN ANDA SALAH !" << endl;
                        subMenu = "y";
                    }
                }
                else
                {
                    cout << "Nomor telah terdaftar !" << endl;
                    cout << "Masukkan nomor lain (y/n)? ";
                    cin >> subMenu;
                }
            }
        }
        else if (menu == 2)
        { // Input paket data
            while (subMenu == "y")
            {
                system("cls");

                cout << "* INPUT PAKET DATA *" << endl;
                cout << "Nama Paket: ";
                cin >> infoPaket.namaPaket;
                cout << "Harga Paket: ";
                cin >> infoPaket.hargaPulsa;
                cout << "Kuota Paket: ";
                cin >> infoPaket.kuota;
                cout << "Point Paket: ";
                cin >> infoPaket.hargaPoint;
                cout << "Rewards Paket: ";
                cin >> infoPaket.point;
                cout << endl;

                cout << "~ Opsi Input" << endl;
                cout << "1. Insert First" << endl;
                cout << "2. Insert Last" << endl;
                cout << "Pilih: ";
                cin >> opsi;
                if (opsi == 1)
                {

                    p = createElementPaketData(infoPaket);
                    insertFirstPaketData(PD, p);
                    system("cls");
                    cout << "< Paket data berhasil ditambahkan >" << endl;
                    cout << "Tambah paket data lagi (y/n)? ";
                    cin >> subMenu;
                    if (subMenu == "n")
                    {
                        kembali = "y";
                    }
                }
                else if (opsi == 2)
                {

                    p = createElementPaketData(infoPaket);
                    insertLastPaketData(PD, p);
                    system("cls");
                    cout << "< Paket data berhasil ditambahkan >" << endl;
                    cout << "Tambah paket data lagi (y/n)? ";
                    cin >> subMenu;
                    if (subMenu == "n")
                    {
                        kembali = "y";
                    }
                }
                else
                {
                    cout << "MASUKAN ANDA SALAH !" << endl;
                    subMenu = "y";
                }
            }
        }
        else if (menu == 3)
        { // Lihat list user
            system("cls");
            printUser(U);
            cout << "Tekan y lalu enter untuk kembali: ";
            cin >> kembali;
        }
        else if (menu == 4)
        { // Lihat list paket data
            system("cls");

            printPaketData(PD);
            cout << "Tekan y lalu enter untuk kembali: ";
            cin >> kembali;
        }
        else if (menu == 5)
        { // Hapus data user

            while (subMenu == "y")
            {
                system("cls");
                cout << "* HAPUS DATA USER *" << endl;
                cout << "Masukkan nomor: ";
                cin >> cari;
                ketemu = searchingUser(U, cari);
                if (ketemu != NULL)
                {
                    system("cls");
                    deleteUser(U, ketemu);
                    cout << "Hapus data user lain (y/n)? ";
                }
                else
                {
                    cout << "Data user tidak ditemukan !" << endl;
                    cout << "Masukkan data user lain (y/n)? ";
                }
                cin >> subMenu;
                if (subMenu == "n")
                {
                    kembali = "y";
                }
            }
        }
        else if (menu == 6)
        { // Hapus data paket data
            adr_paketData zz;
            while (subMenu == "y")
            {
                system("cls");
                cout << "* HAPUS PAKET DATA *" << endl;
                cout << "Masukkan nama paket: ";
                cin >> cari;
                zz = searchingPaketData(PD, cari);
                if (zz != NULL)
                {
                    system("cls");
                    deletePaketData(PD, U, zz);
                    cout << "Hapus paket data lain (y/n)? ";
                }
                else
                {
                    cout << "Paket data tidak ditemukan ! " << endl;
                    cout << "Masukkan nama paket lain (y/n)? ";
                }
                cin >> subMenu;
                if (subMenu == "n")
                {
                    kembali = "y";
                }
            }
        }
        else if (menu == 7)
        { // Cari data user
            while (subMenu == "y")
            {
                system("cls");
                cout << "* CARI DATA USER *" << endl;
                cout << "Masukkan nomor: ";
                cin >> cari;
                adr_user su = searchingUser(U, cari);
                if (su != NULL)
                {
                    system("cls");
                    cout << "# DATA USER DITEMUKAN #" << endl;
                    cout << "Nomor User: " << info(su).nomor << endl;
                    cout << "Pulsa User: " << info(su).pulsa << endl;
                    cout << "Point User: " << info(su).point << endl;
                }
                else
                {
                    cout << "Data user tidak ditemukan ! " << endl;
                }
                cout << "Cari data user lain (y/n)? ";
                cin >> subMenu;
                if (subMenu == "n")
                {
                    kembali = "y";
                }
            }
        }
        else if (menu == 8)
        { // Cari data paket data
            while (subMenu == "y")
            {
                system("cls");
                cout << "* CARI DATA PAKET DATA *" << endl;
                cout << "Masukkan nama paket: ";
                cin >> cari;
                adr_paketData spd = searchingPaketData(PD, cari);
                if (spd != NULL)
                {
                    system("cls");
                    cout << "# PAKET DATA DITEMUKAN #" << endl;
                    cout << "Nama Paket: " << info(spd).namaPaket << endl;
                    cout << "Harga Paket: " << info(spd).hargaPulsa << endl;
                    cout << "Kuota Paket: " << info(spd).kuota << endl;
                    cout << "Point Paket: " << info(spd).hargaPoint << endl;
                    cout << "Rewards Paket: " << info(spd).point << endl;
                }
                else
                {
                    cout << "Paket data tidak ditemukan !" << endl;
                }
                cout << "Cari data paket data lain (y/n)? ";
                cin >> subMenu;
                if (subMenu == "n")
                {
                    kembali = "y";
                }
            }
        }
        else if (menu == 9)
        { // Tampilkan seluruh data user beserta paket data
            system("cls");
            if (first(U) != NULL)
            {
                printUserdanPaket(U);
            }
            else
            {
                cout << "Data user kosong !" << endl;
            }

            cout << "Tekan y untuk kembali : ";
            cin >> kembali;
        }
        else if (menu == 10)
        { // Cari paket data dari user
            while (subMenu == "y")
            {
                system("cls");

                cout << "* CARI PAKET DATA DARI USER *" << endl;
                cout << "Masukkan nomor: ";
                cin >> cari;
                ketemu = searchingUser(U, cari);
                if (ketemu != NULL)
                {
                    system("cls");
                    printPaketDataPenggunaTertentu(ketemu);
                }
                else
                {
                    cout << "Data user tidak ditemukan !" << endl;
                }

                cout << "Cari paket data user lain (y/n)? ";
                cin >> subMenu;
                if (subMenu == "n")
                {
                    kembali = "y";
                }
            }
        }
        else if (menu == 11)
        { // Cari user dari paket data
            while (subMenu == "y")
            {
                system("cls");

                cout << "* CARI USER DARI PAKET DATA *" << endl;
                cout << "Masukkan nama paket: ";
                cin >> cari;
                adr_paketData pp = searchingPaketData(PD, cari);
                if (pp != NULL)
                {
                    system("cls");
                    printPenggunaPaketDataTertentu(U, pp);
                }
                else
                {
                    cout << "Paket data tidak ditemukan !" << endl;
                }

                cout << "Cari nama paket data lain (y/n)? ";
                cin >> subMenu;
                if (subMenu == "n")
                {
                    kembali = "y";
                }
            }
        }
        else if (menu == 12) // Hapus paket data user
        {

            while (subMenu == "y")
            {
                system("cls");

                cout << "* HAPUS PAKET DATA USER *" << endl;
                cout << "Masukkan nomor: ";
                cin >> cari;
                ketemu = searchingUser(U, cari);
                if (ketemu == NULL)
                {
                    cout << "Data user tidak ditemukan !" << endl;
                }
                else
                {
                    string paket;
                    adr_relation r = first_relation(ketemu);
                    printPaketDataPenggunaTertentu(ketemu);
                    if (r != NULL)
                    {
                        cout << "Masukkan nama paket: ";
                        cin >> paket;

                        adr_paketData pp = searchingPaketData(PD, paket);
                        if (pp != NULL)
                        {
                            adr_relation hapus = searchingRelasi(ketemu, pp);
                            if (hapus != NULL)
                            {
                                deleteRelasiTertentu(ketemu, hapus);
                            }
                            else
                            {
                                cout << "User tidak memiliki paket " << info(pp).namaPaket << endl;
                            }
                        }
                        else
                        {
                            cout << "Paket data tidak ada !" << endl;
                        }
                    }
                }
                cout << "Hapus paket data user lain (y/n)? ";

                cin >> subMenu;
                if (subMenu == "n")
                {
                    kembali = "y";
                }
            }
        }
        else if (menu == 13)
        { // Jumlah paket data user
            while (subMenu == "y")
            {
                system("cls");

                cout << "* JUMLAH PAKET DATA USER *" << endl;
                cout << "Masukkan nomor: ";
                cin >> cari;
                ketemu = searchingUser(U, cari);
                if (ketemu == NULL)
                {
                    system("cls");
                    cout << "Data user tidak ditemukan !" << endl;
                }
                else
                {
                    system("cls");
                    cout << "Jumlah paket data: " << jumlahPaketData(ketemu) << endl;
                }

                cout << "Cari jumlah paket data user lain (y/n)? ";
                cin >> subMenu;
                if (subMenu == "n")
                {
                    kembali = "y";
                }
            }
        }
        else if (menu == 14)
        { // Keluar
            kembali = "n";
        }
        else
        {
            cout << "MASUKAN ANDA SALAH !" << endl;
            kembali = "y";
        }
    }
    if (kembali == "n")
    {
        menuUtama(U, PD);
    }
}

// # Tampilan User
void tampilanUser(user &U, paketData PD)
{
    string nomor, namaPaket, kembali = "y", subMenu = "y";
    int menu = 0, pilih = 0;
    adr_paketData cariPaket;
    infotype_user infoUser;
    infotype_relasi infoRelasi;
    adr_relation adrR, r;
    adr_user p, ketemu;
    cout << "Masukkan Nomor Anda: ";
    cin >> nomor;
    ketemu = searchingUser(U, nomor);
    if (ketemu == NULL)
    {
        system("cls");
        infoUser.pulsa = 10000;
        infoUser.point = 0;
        infoUser.nomor = nomor;
        p = createElementUser(infoUser);
        insertLastUser(U, p);
        cout << "# Selamat Nomor Anda Berhasil Di-registrasi #" << endl;
        cout << "Silahkan login ulang !" << endl;
        cout << "Tekan y lalu enter untuk kembali: ";
        cin >> kembali;
    }
    else
    { // USER SUDAH PERNAH LOGIN
        while (kembali == "y")
        {
            system("cls");
            subMenu = "y";
            cout << "--------- Anda Login sebagai User ---------" << endl;
            cout << "MENU:" << endl;
            cout << "1. Beli Paket Data" << endl;
            cout << "2. Lihat Paket Data" << endl;
            cout << "3. Lihat Pulsa dan Point" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilih: ";
            cin >> menu;
            if (menu == 1)
            { // Beli paket data
                system("cls");
                while (subMenu == "y" && first(PD) != NULL)
                {

                    printPaketData(PD);
                    cout << "- Pulsa Anda: " << info(ketemu).pulsa << endl;
                    cout << "- Point Anda: " << info(ketemu).point << endl;
                    cout << "Masukkan nama paket: ";
                    cin >> namaPaket;
                    cariPaket = searchingPaketData(PD, namaPaket);
                    if (cariPaket == NULL)
                    {
                        cout << " ! Paket Tidak Tersedia ! " << endl;
                    }
                    else
                    {
                        cout << "Beli menggunakan" << endl;
                        cout << "1. Pulsa" << endl;
                        cout << "2. Point" << endl;
                        cout << "Pilih: ";
                        cin >> pilih;
                        if (pilih == 1)
                        { // Pulsa
                            if (info(ketemu).pulsa >= info(cariPaket).hargaPulsa &&
                                info(ketemu).pulsa != 0)
                            {
                                r = searchingRelasi(ketemu, cariPaket);
                                if (r != NULL)
                                {
                                    info(r).kuota += info(cariPaket).kuota;
                                }
                                else
                                {
                                    infoRelasi.paketdata = cariPaket;
                                    infoRelasi.kuota = info(cariPaket).kuota;
                                    adrR = createElementRelasi(infoRelasi);
                                    tambahRelasi(ketemu, adrR);
                                }
                                info(ketemu).pulsa -= info(cariPaket).hargaPulsa;
                                info(ketemu).point += info(cariPaket).point;
                                system("cls");
                                cout << "< Paket data berhasil ditambahkan >" << endl;
                                cout << "Tambah paket data lain (y/n)? ";
                                cin >> subMenu;
                            }
                            else
                            {
                                system("cls");
                                cout << "Pulsa tidak mencukupi !" << endl;
                                cout << "Pilih paket data lain tekan y lalu enter: ";
                                cin >> subMenu;
                            }
                        }
                        else if (pilih == 2)
                        { // Point

                            if (info(ketemu).point >= info(cariPaket).hargaPoint &&
                                info(ketemu).point != 0)
                            {
                                r = searchingRelasi(ketemu, cariPaket);
                                if (r != NULL)
                                {
                                    info(r).kuota += info(cariPaket).kuota;
                                }
                                else
                                {
                                    infoRelasi.paketdata = cariPaket;
                                    infoRelasi.kuota = info(cariPaket).kuota;
                                    adrR = createElementRelasi(infoRelasi);
                                    tambahRelasi(ketemu, adrR);
                                }
                                info(ketemu).point -= info(cariPaket).point;
                                system("cls");
                                cout << "< Paket data berhasil ditambahkan >" << endl;
                                cout << "Tambah paket data lain (y/n)? ";
                                cin >> subMenu;
                            }
                            else
                            {
                                cout << "Point tidak mencukupi !" << endl;
                                cout << "Pilih paket data lain tekan y lalu enter: ";
                                cin >> subMenu;
                            }
                        }
                        else
                        {
                            cout << "! Inputan salah !" << endl;
                            subMenu = "y";
                        }
                    }
                }
                if (first(PD) == NULL)
                {
                    system("cls");
                    cout << "Paket data belum tersedia !" << endl;
                }

                cout << "Tekan y lalu enter untuk kembali: ";
                cin >> kembali;
            }
            else if (menu == 2)
            { // Lihat paket data
                system("cls");
                printRelasi(ketemu);
                cout << "Tekan y lalu enter untuk kembali: ";
                cin >> kembali;
            }
            else if (menu == 3)
            { // Lihat pulsa dan point
                system("cls");
                cout << "* CEK SALDO & POINT *" << endl;
                cout << "- Pulsa:" << info(ketemu).pulsa << endl;
                cout << "- Point:" << info(ketemu).point << endl;
                cout << "Tekan y lalu enter untuk kembali: ";
                cin >> kembali;
            }
            else if (menu == 4)
            { // Keluar
                kembali = "n";
            }
            else
            {
                cout << "MASUKAN ANDA SALAH !" << endl;
                kembali = "y";
            }
        }
    }
    menuUtama(U, PD);
}

// # Menu Utama
void menuUtama(user &U, paketData &PD)
{
    system("cls");
    int siapa;
    cout << "==============================================" << endl;
    cout << "             APLIKASI MY TELKOMCEL            " << endl;
    cout << "==============================================" << endl;
    cout << "Login sebagai: " << endl;
    cout << "1. Pengguna" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Exit" << endl;
    cout << "Masukkan pilihan anda: ";
    cin >> siapa;
    if (siapa == 1)
    { // Pengguna
        tampilanUser(U, PD);
    }
    else if (siapa == 2)
    { // Admin

        tampilanAdmin(U, PD);
    }
    else if (siapa == 3)
    {
    }
    else
    {
        cout << "MASUKAN ANDA SALAH !" << endl;
        menuUtama(U, PD);
    }
}

// #Create Element List
adr_user createElementUser(infotype_user X)
{
    adr_user p = new elm_user;
    info(p) = X;
    next(p) = NULL;
    first_relation(p) = NULL;
    return p;
}

adr_paketData createElementPaketData(infotype_paketData X)
{
    adr_paketData p = new elm_paketData;
    info(p) = X;
    next(p) = NULL;
    return p;
}

adr_relation createElementRelasi(infotype_relasi X)
{
    adr_relation p = new elm_relation;
    info(p) = X;
    next(p) = NULL;
    return p;
}

// # insert Element List
void insertFirstUser(user &L, adr_user p)
{
    if (first(L) == NULL)
    {
        first(L) = p;
    }
    else
    {
        next(p) = first(L);
        first(L) = p;
    }
}

void insertLastUser(user &L, adr_user p)
{
    if (first(L) == NULL)
    {
        first(L) = p;
    }
    else
    {
        adr_user a = first(L);
        while (next(a) != NULL)
        {
            a = next(a);
        }
        next(a) = p;
    }
}

void insertFirstPaketData(paketData &L, adr_paketData p)
{
    if (first(L) == NULL)
    {
        first(L) = p;
    }
    else
    {
        next(p) = first(L);
        first(L) = p;
    }
}

void insertLastPaketData(paketData &L, adr_paketData p)
{
    if (first(L) == NULL)
    {
        first(L) = p;
    }
    else
    {
        adr_paketData a = first(L);
        while (next(a) != NULL)
        {
            a = next(a);
        }
        next(a) = p;
    }
}

// # Tambah Relasi
void tambahRelasi(adr_user &p, adr_relation r)
{
    if (first_relation(p) == NULL)
    {
        first_relation(p) = r;
    }
    else
    {
        adr_relation a = first_relation(p);
        while (next(a) != NULL)
        {
            a = next(a);
        }
        next(a) = r;
    }
}
//  #Searching User, PaketData, Relasi
adr_user searchingUser(user &L, string nama)
{
    adr_user p = first(L);
    while (p != NULL)
    {
        if (info(p).nomor == nama)
        {
            return p;
        }

        p = next(p);
    }
    return NULL;
}

adr_paketData searchingPaketData(paketData &L, string nama)
{
    adr_paketData p = first(L);
    while (p != NULL)
    {
        if (info(p).namaPaket == nama)
        {
            return p;
        }

        p = next(p);
    }

    return NULL;
}

adr_relation searchingRelasi(adr_user U, adr_paketData PD)
{
    adr_relation p = first_relation(U);
    while (p != NULL)
    {
        if (info(p).paketdata == PD)
        {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

// # Print
void printPaketData(paketData L)
{
    adr_paketData p = first(L);
    if (p == NULL)
    {
        cout << "Data paket data kosong !" << endl;
    }
    else
    {
        cout << "* PAKET DATA TERSEDIA *" << endl;
        while (p != NULL)
        {
            cout << "Paket: " << info(p).namaPaket << endl;
            cout << "- Harga: " << info(p).hargaPulsa << endl;
            cout << "- Harga (point): " << info(p).hargaPoint << endl;
            cout << "- Kuota: " << info(p).kuota << endl;
            cout << "- Rewards: " << info(p).point << endl;
            cout << endl;
            p = next(p);
        }
    }
}

void printUser(user U)
{
    int i = 1;
    adr_user p = first(U);
    if (p == NULL)
    {
        cout << "Data user kosong !" << endl;
    }
    else
    {
        while (p != NULL)
        {
            cout << "User " << i << endl;
            cout << "Nomor: " << info(p).nomor << endl;
            cout << "Pulsa: " << info(p).pulsa << endl;
            cout << "Point: " << info(p).point << endl;
            cout << endl;
            i++;
            p = next(p);
        }
    }
}

void printUserdanPaket(user U)
{

    adr_user p = first(U);
    adr_relation r;
    adr_paketData pd;

    cout << "* DATA SEMUA USER DAN RELASI *" << endl;
    while (p != NULL)
    {
        r = first_relation(p);
        cout << "Nomor " << info(p).nomor << endl;
        cout << "Daftar paket: " << endl;
        if (r == NULL)
        {
            cout << "User tidak memiliki paket !" << endl;
        }
        else
        {
            while (r != NULL)
            {
                pd = info(r).paketdata;
                cout << "- " << info(pd).namaPaket << endl;
                r = next(r);
            }
            cout << endl;
        }
        p = next(p);
    }
}

void printRelasi(adr_user U)
{

    adr_relation r = first_relation(U);
    adr_paketData pd;

    if (r == NULL)
    {
        cout << "Anda belum memiliki paket data !" << endl;
    }
    else
    {
        cout << "* PAKET DATA ANDA *" << endl;
        while (r != NULL)
        {
            pd = info(r).paketdata;
            cout << "- " << info(pd).namaPaket << endl;
            cout << "Sisa Kuota: " << info(r).kuota << " GB" << endl;
            r = next(r);
        }
    }
}

void printPenggunaPaketDataTertentu(user U, adr_paketData PD)
{
    adr_user p = first(U);
    adr_relation q;
    adr_paketData pd = PD;
    int flag = 0;

    if (first(U) != NULL)
    {
        cout << "User dari paket data " << info(PD).namaPaket << ": " << endl;
        while (p != NULL)
        {
            q = searchingRelasi(p, pd);
            if (q != NULL)
            {
                flag = 1;
                cout << "- " << info(p).nomor << endl;
            }
            p = next(p);
        }
        if (flag == 0)
        {
            cout << "Tidak ada user dari paket data tersebut !" << endl;
        }
    }
    else
    {
        cout << "Tidak ada user !" << endl;
    }
}

void printPaketDataPenggunaTertentu(adr_user U)
{
    adr_relation q = first_relation(U);

    if (q != NULL)
    {
        cout << "Paket data dari user " << info(U).nomor << ": " << endl;
        while (q != NULL)
        {
            cout << "- " << info(info(q).paketdata).namaPaket << ": " << info(info(q).paketdata).kuota << " GB" << endl;
            q = next(q);
        }
    }
    else
    {
        cout << "User tidak memiliki paket data !" << endl;
    }
}

// #Jumlah Paket Data
int jumlahPaketData(adr_user p)
{
    int jumlah = 0;
    adr_relation r;
    r = first_relation(p);
    while (r != NULL)
    {
        jumlah++;
        r = next(r);
    }
    return jumlah;
}

// # Delete
void deleteLastRelasi(adr_user &U, adr_relation &hapus)
{
    adr_relation p = first_relation(U);
    while (next(next(p)) != NULL)
    {
        p = next(p);
    }
    hapus = next(p);
    info(p).paketdata = NULL;
    next(p) = NULL;
}

void deleteAllRelasi(adr_user &U)
{
    adr_relation hapus = first_relation(U);
    while (first_relation(U) != NULL)
    {
        deleteLastRelasi(U, hapus);
    }
}

void deleteRelasiTertentu(adr_user &U, adr_relation &hapus)
{
    if (first_relation(U) == NULL)
    {
        cout << "User belum mempunyai paket data !" << endl;
    }
    else if (first_relation(U) == hapus)
    {
        first_relation(U) = next(hapus);
        next(hapus) = NULL;
        info(hapus).paketdata = NULL;
        cout << "< Paket data milik user " << info(U).nomor << " telah dihapus >"
             << endl;
    }
    else if (next(first_relation(U)) == hapus)
    {
        next(first_relation(U)) = next(hapus);
        next(hapus) = NULL;
        info(hapus).paketdata = NULL;
        cout << "< Paket data milik user " << info(U).nomor << " telah dihapus >"
             << endl;
    }
    else
    {
        adr_relation cc, r = first_relation(U);
        while (r != NULL)
        {
            if (next(r) == hapus)
            {
                cc = r;
            }

            r = next(r);
        }
        next(cc) = next(hapus);
        next(hapus) = NULL;
        info(hapus).paketdata = NULL;
        cout << "< Paket data milik user " << info(U).nomor << " telah dihapus >"
             << endl;
    }
}

void deleteUser(user &U, adr_user &p)
{

    if (first(U) == p)
    {
        first(U) = next(p);
        deleteAllRelasi(p);
        next(p) = NULL;
        cout << "< Data user " << info(p).nomor << " telah dihapus >" << endl;
    }
    else if (next(first(U)) == p)
    {
        next(first(U)) = next(p);
        deleteAllRelasi(p);
        next(p) = NULL;
        cout << "< Data user " << info(p).nomor << " telah dihapus >" << endl;
    }
    else
    {
        adr_user cc, q = first(U);
        while (q != NULL)
        {
            if (next(q) == p)
            {
                cc = q;
            }

            q = next(q);
        }
        deleteAllRelasi(p);
        next(cc) = next(p);
        next(p) = NULL;
        cout << "< Data user " << info(p).nomor << " telah dihapus >" << endl;
    }
}
void deletePaketData(paketData &PD, user &U, adr_paketData &adrP)
{
    adr_user p = first(U);
    adr_relation q;
    adr_paketData a = adrP;
    while (p != NULL)
    {
        q = searchingRelasi(p, a);
        if (q != NULL)
        {
            deleteRelasiTertentu(p, q);
        }
        p = next(p);
    }

    if (first(PD) == adrP)
    {
        first(PD) = next(adrP);
        next(adrP) = NULL;
        cout << "< Data paket " << info(adrP).namaPaket << " telah dihapus >"
             << endl;
    }
    else if (next(first(PD)) == adrP)
    {
        next(first(PD)) = next(adrP);
        next(adrP) = NULL;
        cout << "< Data paket " << info(adrP).namaPaket << " telah dihapus >"
             << endl;
    }
    else
    {
        adr_paketData cc, firstpd = first(PD);
        while (firstpd != NULL)
        {
            if (next(firstpd) == a)
            {
                cc = firstpd;
            }

            firstpd = next(firstpd);
        }
        next(cc) = next(adrP);
        next(adrP) = NULL;
        cout << "< Data paket " << info(adrP).namaPaket << " telah dihapus >"
             << endl;
    }
}