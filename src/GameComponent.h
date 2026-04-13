#pragma once
#include <iostream>

// Lớp cha dùng chung cho các thành phần trong game
// Các class như WordManager, Level, InputHandler, UI sẽ kế thừa từ đây
class GameComponent {
public:

    // Hàm ảo dùng để thể hiện đa hình
    // Mỗi class con sẽ ghi đè (override) hàm này
    virtual void info() {
        std::cout << "Game Component" << std::endl;
    }

    // Destructor ảo để đảm bảo giải phóng bộ nhớ đúng khi dùng con trỏ
    virtual ~GameComponent() {}
};