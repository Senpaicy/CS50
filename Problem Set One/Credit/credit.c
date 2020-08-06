#include <stdio.h>
#include <cs50.h>
#include <math.h>

void whatcard(long long c, int count);

int main(void)
{
    // asks for the card number:
    long long number;
    int count = 0;

    do
    {
        number = get_long_long("Number: ");
    }
    while (number < 0);

    int sum = 0; //sum of the digits
    int temp;
    long long copy = number; //copy of the number
    long long copy2 = number; //another copy of the number

    // part one:
    do
    {
        count++;
        if (count % 2 == 0)
        {
            temp = number % 10;
            if ((2 * temp) > 9)
            {
                sum++;
                temp = (2 * temp) % 10;
                sum += temp;
            }
            else
            {
                sum += (2 * temp);
            }
        }
        number /= 10;
    }
    while (number != 0);

    // part two:
    do
    {
        temp = copy % 10;
        sum += temp;

        copy /= 100;

    }
    while (copy != 0);

    //validating
    if (sum % 10 == 0)
    {
        whatcard(copy2, count);
    }
    else
    {
        printf("INVALID\n");
    }
}

void whatcard(long long c, int count)
{
    //  VISA:
    if (count == 13)
    {
        c /= 1000000000000; //gets first digit
        if (c == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // AMERICAN EXPRESS:
    else if (count == 15)
    {
        c /= 10000000000000; //gets the first two digits
        if (c == 34 || c == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (count == 16)
    {
        // MASTER CARD
        c /= 100000000000000; // gets the first two digits
        if (c == 51 || c == 52 || c == 53 || c == 54 || c == 55)
        {
            printf("MASTERCARD\n");
        }
        // VISA
        else
        {
            c /= 10; // gets the first digit
            if (c == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

    }
    else
    {
        printf("INVALID\n");
    }
}
