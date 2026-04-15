#pragma once
#include <string>
#include "GameComponent.h"

// Enum độ khó
enum Difficulty
{
    EASY = 1,
    MEDIUM,
    HARD
};

// Class Level kế thừa GameComponent
class Level : public GameComponent
{
private:
    Difficulty level; // lưu độ khó hiện tại

public:
    // Constructor
    Level();

    // Cho người dùng chọn độ khó
    void chooseLevel();

    // Tính số ký tự cần ẩn dựa vào độ dài từ
    int getHiddenCount(int length);

    // Ẩn chữ trong từ
    std::string hideWord(const std::string& word);

    // Override từ GameComponent
    void info() override;
};