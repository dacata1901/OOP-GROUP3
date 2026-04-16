#pragma once
#include "GameComponent.h"
#include <string>


//  INHERITANCE: InputHandler kế thừa từ GameComponent
//  ENCAPSULATION: lastInput, errorCount là private

class InputHandler : public GameComponent {
private:
    char lastInput;     // Lưu input gần nhất (encapsulation)
    int  errorCount;    // Đếm số lần nhập sai (encapsulation)

public:
    InputHandler();

    // Lấy input 1 ký tự từ người dùng, trả '!' nếu không hợp lệ
    char getChar();

    // Kiểm tra đáp án
    bool checkAnswer(const std::string& input, const std::string& correct) const;

    // Getters - ENCAPSULATION
    char getLastInput() const  { return lastInput; }
    int  getErrorCount() const { return errorCount; }
    void resetErrors()         { errorCount = 0; }

    // POLYMORPHISM: override từ GameComponent
    void info() const override;
    void display() const override;

    // OPERATOR OVERLOADING: == kiểm tra input có bằng một ký tự không
    bool operator==(char c) const;

    // OPERATOR OVERLOADING: != kiểm tra input khác một ký tự
    bool operator!=(char c) const;

    // OPERATOR OVERLOADING: << in thông tin InputHandler
    friend std::ostream& operator<<(std::ostream& os, const InputHandler& ih);
};