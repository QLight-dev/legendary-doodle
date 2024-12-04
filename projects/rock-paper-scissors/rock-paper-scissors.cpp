#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

int main() {
    srand(time(NULL));
    bool running = true; 
    bool tie;
    bool won;
    int player_choice;
    int bot_choice;
    int wins = 0;
    int loss = 0;
    int ties = 0;
    bool valid = false;
    std::cout << "welcome to rock paper scissors! \n";
    while (running) {

        std::cout << "1. rock \n 2. paper \n 3. scissors \n 4. exit \n";
        std::cout << "choose your choice (1, 2, 3, or 4): ";
        std::cin >> player_choice;
        if (player_choice == 1 || player_choice == 2 || player_choice == 3 || player_choice == 4) {
            valid = true;
        } else {
            while (!valid) {
                std::cout << "\033[2J\033[H" << std::endl;
                std::cout << "please choose 1, 2, or 3! (1 for rock 2 for paper 3 for scissors): ";
                std::cin >> player_choice;
                if (player_choice == 1 || player_choice == 2 || player_choice == 3) {
                    valid = true;
                }
            }
        }
        std::cout << "bot is choosing..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        bot_choice = rand() % 4;
        if (bot_choice == 1 && player_choice == 3) {won = false; tie = false;}
        else if (bot_choice == 1 && player_choice == 2) {won = true; tie = false;}
        else if (bot_choice == 1 && player_choice == 1) {won = false; tie = true;}
        else if (bot_choice == 2 && player_choice == 3) {won = true; tie = false;}
        else if (bot_choice == 2 && player_choice == 2) {won = false; tie = true;}
        else if (bot_choice == 2 && player_choice == 1) {won = false; tie = false;}
        else if (bot_choice == 3 && player_choice == 3) {won = false; tie = true;}
        else if (bot_choice == 3 && player_choice == 2) {won = true; tie = false;}
        else if (bot_choice == 3 && player_choice == 1) {won = false; tie = false;}
        else if (player_choice == 4) {break;}
        std::cout << "\033[2J\033[H \n";

        if (bot_choice == 1) {std::cout << "bot: rock \n";} 
        else if (bot_choice == 2) {std::cout << "bot: paper \n";}
        else {std::cout << "bot: scissors \n";}
        if (tie == true) {
            ties += 1;
            std::cout << "tie" << std::endl;
        } else if (won = false) {
            loss += 1;
            std::cout << "lost!" << std::endl;
        } else {
            wins += 1;
            std::cout << "won!" << std::endl;
        }

    }
}