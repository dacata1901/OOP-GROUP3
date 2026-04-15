#pragma once

// Include các class sẽ sử dụng
#include "WordManager.h"
#include "Level.h"
#include "InputHandler.h"
#include "UI.h"

// Class điều khiển toàn bộ game
// Đây là nơi kết nối tất cả các thành phần lại với nhau
class Game {
private:
    WordManager wordManager;   // quản lý từ vựng
    Level level;               // xử lý độ khó
    InputHandler inputHandler; // xử lý input
    UI ui;                     // giao diện

public:
    // Constructor
    Game();

    // Hàm chạy game chính
    void run();
};