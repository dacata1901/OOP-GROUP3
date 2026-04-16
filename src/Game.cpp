#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;


//  Constructor

Game::Game() {
    srand(static_cast<unsigned>(time(0)));
}


//  ENCAPSULATION: private - in thông tin tất cả components
//  Demo POLYMORPHISM: gọi info() qua con trỏ lớp cha
void Game::showAllInfo() const {
    cout << "\n--- Thong tin cac thanh phan ---\n";

    // Mảng con trỏ lớp cha trỏ đến các đối tượng khác nhau
    const GameComponent* components[] = {
        &wordManager,
        &level,
        &inputHandler,
        &ui
    };

    // Gọi info() - runtime polymorphism, mỗi class gọi đúng phiên bản của nó
    for (const GameComponent* comp : components) {
        comp->info();    // virtual dispatch
    }

    cout << "----------------------------------------------------\n";
}

//  ENCAPSULATION: private - logic 1 ván chơi

bool Game::playRound() {
    string word = wordManager.getRandomWord();
    if (word.empty()) {
        cout << "Khong co tu nao de choi!\n";
        return false;
    }

    for (char& c : word) c = tolower(static_cast<unsigned char>(c));

    level.chooseLevel();

    // Demo operator << của Level
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
            // Demo operator -- của UI
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
                // Demo operator += của UI
                ui += 10;
            } else {
                // Demo operator -- của UI
                --ui;
            }
        }

        // THẮNG
        if (hiddenWord == word) {
            ui.showWin(word);
            return true;
        }

        // THUA
        if (ui.getLives() <= 0) {
            ui.showGameOver(word);
            return false;
        }
    }
}

//  Vòng lặp game chính

void Game::run() {
    wordManager.loadWords("data/words.txt");

    // Demo operator << qua tham chiếu lớp cha (dùng đúng inheritance)
    const GameComponent& gcRef = wordManager;   // upcasting - INHERITANCE
    cout << gcRef << endl;

    // Demo polymorphism hiển thị thông tin tất cả components
    showAllInfo();

    // Demo operator so sánh Level (<, >, ==)
    Level easyLv, hardLv;
    ++hardLv; ++hardLv;  // tăng hardLv lên HARD
    cout << "So sanh do kho: ";
    if (easyLv < hardLv)  cout << "Easy < Hard -> Dung\n";
    if (hardLv > easyLv)  cout << "Hard > Easy -> Dung\n";
    if (!(easyLv == hardLv)) cout << "Easy != Hard -> Dung\n";

    while (true) {
        ui.showMenu();
        int choice = ui.getChoice();

        if (choice == 2) {
            cout << "Cam on ban da choi! Tam biet!\n";

            // Demo operator << của UI khi thoát
            cout << "Ket qua cuoi: " << ui << endl;
            break;
        }

        bool won = playRound();

        if (!won) {
            // Game over → hỏi có chơi lại không
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