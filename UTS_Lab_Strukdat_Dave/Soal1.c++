#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Pasien {
    string nama;
    string jenis;
    int umur;
    int darurat;
    int urutanDatang;
};

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Input tidak valid! Masukkan angka lebih dari 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<Pasien> antrean;

    for (int i = 0; i < n; i++) {
        Pasien p;
        cout << "\nPasien " << i + 1 << ":\n";

        cout << "Nama hewan: ";
        cin >> p.nama;

        cout << "Jenis hewan: ";
        cin >> p.jenis;

        // Input umur dengan validasi
        cout << "Umur: ";
        while (!(cin >> p.umur)) {
            cout << "Input tidak valid! Masukkan angka untuk umur: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buang sisa input

        // Input tingkat darurat dengan validasi dan pembersihan buffer
        cout << "Tingkat darurat (1-5): ";
        while (!(cin >> p.darurat) || p.darurat < 1 || p.darurat > 5) {
            cout << "Input tidak valid! Masukkan angka antara 1 - 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buang newline

        p.urutanDatang = i;
        antrean.push_back(p);
    }

    // Urutkan: darurat tertinggi dulu, kalau sama -> urutan datang
    sort(antrean.begin(), antrean.end(), [](const Pasien &a, const Pasien &b) {
        if (a.darurat == b.darurat)
            return a.urutanDatang < b.urutanDatang;
        return a.darurat > b.darurat;
    });

    cout << "\n=== DAFTAR PENANGANAN ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << antrean[i].nama
             << " (" << antrean[i].umur << " tahun)"
             << " - Darurat " << antrean[i].darurat << endl;
    }

    cout << "\nSemua pasien telah diurutkan berdasarkan tingkat darurat!\n";
    return 0;
}
