#include "cozum.hpp"
#include "puzzle.hpp"
#include <queue>
#include <unordered_set>
#include <memory>
#include <algorithm>

const vector<vector<int>> HEDEF = { {1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 0} };

struct Dugum {
    vector<vector<int>> durum;
    int g, h;
    shared_ptr<Dugum> ebeveyn;
    string hareket;

    Dugum(vector<vector<int>> d, int g_deger, int h_deger, shared_ptr<Dugum> e = nullptr, string h = "")
        : durum(d), g(g_deger), h(h_deger), ebeveyn(e), hareket(h) {
    }

    int f() const {
        return g + h;
    }

    bool operator>(const Dugum& diger) const {
        return f() > diger.f();
    }
};

vector<string> cozPuzzle(const vector<vector<int>>& baslangicDurumu) {
    auto cmp = [](shared_ptr<Dugum> a, shared_ptr<Dugum> b) { return *a > *b; };
    priority_queue<shared_ptr<Dugum>, vector<shared_ptr<Dugum>>, decltype(cmp)> acikListe(cmp);
    unordered_set<string> kapaliListe;

    shared_ptr<Dugum> baslangicDugumu = make_shared<Dugum>(baslangicDurumu, 0, manhattanMesafesi(baslangicDurumu));
    acikListe.push(baslangicDugumu);

    while (!acikListe.empty()) {
        shared_ptr<Dugum> mevcutDugum = acikListe.top();
        acikListe.pop();

        if (mevcutDugum->durum == HEDEF) {
            vector<string> cozum;
            while (mevcutDugum->ebeveyn != nullptr) {
                cozum.push_back(mevcutDugum->hareket);
                mevcutDugum = mevcutDugum->ebeveyn;
            }
            reverse(cozum.begin(), cozum.end());
            return cozum;
        }

        pair<int, int> bosKonum = bosBul(mevcutDugum->durum);
        int x = bosKonum.first, y = bosKonum.second;

        vector<pair<int, int>> hareketler = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        string hareketStr[] = { "YUKARI", "ASAGI", "SOL", "SAG" };

        for (int i = 0; i < 4; ++i) {
            int yeniX = x + hareketler[i].first, yeniY = y + hareketler[i].second;
            if (yeniX >= 0 && yeniX < 3 && yeniY >= 0 && yeniY < 3) {
                vector<vector<int>> yeniDurum = hareketYap(mevcutDugum->durum, x, y, yeniX, yeniY);

                string durumStr = "";
                for (const auto& satir : yeniDurum) {
                    for (int deger : satir) {
                        durumStr += to_string(deger) + ",";
                    }
                }
                if (kapaliListe.find(durumStr) != kapaliListe.end()) {
                    continue;
                }

                shared_ptr<Dugum> yeniDugum = make_shared<Dugum>(yeniDurum, mevcutDugum->g + 1, manhattanMesafesi(yeniDurum), mevcutDugum, hareketStr[i]);
                acikListe.push(yeniDugum);
                kapaliListe.insert(durumStr);
            }
        }
    }

    return {};
}