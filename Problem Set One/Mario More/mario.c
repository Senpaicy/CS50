#include <stdio.h>
#include <cs50.h>

void stair(int block);

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
        /* left pyramid */

        spaces = stairs - i;
        while (spaces > 0)
        {
            printf(" ");
            spaces--;
        }
        stair(i);

        //break

        printf("  ");

        /* right pyramid */

        stair(i);
        printf("\n");
    }
}

// pyramid

void stair(int blocks)
{
    for (int j = blocks; j > 0; j--)
    {
        printf("#");
    }
}
