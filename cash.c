#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //aks for the user input
    float n;
    do
    {
        n = get_float("Change owed: \n");
    }
    while (n < 0);

    int cents = round(n * 100);

    //initialize variables
    int quaters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    //culculate the number of coins needed
    do
    {
        if (cents >= 25)
        {
            quaters = floor(cents / 25);
            cents -= quaters * 25;
        }
        else if (cents >= 10)
        {
            dimes = floor(cents / 10);
            cents -= dimes * 10;
        }
        else if (cents >= 5)
        {
            nickels = floor(cents / 5);
            cents -= nickels * 5;
        }
        else
        {
            pennies = cents / 1;
            cents -= pennies * 1;
        }
    }
    while (cents >= 1);

    int total_number = quaters + dimes + nickels + pennies;

    printf("%u\n", total_number);
}
