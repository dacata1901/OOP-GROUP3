#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Constructor
Game::Game() {
    srand(static_cast<unsigned>(time(0)));
}

// Logic 1 ván chơi
bool Game::playRound() {
    string word = wordManager.getRandomWord();
    if (word.empty()) {
        cout << "No words available to play!\n";
        return false;
    }

    for (char& c : word) 
        c = tolower(static_cast<unsigned char>(c));

    level.chooseLevel();

    cout << "Selected difficulty: " << level << endl;

    string hiddenWord = level.hideWord(word);
    ui.reset();

    while (true) {
        ui.showSeparator();
        ui.displayWord(hiddenWord);
        ui.showScore();
        ui.showLives();
        ui.showUsedLetters();

        char input = ui.getInput();

        if (input == '!') {
            cout << "Please enter exactly 1 valid letter!\n";
            --ui;
        } else {
            if (ui.isUsedLetter(input)) {
                cout << "You already used that letter!\n";
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

            if (correct) {
                ui += 10;
            } else {
                --ui;
            }
        }

        if (hiddenWord == word) {
            ui.showWin(word);
            return true;
        }

        if (ui.getLives() <= 0) {
            ui.showGameOver(word);
            return false;
        }
    }
}

// Vòng lặp chính
void Game::run() {
    wordManager.loadWords("data/words.txt");

    while (true) {
        ui.showMenu();
        int choice = ui.getChoice();

        if (choice == 2) {
            cout << "Thanks for playing! Goodbye!\n";
            cout << "Final result: " << ui << endl;
            break;
        }

        bool won = playRound();

        if (!won) {
            cout << "\nDo you want to play again? (1=Yes / 2=No): ";
            int replay;
            cin >> replay;

            if (replay != 1) {
                cout << "Result: " << ui << endl;
                break;
            }

            ui.fullReset();
        }
    }
}