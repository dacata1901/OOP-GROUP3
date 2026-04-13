#pragma once
#include <vector>
#include <string>
#include "GameComponent.h"

using namespace std;

// Class quản lý từ vựng
class WordManager : public GameComponent {
private:
    vector<string> words; // lưu danh sách từ

public:
    // TODO: đọc file words.txt và lưu vào vector
    void loadWords(string filename);

    // TODO: trả về 1 từ random
    string getRandomWord();

    // override từ class cha
    void info() override;
};