#include <cs50.h>
#include <stdio.h>

// Returns card length if checksum is valid otherwise returns -1
int checksum(long card_number);
// Determines if card is valid and prints brand
void validate_card(int start_digits, int length);
// Returns first two digits of card
int get_start_digits(long card_number, int length);

int main(void)
{
    // Get user input
    long cc_number = get_long("Number: ");

    // Runs checksum and stores return value as the length of the card
    int length = checksum(cc_number);

    if (length > 0)
    {
        validate_card(get_start_digits(cc_number, length), length);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Implements Luhn's Algorithm
int checksum(long card_number)
{
    // Keeps track of sums
    int even_sum = 0;
    int odd_sum  = 0;

    int counter = 0;

    while (card_number > 0)
    {
        // Gets last digit of card_number
        int last_digit = card_number % 10;

        // Determine wether to multiply by two or not
        if (counter % 2 == 0)
        {
            even_sum += last_digit;
        }
        else
        {
            int temp = last_digit * 2;
            // Add digits of product
            if (temp > 9)
            {
                int temp_ld = temp % 10;
                odd_sum += temp_ld;
                temp -= temp_ld;
                temp = temp / 10;
                odd_sum += temp;
            }
            else
            {
                odd_sum += temp;
            }
        }

        card_number = card_number - last_digit;
        card_number = card_number / 10;

        counter++;
    }

    // Adding sums together and checks last digit
    int sum = even_sum + odd_sum;
    if (sum % 10 == 0)
    {
        return counter;
    }
    else
    {
        return -1;
    }
}

int get_start_digits(long card_number, int length)
{
    long cc = card_number;

    for (int i = 0; i < length - 2; i++)
    {
        int temp = cc % 10;
        cc -= temp;
        cc = cc / 10;
    }

    return cc;
}

void validate_card(int start_digits, int length)
{
    // Mastercard uses 16 digits start w/: 51, 52, 53, 54, 55
    // Visa uses 13 and 16       start w/: 4
    // American Express uses 15  start w/: 34, 37

    switch (start_digits)
    {
        case 34:
            (length == 15) ? printf("AMEX\n") : printf("INVALID\n");
            break;
        case 37:
            (length == 15) ? printf("AMEX\n") : printf("INVALID\n");
            break;
        case 40 ... 49:
            (length == 13 || length == 16) ? printf("VISA\n") : printf("INVALID\n");
            break;
        case 51 ... 55:
            (length == 16) ? printf("MASTERCARD\n") : printf("INVLAID\n");
            break;
        default:
            printf("INVALID\n");
    }

}