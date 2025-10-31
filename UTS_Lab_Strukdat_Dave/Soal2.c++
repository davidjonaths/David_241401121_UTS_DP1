#include <iostream> 
#include <string>
using namespace std;

struct Node {
    string judul;
    int tahun, rating;
    Node* next;
};

void tambahBelakang(Node*& head, string judul, int tahun, int rating) {
    Node* baru = new Node{judul, tahun, rating, nullptr};
    if (!head) head = baru;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}

void hapusFilm(Node*& head, string judul) {
    if (!head) return;

    // jika yang dihapus adalah head
    if (head->judul == judul) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->judul != judul)
        temp = temp->next;

    if (!temp->next)
        cout << "Film tidak ditemukan.\n";
    else {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
    }
}

void tampil(Node* head) {
    int count = 0;
    while (head) {
        cout << head->judul << " (" << head->tahun << ") - " << head->rating << endl;
        head = head->next;
        count++;
    }
    cout << "\nTotal film tersisa: " << count << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Masukkan jumlah film awal: ";
    cin >> n;
    cin.ignore(); // buang newline sebelum getline()

    for (int i = 0; i < n; i++) {
        string j;
        int t, r;
        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        getline(cin, j);
        cout << "Tahun: ";
        cin >> t;
        cout << "Rating: ";
        cin >> r;
        cin.ignore(); // buang newline lagi
        tambahBelakang(head, j, t, r);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    cin.ignore();

    if (hapus == 'y' || hapus == 'Y') {
        string target;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, target); // 
        hapusFilm(head, target);
    }

    cout << "\nDaftar Film:\n";
    tampil(head);
}
