#pragma once
#include "WordManager.h"
#include "Level.h"
#include "InputHandler.h"
#include "UI.h"


//  Game: class điều phối toàn bộ - KHÔNG kế thừa GameComponent
//  vì Game là controller, không phải một "thành phần" game

class Game {
private:
    WordManager  wordManager;
    Level        level;
    InputHandler inputHandler;
    UI           ui;

    // ENCAPSULATION: private helper methods
    bool playRound();       // Chơi 1 ván

public:
    Game();
    void run();
};