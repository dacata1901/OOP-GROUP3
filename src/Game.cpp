#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor
Game::Game() {
    // Khởi tạo random (chỉ gọi 1 lần duy nhất trong toàn chương trình)
    srand(time(0));
}

// Hàm chạy game chính
void Game::run() {
    // Load danh sách từ từ file
   wordManager.loadWords("data/words.txt");

    while (true) {
        // ===== MENU =====
        ui.showMenu();
        int choice = ui.getChoice();

        if (choice == 2) {
            cout << "Thoat game!\n";
            break;
        }

        // ===== GAME LOOP =====
        string word = wordManager.getRandomWord();

        // Chọn độ khó
        level.chooseLevel();

        // Ẩn chữ
        string hiddenWord = level.hideWord(word);

        // Reset trạng thái mỗi vòng
        // (nếu bạn có reset lives/usedLetters thì thêm ở UI)

        while (true) {
            cout << "\n====================\n";

            // Hiển thị thông tin
            ui.displayWord(hiddenWord);
            ui.showScore();
            ui.showLives();
            ui.showUsedLetters();

            // Nhập ký tự
            char input = ui.getInput();
            ui.addUsedLetter(input);

            // Kiểm tra đúng sai
            bool correct = false;

            for (int i = 0; i < word.length(); i++) {
                if (word[i] == input && hiddenWord[i] == '_') {
                    hiddenWord[i] = input;
                    correct = true;
                }
            }

            // Hiển thị kết quả
            ui.showResult(correct);

            if (correct) {
                ui.increaseScore(10);
            } else {
                ui.decreaseLives();
            }

            // ===== WIN =====
            if (hiddenWord == word) {
                ui.showWin(word);
                break;
            }

            // ===== GAME OVER =====
            if (ui.getLives() <= 0) {
                ui.showGameOver(word);
                break;
            }
        }

        // ===== CONTINUE? =====
        char cont;
        cout << "\nBan co muon choi tiep? (y/n): ";
        cin >> cont;

        if (cont != 'y' && cont != 'Y') {
            cout << "Cam on ban da choi!\n";
            break;
        }
    }
}