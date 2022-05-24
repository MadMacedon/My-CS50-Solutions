#include <cs50.h>
#include <stdio.h>

void print_hash(int n);
void print_space(int n);

int main(void)
{

    //Prompt user for desired height
    int height = 0;
    while (true)
    {
        height = get_int("Height: ");
        if (height > 0 && height < 9)
        {
            break;
        }
    }


    //For loop that prints pyramid
    //Starts at 1 because nothing prints during loop 0 anyways
    for (int i = 1; i < height + 1; i++)
    {
        print_space(height - i);
        print_hash(i);
        printf("  ");
        print_hash(i);
        printf("\n");
    }
}

//Prints # n number of times
void print_hash(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

//Prints spaces n number of times
void print_space(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}