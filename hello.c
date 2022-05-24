#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Getting user's name
    string name = get_string("what is your name: ");

    //Prints user's name
    printf("hello, %s\n", name);
}