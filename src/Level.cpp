#include "Level.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

// Constructor
Level::Level() {
    level = EASY;
}

// Chọn độ khó
void Level::chooseLevel() {
    int choice;

    cout << "Chon do kho:\n";
    cout << "1. Easy\n2. Medium\n3. Hard\n";
    cout << "Nhap: ";
    cin >> choice;

    while (choice < 1 || choice > 3) {
        cout << "Nhap lai (1-3): ";
        cin >> choice;
    }

    level = static_cast<Difficulty>(choice);
}

// Tính số ký tự cần ẩn
int Level::getHiddenCount(int length) {
    if (level == EASY) return length * 0.3;
    if (level == MEDIUM) return length * 0.5;
    return length * 0.7;
}

// Ẩn chữ trong từ
string Level::hideWord(const string& word) {
    string result = word;

    int len = result.length();
    int hideCount = getHiddenCount(len);

    set<int> positions;

    while ((int)positions.size() < hideCount) {
        int pos = rand() % len;
        positions.insert(pos);
    }

    for (int pos : positions) {
        result[pos] = '_';
    }

    return result;
}

// Thông tin level (đa hình)
void Level::info() {
    if (level == EASY) cout << "Level: Easy\n";
    else if (level == MEDIUM) cout << "Level: Medium\n";
    else cout << "Level: Hard\n";
}