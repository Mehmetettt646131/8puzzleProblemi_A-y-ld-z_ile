#include "puzzle.hpp"
#include <cmath>

void yazdirPuzzle(const vector<vector<int>>& durum) {
    for (const auto& satir : durum) {
        for (int deger : satir) {
            if (deger == 0)
                cout << "  ";
            else
                cout << deger << " ";
        }
        cout << endl;
    }
    cout << "--------" << endl;
}

pair<int, int> bosBul(const vector<vector<int>>& durum) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (durum[i][j] == 0) {
                return { i, j };
            }
        }
    }
    return { -1, -1 };
}

vector<vector<int>> hareketYap(const vector<vector<int>>& durum, int x1, int y1, int x2, int y2) {
    vector<vector<int>> yeniDurum = durum;
    swap(yeniDurum[x1][y1], yeniDurum[x2][y2]);
    return yeniDurum;
}

int manhattanMesafesi(const vector<vector<int>>& durum) {
    int mesafe = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (durum[i][j] != 0) {
                int hedefX = (durum[i][j] - 1) / 3;
                int hedefY = (durum[i][j] - 1) % 3;
                mesafe += abs(i - hedefX) + abs(j - hedefY);
            }
        }
    }
    return mesafe;
}