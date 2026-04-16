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
        cout << "Khong co tu nao de choi!\n";
        return false;
    }

    for (char& c : word) 
        c = tolower(static_cast<unsigned char>(c));

    level.chooseLevel();

    cout << "Do kho da chon: " << level << endl;

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
            cout << "Chi duoc nhap 1 chu cai hop le!\n";
            --ui;
        } else {
            if (ui.isUsedLetter(input)) {
                cout << "Chu nay da duoc dung roi!\n";
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

    // Demo operator << (inheritance)
    const GameComponent& gcRef = wordManager;
    cout << gcRef << endl;

    while (true) {
        ui.showMenu();
        int choice = ui.getChoice();

        if (choice == 2) {
            cout << "Cam on ban da choi! Tam biet!\n";
            cout << "Ket qua cuoi: " << ui << endl;
            break;
        }

        bool won = playRound();

        if (!won) {
            cout << "\nBan co muon choi lai khong? (1=Co / 2=Khong): ";
            int replay;
            cin >> replay;

            if (replay != 1) {
                cout << "Ket qua: " << ui << endl;
                break;
            }

            ui.fullReset();
        }
    }
}