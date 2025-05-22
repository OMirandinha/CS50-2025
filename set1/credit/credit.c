[⚠️ Suspicious Content] #include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    } while (number < 1);

    long temp = number;
    int sum = 0;
    int position = 0;
    int first_two = 0;
    int first_digit = 0;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (position % 2 == 1)
        {
            int product = digit * 2;
            sum += product / 10 + product % 10;
        }
        else
        {
            sum += digit;
        }

        // Stores first two digits and first digit
        if (temp < 100 && temp >= 10)
        {
            first_two = temp;
        }
        if (temp < 10)
        {
            first_digit = temp;
        }

        temp /= 10;
        position++;
    }

    // Validates the card using Luhn algorithm
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Checks card type
    if (position == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (position == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((position == 13 || position == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
