#include "Level.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

Level::Level() {
    level = EASY; 
    srand(time(0)); 
}


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

    level = (Difficulty)choice;
}


int Level::getHiddenCount(int length) {
    if (level == EASY) return length * 0.3;
    if (level == MEDIUM) return length * 0.5;
    return length * 0.7;
}


string Level::hideWord(string word) {
    int len = word.length();
    int hideCount = getHiddenCount(len);

    set<int> positions; 

    while (positions.size() < hideCount) {
        int pos = rand() % len;
        positions.insert(pos);
    }

    for (int pos : positions) {
        word[pos] = '_';
    }

    return word;
}


void Level::info() {
    if (level == EASY) cout << "Level: Easy\n";
    else if (level == MEDIUM) cout << "Level: Medium\n";
    else cout << "Level: Hard\n";
}