#include "UI.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

// ===== CONSTRUCTOR =====
UI::UI() {
    score = 0;
    lives = 5;
}

// ===== RESET =====
void UI::reset() {
    usedLetters.clear();
}

// ===== MENU =====
void UI::showMenu() {
    cout << "\n========== WORD GUESS GAME ==========\n";
    cout << "1. Start Game\n";
    cout << "2. Exit\n";
    cout << "====================================\n";
}

// ===== CHOICE =====
int UI::getChoice() {
    int choice;

    while (true) {
        cout << "Choose: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap so hop le!\n";
            continue;
        }

        return choice;
    }
}

// ===== DISPLAY WORD =====
void UI::displayWord(const string& word) {
    cout << "\nWord: ";
    for (char c : word) cout << c << " ";
    cout << endl;
}

// ===== INPUT STRICT =====
char UI::getInput() {
    string input;

    cout << "Enter 1 letter: ";
    getline(cin >> ws, input);

    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    if (input.length() != 1) {
        return '!';
    }

    char c = tolower(input[0]);

    if (!isalpha(static_cast<unsigned char>(c))) {
        return '!';
    }

    return c;
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

    for (char c : usedLetters) {
        cout << c << " ";
    }

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
    c = tolower(c);

    if (isalpha(static_cast<unsigned char>(c)) && !isUsedLetter(c)) {
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

// ===== RESET STATE GETTERS =====
int UI::getLives() const {
    return lives;
}

int UI::getScore() const {
    return score;
}

void UI::info() {
    cout << "UI Component\n";
}