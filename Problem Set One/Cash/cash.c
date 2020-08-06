#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Asks question until it get positive number
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    //intializing how many of each coin
    int pennies = round(change * 100);
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;

    // QUARTERS:
    if (pennies >= 25)
    {
        quarters = pennies / 25;
        pennies = pennies % 25;
    }

    // DIMES:
    if (pennies >= 10)
    {
        dimes = pennies / 10;
        pennies = pennies % 10;
    }

    // NICKELS:
    if (pennies >= 5)
    {
        nickels = pennies / 5;
        pennies = pennies % 5;
    }

    //result
    int coins = pennies + nickels + dimes + quarters;
    printf("%i\n", coins);
}
