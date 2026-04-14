#pragma once
#include <string>
#include "GameComponent.h"
using namespace std;

class InputHandler : public GameComponent {
public:
    string getInput();
    void info() override;
};
