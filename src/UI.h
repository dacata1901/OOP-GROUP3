#pragma once
#include <string>
#include <vector>
#include "GameComponent.h"

// Class UI kế thừa từ GameComponent
// Chịu trách nhiệm hiển thị và tương tác với người dùng
class UI : public GameComponent {
private:
    int score;                  // điểm
    int lives;                  // số mạng
    std::vector<char> usedLetters; // các chữ đã nhập

public:
    // ===== CONSTRUCTOR =====
    UI();

    // ===== MENU =====
    void showMenu();
    int getChoice();

    // ===== HIỂN THỊ WORD =====
    void displayWord(const std::string& word);

    // ===== INPUT =====
    char getInput();

    // ===== RESULT =====
    void showResult(bool correct);

    // ===== SCORE & LIVES =====
    void showScore() const;
    void showLives() const;

    // ===== USED LETTERS =====
    void showUsedLetters() const;

    // ===== GAME STATE =====
    void showGameOver(const std::string& word);
    void showWin(const std::string& word);

    // ===== LOGIC =====
    void addUsedLetter(char c);
    void increaseScore(int value);
    void decreaseLives();

    // ===== GETTER =====
    int getScore() const;
    int getLives() const;

    // ===== ĐA HÌNH =====
    void info() override;
};