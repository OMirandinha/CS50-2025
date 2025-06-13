#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>

bool is_valid_key(string key);
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate the key
    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    // Encrypt and print ciphertext
    printf("ciphertext: ");
    encrypt(plaintext, argv[1]);
    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    // Check key length
    if (strlen(key) != 26)
    {
        return false;
    }

    // Initialize frequency array to track letter occurrences
    int freq[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        // Check if character is alphabetic
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Convert to uppercase for case-insensitive check
        char upper = toupper(key[i]);

        // Check if letter has been seen before
        if (freq[upper - 'A'] > 0)
        {
            return false;
        }

        // Mark letter as seen
        freq[upper - 'A']++;
    }

    return true;
}

void encrypt(string plaintext, string key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            // Determine the position in the alphabet (0-25)
            int position;
            if (isupper(c))
            {
                position = c - 'A';
                printf("%c", toupper(key[position]));
            }
            else
            {
                position = c - 'a';
                printf("%c", tolower(key[position]));
            }
        }
        else
        {
            // Non-alphabetic characters remain unchanged
            printf("%c", c);
        }
    }
}