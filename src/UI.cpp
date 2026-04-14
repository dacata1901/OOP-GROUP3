#include <UI.h>
#include <iostream>
#include <algorithm>
using namespace std;

// ===== CONSTRUCTOR =====
UI::UI() {
    score = 0;
    lives = 5;
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

// ===== HIỂN THỊ WORD =====
void UI::displayWord(const string& word) {
    cout << "\nWord: ";
    for (char c : word) {
        cout << c << " ";
    }
    cout << endl;
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
    for (char c : usedLetters) {
        cout << c << " ";
    }
    cout << endl;
}

// ===== INPUT =====
char UI::getInput() {
    char c;
    cout << "Enter a letter: ";
    cin >> c;
    return tolower(c);
}

// ===== RESULT =====
void UI::showResult(bool correct) {
    if (correct) {
        cout << "[✔] Correct!\n";
    } else {
        cout << "[✘] Wrong!\n";
    }
}

// ===== GAME OVER =====
void UI::showGameOver(const string& word) {
    cout << "\n💀 GAME OVER 💀\n";
    cout << "Correct word: " << word << endl;
}

// ===== WIN =====
void UI::showWin(const string& word) {
    cout << "\n🎉 YOU WIN 🎉\n";
    cout << "Word: " << word << endl;
}

// ===== LOGIC =====
void UI::addUsedLetter(char c) {
    if (find(usedLetters.begin(), usedLetters.end(), c) == usedLetters.end()) {
        usedLetters.push_back(c);
    }
}

void UI::increaseScore(int value) {
    score += value;
}

void UI::decreaseLives() {
    lives--;
}

// ===== GETTER =====
int UI::getScore() const {
    return score;
}

int UI::getLives() const {
    return lives;
}

// ===== INFO =====
void UI::info() {
    cout << "UI Component: Display + User Interaction (OOP)\n";
}