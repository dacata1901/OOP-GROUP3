#pragma once
#include <string>
#include "GameComponent.h"

// Class xử lý input
class InputHandler : public GameComponent {
public:
    std::string getInput();
    bool checkAnswer(std::string input, std::string correct);
    void info() override;
};
