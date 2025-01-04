#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float nilaiAkhir;
};


void tambahDataMahasiswa(vector<Mahasiswa>& dataMahasiswa) {
    Mahasiswa mhs;
    cout << "Masukkan NIM: ";
    cin >> mhs.nim;
    cout << "Masukkan Nama: ";
    cin.ignore(); // Mengabaikan newline yang tersisa
    getline(cin, mhs.nama);
    cout << "Masukkan Nilai Akhir: ";
    cin >> mhs.nilaiAkhir;
    dataMahasiswa.push_back(mhs);
}


void tampilkanSemuaData(const vector<Mahasiswa>& dataMahasiswa) {
    cout << "\n=== Data Mahasiswa ===\n";
    for (const auto& mhs : dataMahasiswa) {
        cout << "NIM: " << mhs.nim << ", Nama: " << mhs.nama 
             << ", Nilai Akhir: " << mhs.nilaiAkhir << endl;
    }
}


Mahasiswa* cariMahasiswa(const vector<Mahasiswa>& dataMahasiswa, const string& nim) {
    for (auto& mhs : dataMahasiswa) {
        if (mhs.nim == nim) {
            return const_cast<Mahasiswa*>(&mhs); 
            
        }
    }
    return nullptr; 
}


void urutkanData(vector<Mahasiswa>& dataMahasiswa) {
    int n = dataMahasiswa.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dataMahasiswa[j].nilaiAkhir < dataMahasiswa[j + 1].nilaiAkhir) {
                swap(dataMahasiswa[j], dataMahasiswa[j + 1]);
            }
        }
    }
}


void simpanDataKeBerkas(const vector<Mahasiswa>& dataMahasiswa, const string& namaBerkas) {
    ofstream berkas(namaBerkas);
    if (berkas.is_open()) {
        for (const auto& mhs : dataMahasiswa) {
            berkas << mhs.nim << "," << mhs.nama << "," << mhs.nilaiAkhir << endl;
        }
        berkas.close();
        cout << "Data mahasiswa berhasil disimpan ke dalam berkas " << namaBerkas << endl;
    } else {
        cout << "Gagal membuka berkas untuk menyimpan data." << endl;
    }
}


void bacaDataDariBerkas(vector<Mahasiswa>& dataMahasiswa, const string& namaBerkas) {
    ifstream berkas(namaBerkas);
    if (berkas.is_open()) {
        Mahasiswa mhs;
        string line;
        while (getline(berkas, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            mhs.nim = line.substr(0, pos1);
            mhs.nama = line.substr(pos1 + 1, pos2 - pos1 - 1);
            mhs.nilaiAkhir = stof(line.substr(pos2 + 1));
            dataMahasiswa.push_back(mhs);
        }
        berkas.close();
        cout << "Data mahasiswa berhasil dibaca dari berkas " << namaBerkas << endl;
    } else {
        cout << "Gagal membuka berkas untuk membaca data." << endl;
    }
}

int main() {
    vector<Mahasiswa> dataMahasiswa;
    int pilihan;

    do {
        cout << "\n=== Menu Pengelolaan Data Mahasiswa ===\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data Mahasiswa (berdasarkan NIM)\n";
        cout << "4. Urutkan Data (berdasarkan Nilai Akhir)\n";
        cout << "5. Simpan Data ke Berkas\n";
        cout << "6. Baca Data dari Berkas\n";
        cout << "7. Keluar\n";
        
        cout << "Pilih opsi (1-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahDataMahasiswa(dataMahasiswa);
                break;

            case 2:
                tampilkanSemuaData(dataMahasiswa);
                break;

            case 3: {
                string nim;
                cout << "Masukkan NIM yang dicari: ";
                cin >> nim;
                Mahasiswa* hasil = cariMahasiswa(dataMahasiswa, nim);
                if (hasil) {
                    cout << "Data Mahasiswa Ditemukan:\n";
                    cout << "NIM: " << hasil->nim 
                         << ", Nama: " << hasil->nama 
                         << ", Nilai Akhir: " << hasil->nilaiAkhir 
                         << endl;
                } else {
                    cout << "Data mahasiswa dengan NIM tersebut tidak ditemukan.\n";
                }
                break;
            }

            case 4:
                urutkanData(dataMahasiswa);
                cout << "Data mahasiswa berhasil diurutkan berdasarkan Nilai Akhir.\n";
                break;

            case 5: {
                string namaBerkas;
                cout << "Masukkan nama berkas untuk menyimpan data: ";
                cin >> namaBerkas;
                simpanDataKeBerkas(dataMahasiswa, namaBerkas);
                break;
            }

            case 6: {
                string namaBerkas;
                cout << "Masukkan nama berkas untuk membaca data: ";
                cin >> namaBerkas;
                bacaDataDariBerkas(dataMahasiswa, namaBerkas);
                break;
            }

            case 7:
                cout << "Terima kasih! Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan pilih opsi yang benar.\n";
        }

    } while (pilihan != 7);

    return 0;
}