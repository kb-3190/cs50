#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //exoecting user input for height
    int n;
    do
    {
        n = get_int("Height: \n");
    }
    while (n < 1 || n > 8);

    //make a pyramid
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n - i; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        //another side of pyramid
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
