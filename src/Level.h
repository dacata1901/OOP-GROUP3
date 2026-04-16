#pragma once
#include "GameComponent.h"
#include <string>


//  Enum độ khó

enum Difficulty {
    EASY   = 1,
    MEDIUM = 2,
    HARD   = 3
};


//  INHERITANCE: Level kế thừa từ GameComponent
//  ENCAPSULATION: difficulty, hiddenRatio là private

class Level : public GameComponent {
private:
    Difficulty difficulty;
    float hiddenRatio;      // Tỉ lệ ký tự bị ẩn (private - encapsulation)

    // ENCAPSULATION: private helper
    void updateRatio();

public:
    Level();

    void chooseLevel();
    int getHiddenCount(int length) const;
    std::string hideWord(const std::string& word) const;

    // Getters - ENCAPSULATION
    Difficulty getDifficulty() const { return difficulty; }
    float getHiddenRatio() const     { return hiddenRatio; }
    std::string getDifficultyName() const;

    // POLYMORPHISM: override từ GameComponent
    void info() const override;
    void display() const override;

    // OPERATOR OVERLOADING: < so sánh độ khó
    bool operator<(const Level& other) const;

    // OPERATOR OVERLOADING: > so sánh độ khó
    bool operator>(const Level& other) const;

    // OPERATOR OVERLOADING: == so sánh độ khó bằng nhau
    bool operator==(const Level& other) const;

    // OPERATOR OVERLOADING: ++ tăng độ khó lên 1 bậc (prefix)
    Level& operator++();

    // OPERATOR OVERLOADING: << in thông tin level
    friend std::ostream& operator<<(std::ostream& os, const Level& lv);
};