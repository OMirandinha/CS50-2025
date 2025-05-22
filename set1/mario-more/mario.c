[⚠️ Suspicious Content] #include <stdio.h>
#include <cs50.h>

int get_height(void);
void print_pyramids(int height);

// Main function to print the pyramid
int main(void)
{
    int height = get_height();
    print_pyramids(height);
}

// Prompts user for pyramid height (1-8)
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

// Print the double pyramids with a gap
void print_pyramids(int height)
{
    for (int row = 0; row < height; row++)
    {
        // Left pyramid spaces
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // Left pyramid hashes
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }

        // Gap (always 2 spaces)
        printf("  ");

        // Right pyramid hashes
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }

        // Move to next line
        printf("\n");
    }
}
