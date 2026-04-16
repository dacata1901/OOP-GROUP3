#include "WordManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;


//  Constructor - INHERITANCE: gọi constructor lớp cha

WordManager::WordManager() : GameComponent("WordManager") {}


//  ENCAPSULATION: private helper methods

bool WordManager::isValidWord(const string& word) const {
    if (word.empty()) return false;
    for (char c : word) {
        if (!isalpha(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

string WordManager::normalizeWord(const string& word) const {
    string result = word;
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c) { return tolower(c); });
    return result;
}


//  Public methods

bool WordManager::loadWords(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file: " << filename << endl;
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
        cout << "No valid words found in file." << endl;
        return false;
    }
    return true;
}

bool WordManager::isEmpty() const {
    return words.empty();
}

int WordManager::getWordCount() const {
    return static_cast<int>(words.size());
}

void WordManager::clearWords() {
    words.clear();
    usedIndexes.clear();
}

string WordManager::getRandomWord() {
    if (words.empty()) return "";
    return words[rand() % words.size()];
}

string WordManager::getUnusedRandomWord() {
    if (words.empty() || usedIndexes.size() == words.size()) return "";
    int index;
    do {
        index = rand() % words.size();
    } while (usedIndexes.count(index));
    usedIndexes.insert(index);
    return words[index];
}

void WordManager::resetUsedWords() {
    usedIndexes.clear();
}


//  POLYMORPHISM: Override info() và display()

void WordManager::info() const {
    cout << "WordManager: Managing " << words.size() << " words." << endl;
}

void WordManager::display() const {
    cout << "=== " << componentName << " ===" << endl;
    cout << "Total words: " << words.size() << endl;
    cout << "Used so far: " << usedIndexes.size() << " words" << endl;
}


//  OPERATOR OVERLOADING


// [] - truy cập từ theo chỉ số
string WordManager::operator[](int index) const {
    if (index < 0 || index >= (int)words.size()) return "";
    return words[index];
}

// += - thêm một từ vào danh sách
WordManager& WordManager::operator+=(const string& word) {
    string normalized = normalizeWord(word);
    if (isValidWord(normalized)) {
        words.push_back(normalized);
    }
    return *this;
}

// == - so sánh hai WordManager có cùng số lượng từ không
bool WordManager::operator==(const WordManager& other) const {
    return words.size() == other.words.size();
}