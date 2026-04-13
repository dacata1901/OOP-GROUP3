#pragma once
#include <string>
#include "GameComponent.h"

using namespace std;

// Class xử lý input
class InputHandler : public GameComponent {
public:
    // TODO: nhập từ người chơi
    string getInput();

    // TODO: so sánh với từ gốc
    bool checkAnswer(string input, string correct);

    void info() override;
};