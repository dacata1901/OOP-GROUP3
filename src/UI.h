#pragma once
#include "GameComponent.h"
#include <string>
#include <vector>
#include <limits>

//  INHERITANCE: UI kế thừa từ GameComponent
//  ENCAPSULATION: score, lives, usedLetters là private

class UI : public GameComponent {
private:
    int score;                      // Điểm số (private)
    int lives;                      // Số mạng (private)
    std::vector<char> usedLetters;  // Các chữ đã dùng (private)

    static const int DEFAULT_LIVES = 5;  // Hằng số mặc định

public:
    UI();

    // Reset trạng thái cho ván mới
    void reset();
    void fullReset();  // reset cả score và lives

    // Menu
    void showMenu() const;
    int  getChoice();

    // Hiển thị game
    void displayWord(const std::string& word) const;
    void showResult(bool correct) const;
    void showScore() const;
    void showLives() const;
    void showUsedLetters() const;
    void showGameOver(const std::string& word) const;
    void showWin(const std::string& word) const;
    void showSeparator() const;

    // Input
    char getInput();

    // Logic chữ đã dùng
    void addUsedLetter(char c);
    bool isUsedLetter(char c) const;

    // Thao tác điểm/mạng
    void increaseScore(int value);
    void decreaseLives();

    // Getters - ENCAPSULATION
    int getLives() const  { return lives; }
    int getScore() const  { return score; }

    // Setters - ENCAPSULATION
    void setLives(int l)  { lives = l; }
    void setScore(int s)  { score = s; }

    // POLYMORPHISM: override từ GameComponent
    void info() const override;
    void display() const override;

    // OPERATOR OVERLOADING: + cộng thêm điểm, trả UI mới
    UI operator+(int points) const;

    // OPERATOR OVERLOADING: += cộng điểm trực tiếp
    UI& operator+=(int points);

    // OPERATOR OVERLOADING: -- giảm 1 mạng (prefix)
    UI& operator--();

    // OPERATOR OVERLOADING: ++ tăng 1 mạng (prefix)  
    UI& operator++();

    // OPERATOR OVERLOADING: == so sánh hai UI có cùng điểm không
    bool operator==(const UI& other) const;

    // OPERATOR OVERLOADING: > so sánh điểm
    bool operator>(const UI& other) const;

    // OPERATOR OVERLOADING: << in trạng thái UI
    friend std::ostream& operator<<(std::ostream& os, const UI& ui);
};