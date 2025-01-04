
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pengeluaran {
    string kategori;
    double jumlah;
};

int main() {
    double saldoAwal, sisaSaldo, totalPengeluaran = 0;
    std::vector<Pengeluaran> daftarPengeluaran;
    int pilihan;

    
    cout << "Selamat datang di aplikasi KeuanganHarian!\n";
    cout << "Masukkan saldo awal Anda: ";
    cin >> saldoAwal;
    sisaSaldo = saldoAwal;

    do {
        
        cout << "\nMenu Utama:\n";
        cout << "1. Tambah Pengeluaran\n";
        cout << "2. Tampilkan Total Pengeluaran\n";
        cout << "3. Tampilkan Sisa Saldo\n";
        cout << "4. Keluar dari Aplikasi\n";
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                
                Pengeluaran pengeluaranBaru;
                cout << "\nMasukkan kategori pengeluaran: ";
                cin.ignore(); 
                getline(cin, pengeluaranBaru.kategori);
                cout << "Masukkan jumlah pengeluaran: ";
                cin >> pengeluaranBaru.jumlah;

                if (pengeluaranBaru.jumlah > sisaSaldo) {
                    cout << "Saldo tidak mencukupi untuk pengeluaran ini.\n";
                } else {
                    daftarPengeluaran.push_back(pengeluaranBaru);
                    totalPengeluaran += pengeluaranBaru.jumlah;
                    sisaSaldo -= pengeluaranBaru.jumlah;
                    cout << "Pengeluaran berhasil ditambahkan.\n";
                }
                break;
            }
            case 2:
                cout << "\nTotal Pengeluaran: " << totalPengeluaran << "\n";
                break;

            case 3:
        
                cout << "\nSisa Saldo: " << sisaSaldo << "\n";
                break;

            case 4:
                
                cout << "\nTerima kasih telah menggunakan aplikasi KeuanganHarian. Selamat tinggal!\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 4);

    return 0;
}