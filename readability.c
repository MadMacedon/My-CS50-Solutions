#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get user input or whatever
    string input = get_string("Text: ");

    // Implement the algo or somthin
    double L = (double) count_letters(input) / (double) count_words(input) * 100;
    double S = (double) count_sentences(input) / (double) count_words(input) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    // Finalizes the formatting
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

// To count letters I just used isalpha from ctype
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// To count words I itterated over the string and searched for a space
int count_words(string text)
{
    int words = 0;

    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words + 1;
}

// To count sentences I used a switch to increment when one of 3 cases of punc. is true
int count_sentences(string text)
{
    int sentences = 0;

    // Switch statements are useful but this comment is not
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        switch (text[i])
        {
            case '!' :
                sentences++;
                break;
            case '.' :
                sentences++;
                break;
            case '?' :
                sentences++;
                break;
        }
    }

    // This returns the variable called sentences
    return sentences;
}