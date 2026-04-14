#pragma once
#include <string>
#include "GameComponent.h"

using namespace std;

// Class UI kế thừa từ GameComponent
// Chịu trách nhiệm hiển thị và tương tác với người dùng
class UI : public GameComponent {
public:
    // ===== MENU =====
    void showMenu();

    // ===== HIỂN THỊ TỪ =====
    // word dạng: "_ p p _ e"
    void displayWord(string word);

    // ===== THÔNG BÁO ĐÚNG / SAI =====
    void showResult(bool correct);

    // ===== NHẬP KÝ TỰ =====
    char getInput();

    // ===== HIỂN THỊ ĐIỂM =====
    void showScore(int score);

    // ===== KẾT THÚC GAME =====
    void showGameOver(string word);

    // ===== ĐA HÌNH (override) =====
    void info() override;
};