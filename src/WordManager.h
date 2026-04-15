#ifndef WORDMANAGER_H
#define WORDMANAGER_H

#include "GameComponent.h"
#include <string>
#include <vector>
#include <set>

using namespace std;

class WordManager : public GameComponent {
private:
    vector<string> words;
    set<int> usedIndexes;

    bool isValidWord(const string& word) const;
    string normalizeWord(const string& word) const;

public:
    WordManager();

    bool loadWordsFromFile(const string& filename);
    void displayWords() const;
    bool isEmpty() const;
    int getWordCount() const;
    void clearWords();

    string getRandomWord();
    string getUnusedRandomWord();
    void resetUsedWords();

    void displayInfo() const override;
    string getComponentName() const override;
};

#endif
