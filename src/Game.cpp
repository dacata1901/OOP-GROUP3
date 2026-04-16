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

    bool gameOver = false;

    while (true) {

        ui.showMenu();
        int choice = ui.getChoice();

        if (choice == 2 || gameOver) {
            cout << "Thoat game!\n";
            break;
        }

        string word = wordManager.getRandomWord();

        for (char &c : word) c = tolower(c);

        level.chooseLevel();
        string hiddenWord = level.hideWord(word);

        ui.reset();

        while (true) {

            cout << "\n====================\n";

            ui.displayWord(hiddenWord);
            ui.showScore();
            ui.showLives();
            ui.showUsedLetters();

            char input = ui.getInput();

            //  input sai
            if (input == '!') {
                cout << "Only ONE valid letter is allowed!\n";
                ui.decreaseLives();
            }
            else {

                if (ui.isUsedLetter(input)) {
                    cout << "This letter has already been used!\n";
                    continue;
                }

                ui.addUsedLetter(input);

                bool correct = false;

                for (int i = 0; i < (int)word.length(); i++) {
                    if (word[i] == input && hiddenWord[i] == '_') {
                        hiddenWord[i] = input;
                        correct = true;
                    }
                }

                ui.showResult(correct);

                if (correct) ui.increaseScore(10);
                else ui.decreaseLives();
            }

            // WIN
            if (hiddenWord == word) {
                ui.showWin(word);
                break;
            }

            // GAME OVER → EXIT FULL GAME
            if (ui.getLives() <= 0) {
                ui.showGameOver(word);
                gameOver = true;
                break;
            }
        }

        if (gameOver) break;
    }
}