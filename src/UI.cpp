#include "UI.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

// ============================================================
//  Constructor - INHERITANCE: gọi constructor lớp cha
// ============================================================
UI::UI() : GameComponent("UI"), score(0), lives(DEFAULT_LIVES) {}

// ============================================================
//  Reset
// ============================================================
void UI::reset() {
    usedLetters.clear();
}

void UI::fullReset() {
    score = 0;
    lives = DEFAULT_LIVES;
    usedLetters.clear();
}

// ============================================================
//  Menu
// ============================================================
void UI::showMenu() const {
    cout << "\n========== WORD GUESS GAME ==========\n";
    cout << "  1. Start Game\n";
    cout << "  2. Exit\n";
    cout << "======================================\n";
}

int UI::getChoice() {
    int choice;
    while (true) {
        cout << "Choose: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number!\n";
            continue;
        }
        return choice;
    }
}

// ============================================================
//  Hiển thị game
// ============================================================
void UI::showSeparator() const {
    cout << "\n--------------------\n";
}

void UI::displayWord(const string& word) const {
    cout << "Word: ";
    for (char c : word) cout << c << " ";
    cout << endl;
}

void UI::showResult(bool correct) const {
    cout << (correct ? ">>> Correct! <<<\n" : ">>> Wrong! <<<\n");
}

void UI::showScore() const {
    cout << "Score: " << score << endl;
}

void UI::showLives() const {
    cout << "Lives: " << lives << "  [";
    for (int i = 0; i < lives; i++) cout << "*";
    for (int i = lives; i < DEFAULT_LIVES; i++) cout << ".";
    cout << "]" << endl;
}

void UI::showUsedLetters() const {
    cout << "Used: ";
    if (usedLetters.empty()) {
        cout << "(none)";
    } else {
        for (char c : usedLetters) cout << c << " ";
    }
    cout << endl;
}

void UI::showGameOver(const string& word) const {
    cout << "\n===== GAME OVER =====\n";
    cout << "The word was: " << word << endl;
    cout << "Final score: " << score << endl;
    cout << "=====================\n";
}

void UI::showWin(const string& word) const {
    cout << "\n===== YOU WIN! =====\n";
    cout << "Word: " << word << endl;
    cout << "Score: " << score << endl;
    cout << "====================\n";
}

// ============================================================
//  Input
// ============================================================
char UI::getInput() {
    string input;
    cout << "Enter 1 letter: ";
    getline(cin >> ws, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    if (input.length() != 1) return '!';

    char c = tolower(static_cast<unsigned char>(input[0]));
    if (!isalpha(static_cast<unsigned char>(c))) return '!';

    return c;
}

// ============================================================
//  Logic chữ đã dùng
// ============================================================
void UI::addUsedLetter(char c) {
    c = tolower(static_cast<unsigned char>(c));
    if (isalpha(static_cast<unsigned char>(c)) && !isUsedLetter(c)) {
        usedLetters.push_back(c);
    }
}

bool UI::isUsedLetter(char c) const {
    return find(usedLetters.begin(), usedLetters.end(), c) != usedLetters.end();
}

// ============================================================
//  Thao tác điểm/mạng
// ============================================================
void UI::increaseScore(int value) {
    score += value;
}

void UI::decreaseLives() {
    if (lives > 0) lives--;
}

// ============================================================
//  POLYMORPHISM: Override info() và display()
// ============================================================
void UI::info() const {
    cout << "UI Component - Score: " << score
         << ", Lives: " << lives << endl;
}

void UI::display() const {
    cout << "=== " << componentName << " ===" << endl;
    cout << "Score: " << score << " | Lives: " << lives << endl;
    cout << "Letters used: " << usedLetters.size() << endl;
}

// ============================================================
//  OPERATOR OVERLOADING
// ============================================================

// + tạo UI mới với điểm được cộng thêm
UI UI::operator+(int points) const {
    UI result = *this;
    result.score += points;
    return result;
}

// += cộng điểm trực tiếp
UI& UI::operator+=(int points) {
    score += points;
    return *this;
}

// -- (prefix) giảm 1 mạng
UI& UI::operator--() {
    if (lives > 0) lives--;
    return *this;
}

// ++ (prefix) tăng 1 mạng (bonus)
UI& UI::operator++() {
    lives++;
    return *this;
}

// == so sánh hai UI có cùng điểm không
bool UI::operator==(const UI& other) const {
    return score == other.score;
}

// > so sánh điểm cao hơn
bool UI::operator>(const UI& other) const {
    return score > other.score;
}

// << in trạng thái UI
ostream& operator<<(ostream& os, const UI& ui) {
    os << "UI[score=" << ui.score << ", lives=" << ui.lives << "]";
    return os;
}