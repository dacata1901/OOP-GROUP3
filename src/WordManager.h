#pragma once
#include "GameComponent.h"
#include <string>
#include <vector>
#include <set>

// ============================================================
//  INHERITANCE: WordManager kế thừa từ GameComponent
//  ENCAPSULATION: words, usedIndexes là private
// ============================================================
class WordManager : public GameComponent {
private:
    std::vector<std::string> words;
    std::set<int> usedIndexes;

    bool isValidWord(const std::string& word) const;
    std::string normalizeWord(const std::string& word) const;

public:
    WordManager();

    bool loadWords(const std::string& filename);
    bool isEmpty() const;
    int getWordCount() const;
    void clearWords();
    std::string getRandomWord();
    std::string getUnusedRandomWord();
    void resetUsedWords();

    // POLYMORPHISM: override info() từ GameComponent
    void info() const override;

    // POLYMORPHISM: override display() từ GameComponent
    void display() const override;

    // OPERATOR OVERLOADING: [] để lấy từ theo chỉ số
    std::string operator[](int index) const;

    // OPERATOR OVERLOADING: += thêm một từ vào danh sách
    WordManager& operator+=(const std::string& word);

    // OPERATOR OVERLOADING: == so sánh số lượng từ hai WordManager
    bool operator==(const WordManager& other) const;
};