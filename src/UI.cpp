#include "UI.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

// ===== CONSTRUCTOR =====
UI::UI() {
    score = 0;
    lives = 5;
}

// ===== RESET =====
void UI::reset() {
    score = 0;
    lives = 5;
    usedLetters.clear();
}

// ===== MENU =====
void UI::showMenu() {
    cout << "\n========== WORD GUESS GAME ==========\n";
    cout << "1. Start Game\n";
    cout << "2. Exit\n";
    cout << "====================================\n";
}

int UI::getChoice() {
    int choice;
    cout << "Choose: ";
    cin >> choice;
    return choice;
}

// ===== DISPLAY WORD =====
void UI::displayWord(const string& word) {
    cout << "\nWord: ";
    for (char c : word) cout << c << " ";
    cout << endl;
}

// ===== INPUT (CHỈ 1 CHỮ CÁI) =====
char UI::getInput() {
    string input;

    while (true) {
        cout << "Enter 1 letter: ";
        cin >> input;

        if (input.length() != 1) {
            cout << "Chi duoc nhap 1 chu cai!\n";
            continue;
        }

        char c = tolower(input[0]);

        if (!isalpha(c)) {
            cout << "Chi duoc nhap chu cai a-z!\n";
            continue;
        }

        return c;
    }
}

// ===== RESULT =====
void UI::showResult(bool correct) {
    cout << (correct ? "Correct!\n" : "Wrong!\n");
}

// ===== SCORE =====
void UI::showScore() const {
    cout << "Score: " << score << endl;
}

// ===== LIVES =====
void UI::showLives() const {
    cout << "Lives: " << lives << endl;
}

// ===== USED LETTERS =====
void UI::showUsedLetters() const {
    cout << "Used letters: ";
    for (char c : usedLetters) cout << c << " ";
    cout << endl;
}

// ===== GAME OVER =====
void UI::showGameOver(const string& word) {
    cout << "\n===== GAME OVER =====\n";
    cout << "Correct word: " << word << endl;
}

// ===== WIN =====
void UI::showWin(const string& word) {
    cout << "\n===== YOU WIN =====\n";
    cout << "Word: " << word << endl;
}

// ===== LOGIC =====
void UI::addUsedLetter(char c) {
    if (!isUsedLetter(c)) {
        usedLetters.push_back(c);
    }
}

bool UI::isUsedLetter(char c) {
    return find(usedLetters.begin(), usedLetters.end(), c) != usedLetters.end();
}

void UI::increaseScore(int value) {
    score += value;
}

void UI::decreaseLives() {
    lives--;
}

// ===== GETTER =====
int UI::getLives() const {
    return lives;
}

int UI::getScore() const {
    return score;
}

void UI::info() {
    cout << "UI Component\n";
}