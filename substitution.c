#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//initialize functions
bool check_duplication(string text);
bool check_isalpha(string text);

int main(int argc, char *argv[])
{
    string cipherkey = argv[1];

    //checking invalid input or not
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Error: invalid input\n");
        return 1;
    }

    //checking invalid input or not
    bool duplication = check_duplication(argv[1]);
    bool is_alpha = check_isalpha(argv[1]);
    if (duplication == false || is_alpha == false)
    {
        printf("Error: invalid input\n");
        return 1;
    }

    //get a plaintext
    string plaintext = get_string("plaintext: ");

    //output ciphertext
    printf("ciphertext: ");

    for (int m = 0; m < strlen(plaintext); m++)
    {
        if (plaintext[m] >= 'a' && plaintext[m] <= 'z')
        {
            int key = plaintext[m] - 97;
            printf("%c", tolower(cipherkey[key]));
        }
        else if (plaintext[m] >= 'A' && plaintext[m] <= 'Z')
        {
            int key = plaintext[m] - 65;
            printf("%c", toupper(cipherkey[key]));
        }
        else
        {
            printf("%c", plaintext[m]);
        }
    }
    printf("\n");

}

// function to check duplication
bool check_duplication(string text)
{
    for (int i = 0; i < strlen(text) - 1; i++)
    {
        for (int n = i + 1; n < strlen(text); n++)
        {
            if (tolower(text[i]) == tolower(text[n]))
            {
                return false;
            }
        }
    }
    return true;
}

//function to check if contains non-alphabet
bool check_isalpha(string text)
{
    for (int j = 0; j < strlen(text); j++)
    {
        if (isalpha(text[j]) == false)
        {
            return false;
        }
    }
    return true;
}
