#include <iostream>
#include <cstdlib>
//#include <string> //so, iostream include string

int main() {
    const std::string word = "hangman";
    std::string mask(word.length(), '*');
    int attempts = word.length() * 2;

    char letter;
    int length = 0;
    while (length < word.length()) {
        if (attempts <= 0) {
            printf("Lose\n");
            break;
        }

        system("clear");

        printf("Attempts: %d\n\nWord: %s\n", attempts, mask.c_str());
        printf("Letter: ");
        scanf("%s", &letter);

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter && mask[i] != letter) {
                mask[i] = letter;
                length++;
            }
        }
        attempts--;
    }
    printf("%s\n", word.c_str());

    return 0;
}
