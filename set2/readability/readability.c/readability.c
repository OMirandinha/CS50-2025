#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count letters, words, and sentences in a single pass
    int letters = 0, words = 1, sentences = 0; // Start words at 1 for first word
    
    for (int i = 0; text[i]; i++)
    {
        // Count letters (alphabetic characters)
        if (isalpha(text[i])) letters++;
        
        // Count words (transitions from space to non-space)
        if (isspace(text[i])) words++;
        
        // Count sentences (., !, ? punctuation)
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') sentences++;
    }

    // Compute the Coleman-Liau index
    // L = average letters per 100 words
    float L = letters * 100.0 / words;
    // S = average sentences per 100 words
    float S = sentences * 100.0 / words;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level with special cases
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}