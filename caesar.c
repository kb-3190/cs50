#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //process to make cioher text
    if (argc == 2)
    {
        //check if input is all digit
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (argv[1][i] <= '0' && argv[1][i] >= '9')
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        int k = atoi(argv[1]);
        //ask user for plaintext
        string plaintext = get_string("plaintext: ");
        
        //output the result
        printf("ciphertext: ");

        //convet all letters to ciphertext and output
        for (int n = 0; n < strlen(plaintext); n++)
        {
            if (plaintext[n] >= 'a' && plaintext[n] <= 'z')
            {
                printf("%c", (((plaintext[n] + k) - 'a') % 26) + 97);
            }
            else if (plaintext[n] >= 'A' && plaintext[n] <= 'Z')
            {
                printf("%c", (((plaintext[n] + k) - 'A') % 26) + 65);
            }
            else
            {
                printf("%c", plaintext[n]);
            }
        }
        printf("\n");
    }
    //return error when invalid input
    else
    {
        printf("Error: invalid input\n");
        return 1;
    }
}
