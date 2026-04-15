#include "InputHandler.h"
#include <iostream>
#include <algorithm>

using namespace std;

string InputHandler::getInput() {
    string input;
    cout << "Nhap dap an: ";
    cin >> input;
    return input;
}

bool InputHandler::checkAnswer(string input, string correct) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    transform(correct.begin(), correct.end(), correct.begin(), ::tolower);

    return input == correct;
}

void InputHandler::info() {
    cout << "Input Handler Component - Xu ly nhap va kiem tra dap an" << endl;
}