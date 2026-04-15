#include "WordManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

// Constructor
WordManager::WordManager() {
    // Không cần srand ở đây
}

// Kiểm tra từ hợp lệ (chỉ chứa chữ cái)
bool WordManager::isValidWord(const string& word) const {
    if (word.empty()) return false;

    for (char c : word) {
        if (!isalpha(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

// Chuẩn hóa từ (xóa khoảng trắng + lowercase)
string WordManager::normalizeWord(const string& word) const {
    string result = word;

    // Xóa khoảng trắng
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());

    // Chuyển về chữ thường
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c) { return tolower(c); });

    return result;
}

// Load từ từ file
bool WordManager::loadWords(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << endl;
        return false;
    }

    words.clear();
    usedIndexes.clear();

    string line;
    while (getline(file, line)) {
        string word = normalizeWord(line);
        if (isValidWord(word)) {
            words.push_back(word);
        }
    }

    file.close();

    if (words.empty()) {
        cout << "File khong co tu hop le." << endl;
        return false;
    }

    return true;
}

// Kiểm tra rỗng
bool WordManager::isEmpty() const {
    return words.empty();
}

// Số lượng từ
int WordManager::getWordCount() const {
    return static_cast<int>(words.size());
}

// Xóa dữ liệu
void WordManager::clearWords() {
    words.clear();
    usedIndexes.clear();
}

// Lấy từ random
string WordManager::getRandomWord() {
    if (words.empty()) return "";

    int index = rand() % words.size();
    return words[index];
}

// Lấy từ chưa dùng
string WordManager::getUnusedRandomWord() {
    if (words.empty()) return "";

    if (usedIndexes.size() == words.size()) {
        return "";
    }

    int index;
    do {
        index = rand() % words.size();
    } while (usedIndexes.count(index));

    usedIndexes.insert(index);
    return words[index];
}

// Reset
void WordManager::resetUsedWords() {
    usedIndexes.clear();
}

// Thông tin (đa hình)
void WordManager::info() {
    cout << "WordManager: Dang quan ly " << words.size() << " tu.\n";
}