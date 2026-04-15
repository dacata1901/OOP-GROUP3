#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Constructor
Game::Game() {
    srand(time(0));
}

// ===== GAME LOOP =====
void Game::run() {

    wordManager.loadWords("data/words.txt");

    while (true) {

        ui.showMenu();
        int choice = ui.getChoice();

        if (choice == 2) {
            cout << "Thoat game!\n";
            break;
        }

        string word = wordManager.getRandomWord();

        // lowercase
        for (char &c : word) c = tolower(c);

        level.chooseLevel();
        string hiddenWord = level.hideWord(word);

        ui.reset(); //reset mỗi game

        while (true) {

            cout << "\n====================\n";

            ui.displayWord(hiddenWord);
            ui.showScore();
            ui.showLives();
            ui.showUsedLetters();

            char input = ui.getInput();

            //  nhập lại chữ đã dùng
            if (ui.isUsedLetter(input)) {
                cout << "Da nhap chu nay roi!\n";
                continue;
            }

            ui.addUsedLetter(input);

            bool correct = false;

            for (int i = 0; i < word.length(); i++) {
                if (word[i] == input && hiddenWord[i] == '_') {
                    hiddenWord[i] = input;
                    correct = true;
                }
            }

            ui.showResult(correct);

            if (correct) ui.increaseScore(10);
            else ui.decreaseLives();

            if (hiddenWord == word) {
                ui.showWin(word);
                break;
            }

            if (ui.getLives() <= 0) {
                ui.showGameOver(word);
                break;
            }
        }

        char cont;
        cout << "\nChoi tiep? (y/n): ";
        cin >> cont;

        if (cont != 'y' && cont != 'Y') {
            cout << "Cam on ban!\n";
            break;
        }
    }
}