#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*-------------------QUESTION----------------------*/

    int stairs;
    do
    {
        stairs = get_int("How many stairs? ");
    }
    while (stairs < 1 || stairs > 8);

    /*---------------------PYRAMID---------------------*/

    // number of spaces

    int spaces = 0;

    for (int i = 1; i < stairs + 1; i++)
    {
        spaces = stairs - i;
        while (spaces > 0)
        {
            printf(" ");
            spaces--;
        }
        for (int j = i; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}
