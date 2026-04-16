#include "InputHandler.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;


//  Constructor - INHERITANCE: gọi constructor lớp cha

InputHandler::InputHandler()
    : GameComponent("InputHandler"), lastInput('\0'), errorCount(0) {}


//  Lấy input 1 ký tự hợp lệ
char InputHandler::getChar() {
    string input;
    cout << "Nhap 1 chu cai: ";
    getline(cin >> ws, input);

    // Xóa khoảng trắng
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    if (input.length() != 1) {
        errorCount++;
        lastInput = '!';
        return '!';
    }

    char c = tolower(static_cast<unsigned char>(input[0]));

    if (!isalpha(static_cast<unsigned char>(c))) {
        errorCount++;
        lastInput = '!';
        return '!';
    }

    lastInput = c;
    return c;
}

// ============================================================
//  Kiểm tra đáp án
// ============================================================
bool InputHandler::checkAnswer(const string& input, const string& correct) const {
    string a = input, b = correct;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a == b;
}

// ============================================================
//  POLYMORPHISM: Override info() và display()
// ============================================================
void InputHandler::info() const {
    cout << "InputHandler: lastInput='" << lastInput
         << "', errors=" << errorCount << endl;
}

void InputHandler::display() const {
    cout << "=== " << componentName << " ===" << endl;
    cout << "Input cuoi: '" << lastInput << "'" << endl;
    cout << "So loi:     " << errorCount << endl;
}

// ============================================================
//  OPERATOR OVERLOADING
// ============================================================

// == kiểm tra lastInput có bằng ký tự c không
bool InputHandler::operator==(char c) const {
    return lastInput == tolower(static_cast<unsigned char>(c));
}

// != kiểm tra lastInput khác ký tự c
bool InputHandler::operator!=(char c) const {
    return !(*this == c);
}

// << in thông tin InputHandler
ostream& operator<<(ostream& os, const InputHandler& ih) {
    os << "InputHandler[last='" << ih.lastInput
       << "', errors=" << ih.errorCount << "]";
    return os;
}