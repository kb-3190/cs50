#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("start size:\n");
    }
    while (n < 9);
    // TODO: Prompt for end size
    int x;
    do
    {
        x = get_int("end size:\n");
    }
    while (x < n);
    // TODO: Calculate number of years until we reach threshold
    int i = 0;
    while (n < x)
    {
        n += n / 3 - n / 4;
        i ++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", i);
}
