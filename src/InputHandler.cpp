#include "InputHandler.h"
#include <iostream>

string InputHandler::getInput() {
    string input;
    cout << "Nhap dap an: ";
    cin >> input;
    return input;
}

void InputHandler::info() {
    cout << "InputHandler: nhan du lieu tu nguoi choi\n";
}
