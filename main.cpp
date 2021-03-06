#include <iostream>

int main() {
    const std::string word = "hangman";
    int attempts = word.length() * 2;

    char mask[word.length()];
    for (int i = 0; i < word.length(); i++)
        mask[i] = '*';

    char letter;
    int length = 0;
    while (length < word.length()) {
        if (attempts <= 0) {
            std::cout << "Lose" << std::endl;
            break;
        }

#ifdef __linux__
        system("clear");
#elif _WIN32
        system("cls");
#endif

        std::cout << "Attempts: " << attempts << '\n' << std::endl;

        for (const auto &m : mask)
            std::cout << m;
        std::cout << std::endl;

        std::cin >> letter;
        for (int i = 0; i < word.length(); i++) {
            if (word.c_str()[i] == letter && mask[i] != letter) {
                mask[i] = letter;
                length++;
            }
        }
        attempts--;
    }
    std::cout << word << std::endl;

    return 0;
}
