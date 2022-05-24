#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool valid_args(int argc, string arg[]);
void key_to_intarr(string key, int intarr[]);
void text_to_intarr(string text, int arr[]);
string ciphertext(string key, string text);

// Key must be 26 characters long OR ELSE!!
const int KEYLEN = 26;

int main(int argc, string argv[])
{
    // Checking for invalid args
    if (!valid_args(argc, argv))
    {
        return 1;
    }

    // Prompt user for text to cipher
    string plaintext = get_string("plaintext: ");


    // Display ciphertext
    printf("ciphertext: %s\n", ciphertext(argv[1], plaintext));

}

// Checks for correct arg count and then verifies valid key
bool valid_args(int argc, string arg[])
{
    // Check for correct argument count
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }

    // Checks that 26 chars are present
    if (strlen(arg[1]) != KEYLEN)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    // Checks that each char is a letter
    for (int i = 0; i < KEYLEN; i++)
    {
        if (!isalpha(arg[1][i]))
        {
            printf("Key contains invalid characters.\n");
            return false;
        }
    }

    // Checks for repeated characters
    for (int i = 0; i < KEYLEN; i++)
    {

        char c = toupper(arg[1][i]);

        // Check for repeating letter starting from one past itself to avoid repeating letters
        for (int k = i + 1; k < KEYLEN; k++)
        {
            if (c == toupper(arg[1][k]))
            {
                printf("Key contains repeated characters\n");
                return false;
            }
        }
    }

    return true;
}

// Converts key to a case agnostic array of ints
void key_to_intarr(string key, int intarr[])
{
    for (int i = 0; i < KEYLEN; i++)
    {
        if (isupper(key[i]))
        {
            intarr[i] = key[i] - 65;
        }
        else
        {
            intarr[i] = key[i] - 97;
        }
    }

}

// Converts text to a case agnostic array of ints
void text_to_intarr(string text, int arr[])
{
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (isupper(text[i]))
        {
            arr[i] = text[i] - 65;
        }
        else
        {
            arr[i] = text[i] - 97;
        }

    }
}

// Finally does the thing
string ciphertext(string key, string text)
{
    int keyarr[KEYLEN];
    key_to_intarr(key, keyarr);
    int textarr[strlen(text)];
    text_to_intarr(text, textarr);

    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (isalpha(text[i]))
        {
            // 65 and 97 are there to put case back into each letter
            if (isupper(text[i]))
            {
                text[i] = keyarr[textarr[i]] + 65;
            }
            else
            {
                text[i] = keyarr[textarr[i]] + 97;
            }
        }
    }

    return text;
}