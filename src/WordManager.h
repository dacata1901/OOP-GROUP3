#pragma once
#include "GameComponent.h"
#include <string>
#include <vector>
#include <set>

// Class quản lý từ vựng
class WordManager : public GameComponent {
private:
    std::vector<std::string> words;   // danh sách từ
    std::set<int> usedIndexes;        // tránh lặp lại từ

    // Kiểm tra từ hợp lệ
    bool isValidWord(const std::string& word) const;

    // Chuẩn hóa từ (lowercase, trim...)
    std::string normalizeWord(const std::string& word) const;

public:
    // Constructor
    WordManager();

    // Load từ từ file
    bool loadWords(const std::string& filename);

    // Kiểm tra rỗng
    bool isEmpty() const;

    // Lấy số lượng từ
    int getWordCount() const;

    // Xóa toàn bộ từ
    void clearWords();

    // Lấy từ ngẫu nhiên
    std::string getRandomWord();

    // Lấy từ chưa dùng
    std::string getUnusedRandomWord();

    // Reset danh sách đã dùng
    void resetUsedWords();

    // Override từ GameComponent
    void info() override;
};