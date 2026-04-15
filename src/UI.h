#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UI {
private:
    int score;
    int lives;
    vector<char> usedLetters;

public:
    UI();

    void showMenu();
    int getChoice();

    void displayWord(const string& word);

    char getInput(); // 🔥 chỉ 1 chữ cái

    void showResult(bool correct);

    void showScore() const;
    void showLives() const;
    void showUsedLetters() const;

    void showGameOver(const string& word);
    void showWin(const string& word);

    void addUsedLetter(char c);
    bool isUsedLetter(char c);

    void increaseScore(int value);
    void decreaseLives();

    void reset();

    int getLives() const;
    int getScore() const;

    void info();
};