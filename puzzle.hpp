#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <vector>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

void yazdirPuzzle(const vector<vector<int>>& durum);
pair<int, int> bosBul(const vector<vector<int>>& durum);
vector<vector<int>> hareketYap(const vector<vector<int>>& durum, int x1, int y1, int x2, int y2);
int manhattanMesafesi(const vector<vector<int>>& durum);

#endif