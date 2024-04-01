#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Book {
    string title;
    string description;
    string publisher;
    int year;
    string ISBN;
};


vector<string> splitWords(const string &str) {
    vector<string> words;
    string word;
    for (char c : str) {
        if (isspace(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

int main() {
    vector<Book> library; 
    vector<vector<string>> tags; 

    while (true) {
        int choice;
        cout << "\nMenu:\n1. Tambah Informasi Buku\n2. Cari Informasi Buku\n3. Keluar\nPilihan Anda: ";
        cin >> choice;

        if (choice == 1) {
            Book newBook;
            cout << "Nama Buku: ";
            cin.ignore();
            getline(cin, newBook.title);
            cout << "Deskripsi Buku: ";
            getline(cin, newBook.description);
            cout << "Penerbit: ";
            getline(cin, newBook.publisher);
            cout << "Tahun Terbit: ";
            cin >> newBook.year;
            cout << "ISBN: ";
            cin.ignore();
            getline(cin, newBook.ISBN);

            library.push_back(newBook); 

            
            vector<string> bookTags;
            vector<string> words = splitWords(newBook.title);
            for (const string &word : words) {
                bookTags.push_back(word);
            }
            tags.push_back(bookTags);
        } else if (choice == 2) {
            string keyword;
            cout << "Masukkan kata kunci: ";
            cin.ignore();
            getline(cin, keyword);

            
            vector<string> keywords = splitWords(keyword);

            
            cout << "\nHasil Pencarian:\n";
            bool found = false;
            for (size_t i = 0; i < tags.size(); ++i) {
                bool allFound = true;
                for (const string &kw : keywords) {
                    if (find(tags[i].begin(), tags[i].end(), kw) == tags[i].end()) {
                        allFound = false;
                        break;
                    }
                }
                if (allFound) {
                    found = true;
                    cout << "Nama Buku: " << library[i].title << endl;
                    cout << "Deskripsi Buku: " << library[i].description << endl;
                    cout << "Penerbit: " << library[i].publisher << endl;
                    cout << "Tahun Terbit: " << library[i].year << endl;
                    cout << "ISBN: " << library[i].ISBN << endl << endl;
                }
            }
            if (!found) {
                cout << "Buku tidak ditemukan.\n";
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }

    return 0;
}
