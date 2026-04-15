#include "WordManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

WordManager::WordManager() {
    srand((unsigned)time(nullptr));
}

bool WordManager::isValidWord(const string& word) const {
    if (word.empty()) return false;

    for (char c : word) {
        if (!isalpha(static_cast<unsigned char>(c))) {
            return false;
        }
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

bool WordManager::loadWordsFromFile(const string& filename) {
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

void WordManager::displayWords() const {
    cout << "\nDanh sach tu vung:\n";
    for (size_t i = 0; i < words.size(); i++) {
        cout << i + 1 << ". " << words[i] << endl;
    }
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
    if (words.empty()) {
        return "";
    }

    int index = rand() % words.size();
    return words[index];
}

string WordManager::getUnusedRandomWord() {
    if (words.empty()) {
        return "";
    }

    if (usedIndexes.size() == words.size()) {
        return "";
    }

    int index;
    do {
        index = rand() % words.size();
    } while (usedIndexes.count(index) > 0);

    usedIndexes.insert(index);
    return words[index];
}

void WordManager::resetUsedWords() {
    usedIndexes.clear();
}

void WordManager::displayInfo() const {
    cout << "WordManager dang quan ly " << words.size() << " tu." << endl;
}

string WordManager::getComponentName() const {
    return "WordManager";
}
