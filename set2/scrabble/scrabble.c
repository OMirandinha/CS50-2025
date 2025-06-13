#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Defines a structure to hold letter-point pairs
typedef struct {
    char letter;
    int points;
} LetterValue;

int calculate_score(char *word) {
    // I've created an array to make letter scores more compact and easier to read
    LetterValue letter_values[] = {
        {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1},
        {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8},
        {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1},
        {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1},
        {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4},
        {'Z', 10}
    };
    
    int score = 0;
    
    // Converts everything to upper case
    for (int i = 0; word[i] != '\0'; i++) {
        char c = toupper(word[i]);
        
        // Searches for respective letter in the array
        for (size_t j = 0; j < sizeof(letter_values)/sizeof(LetterValue); j++) {
            if (letter_values[j].letter == c) {
                score += letter_values[j].points;
                break;
            }
        }
    }
    
    return score;
}

//main program
int main(void) {
    char word1[100], word2[100];
    
    printf("Player 1: ");
    scanf("%99s", word1);
    
    printf("Player 2: ");
    scanf("%99s", word2);
    
    int score1 = calculate_score(word1);
    int score2 = calculate_score(word2);
    
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
    
    return 0;
}