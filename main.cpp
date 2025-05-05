#include "puzzle.hpp"
#include "cozum.hpp"
#include <iostream>

int main() {
    vector<vector<int>> baslangicDurumu = { {6, 2, 8},
                                           {4, 7, 1},
                                           {0, 3, 5} };

    cout << "Baslangic Durumu:" << endl;
    yazdirPuzzle(baslangicDurumu);

    vector<string> cozum = cozPuzzle(baslangicDurumu);
    if (cozum.empty()) {
        cout << "Cozum bulunamadi!" << endl;
    }
    else {
        cout << "Cozum " << cozum.size() << " adimda bulundu:" << endl;
        vector<vector<int>> mevcutDurum = baslangicDurumu;
        for (const string& hareket : cozum) {
            cout << "Hareket: " << hareket << endl;
            pair<int, int> bosKonum = bosBul(mevcutDurum);
            int x = bosKonum.first, y = bosKonum.second;

            if (hareket == "YUKARI") {
                mevcutDurum = hareketYap(mevcutDurum, x, y, x - 1, y);
            }
            else if (hareket == "ASAGI") {
                mevcutDurum = hareketYap(mevcutDurum, x, y, x + 1, y);
            }
            else if (hareket == "SOL") {
                mevcutDurum = hareketYap(mevcutDurum, x, y, x, y - 1);
            }
            else if (hareket == "SAG") {
                mevcutDurum = hareketYap(mevcutDurum, x, y, x, y + 1);
            }
            yazdirPuzzle(mevcutDurum);
        }
        cout << "Basarili sekilde sonuca ulasildi!" << endl;
    }

    return 0;
}