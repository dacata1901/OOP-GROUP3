#include "Level.h"
#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;


//  Constructor - INHERITANCE: gọi constructor lớp cha

Level::Level() : GameComponent("Level"), difficulty(EASY), hiddenRatio(0.3f) {}


//  ENCAPSULATION: private helper - cập nhật tỉ lệ ẩn

void Level::updateRatio() {
    if (difficulty == EASY)        hiddenRatio = 0.3f;
    else if (difficulty == MEDIUM) hiddenRatio = 0.5f;
    else                           hiddenRatio = 0.7f;
}


//  Public methods

void Level::chooseLevel() {
    int choice;
    cout << "\nChoose difficulty:\n";
    cout << "  1. Easy   (hide 30% of letters)\n";
    cout << "  2. Medium (hide 50% of letters)\n";
    cout << "  3. Hard   (hide 70% of letters)\n";
    cout << "Enter: ";
    cin >> choice;

    while (choice < 1 || choice > 3) {
        cout << "Please enter a valid option (1-3): ";
        cin >> choice;
    }

    difficulty = static_cast<Difficulty>(choice);
    updateRatio();
}

int Level::getHiddenCount(int length) const {
    return static_cast<int>(length * hiddenRatio);
}

string Level::getDifficultyName() const {
    if (difficulty == EASY)   return "Easy";
    if (difficulty == MEDIUM) return "Medium";
    return "Hard";
}

string Level::hideWord(const string& word) const {
    string result = word;
    int len = result.length();
    int hideCount = getHiddenCount(len);

    set<int> positions;
    while ((int)positions.size() < hideCount) {
        positions.insert(rand() % len);
    }
    for (int pos : positions) {
        result[pos] = '_';
    }
    return result;
}


//  POLYMORPHISM: Override info() và display()

void Level::info() const {
    cout << "Level Component - Current difficulty: " << getDifficultyName()
         << " (hiding " << static_cast<int>(hiddenRatio * 100) << "% of letters)" << endl;
}

void Level::display() const {
    cout << "=== " << componentName << " ===" << endl;
    cout << "Difficulty: " << getDifficultyName() << endl;
    cout << "Hidden ratio: " << static_cast<int>(hiddenRatio * 100) << "%" << endl;
}


//  OPERATOR OVERLOADING

// < so sánh độ khó
bool Level::operator<(const Level& other) const {
    return difficulty < other.difficulty;
}

// > so sánh độ khó
bool Level::operator>(const Level& other) const {
    return difficulty > other.difficulty;
}

// == so sánh độ khó bằng nhau
bool Level::operator==(const Level& other) const {
    return difficulty == other.difficulty;
}

// ++ (prefix) tăng độ khó lên 1 bậc
Level& Level::operator++() {
    if (difficulty == EASY)        difficulty = MEDIUM;
    else if (difficulty == MEDIUM) difficulty = HARD;
    updateRatio();
    return *this;
}

// << in thông tin level ra ostream
ostream& operator<<(ostream& os, const Level& lv) {
    os << "Level[" << lv.getDifficultyName() << ", hidden="
       << static_cast<int>(lv.hiddenRatio * 100) << "%]";
    return os;
}