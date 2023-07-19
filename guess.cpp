#include <iostream>
#include <string>

#define less_stock stock_1 = stock_1 - 1
#define more_stock stock_1 = stock_1 + 1

unsigned int Coins = 800;
unsigned int stock_1 = 0;
bool purchased_1 = false;

int GetRandom(int min, int max) {
    int random_number = (rand() % (min - max + 1)) + min;

    return random_number;
}

int GetBalance(unsigned int currency){
    return currency;
}

void shop(){
    std::string confirm;

    int option;

    do {
    std::cout << "Options:\n";
    std::cout << "0: Quit shop.\n";
    std::cout << "1: Buy a hint - 800 points.\n";
    std::cout << "Choose an option: ";

    std::cin >> option;

    if (option == 1){
        std::cout << "\nAre you sure you wanna purchase it? Yes/No: ";
        std::cin >> confirm;

        if (confirm == "yes" || confirm == "Yes" || confirm == "YES") {
            if (Coins >= 800) {
                std::cout << "You purchased it! Use this secret code in guess game to activate it: 1919\n";
                more_stock;
                std::cout << "Stock: " << stock_1 << "\n";
                purchased_1 = true;
                Coins = Coins - 800;
            }
            else {
                std::cout << "You don't have enough coins!\n";
            }
        }
        if (confirm == "no" || confirm == "No" || confirm == "NO") {
            std::cout << "Canceling..";
            break;
            }
        }
    } while (option > 1);
}

void play_game(){
    int attempts = 0;

    int random_number = GetRandom(1, 10);
    int guess;

    do{
        std::cout << "Guess random number between 1 and 10: ";
        std::cin >> guess;

        
        if (guess > random_number) {
            std::cout << "Number is lower\n";
        }
        if (guess < random_number) {
            std::cout << "Number is higher\n";
        }
        if (guess == 1919 && purchased_1 == true) {
            attempts = attempts - 1;
            int random = GetRandom(1, 3);
            int not_accurate = random_number - random;

            std::cout << "Answer is around " << not_accurate << "\n";
            less_stock;

            if (stock_1 > 1) {
                std::cout << "You can use this hint " << stock_1 << " more times!\n";
            }
            if (stock_1 == 1) {
                std::cout << "You can use this hint 1 more time!\n";
            }
            if (stock_1 == 0) {
                std::cout << "You can't use hints anymore. :(\n";
                purchased_1 = false;
            }
        }

        attempts++;
        Coins = Coins - 5;

    } while(guess != random_number);

    if (guess == random_number) {
        std::cout << "Attempts: " << attempts << "\n";
        Coins = Coins + (attempts / 2);

            if (attempts == 1) {
                Coins = Coins + 500;

                std::cout << "Wow! It took only 1 attempts for you to guess it. You get 500 extra points!\n";
            }
    }

}

int main(){ 
    int choice;

    do{
    std::cout << "0: Quit \n1: Play game.\n2: See your balance.\n3: Enter a shop.\n4: See stock of hints.\nEnter a value: ";
    std::cin >> choice;

    switch (choice){
        case 0:
            std::cout << "Quitted.\n";
            break;
        case 1:
            play_game();
            break;
        case 2:
            std::cout << "Coins: " << GetBalance(Coins) << "\n";
            break;
        case 3:
            shop();
            break;
        case 4:
            std::cout << "Stock of hints: " << stock_1 << "\n";
            break;
        default:
            std::cout << "Invalid option.\n";
            break;
        }
    }
    while(choice !=0);

}
