#pragma once
#include <string>
#include "GameComponent.h"

using namespace std;

// Class hiển thị giao diện
class UI : public GameComponent {
public:
    // TODO: hiển thị menu
    void showMenu();

    // TODO: hiển thị từ bị ẩn
    void displayWord(string word);

    // TODO: thông báo đúng/sai
    void showResult(bool correct);

    void info() override;
};