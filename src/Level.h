#pragma once
#include <string>
#include "GameComponent.h"

using namespace std;

// Class xử lý độ khó
class Level : public GameComponent {
private:
    int level; // 1: Easy, 2: Medium, 3: Hard

public:
    // TODO: cho người dùng chọn level
    void chooseLevel();

    // TODO: ẩn chữ theo level
    string hideWord(string word);

    void info() override;
};