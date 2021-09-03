#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long credit_num;
    //ask user to put creditcard number
    do
    {
        credit_num = get_long("Number: ");
    }
    while (credit_num < 0);

    long num = credit_num;

    //count number of digits
    int digits_count = 0;

    while (credit_num != 0)
    {
        credit_num /= 10;
        digits_count++;
    }

    //return error when number of digit is invalid
    if (digits_count != 16 && digits_count != 15 && digits_count != 13)
    {
        printf("INVALID\n");
        return 0;
    }

    //make an array of credit number
    int credit_text[digits_count];
    for (int j = 0; j < digits_count; j++)
    {
        credit_text[j] = num % 10;
        num /= 10;
    }

    //Luhn algorithm
    int sum1 = 0;
    int sum2 = 0;
    int doubled_num = 0;

    for (int i = 0; i < digits_count; i++)
    {
        if (i % 2 != 0)
        {
            doubled_num = credit_text[i] * 2;
            if (doubled_num >= 10)
            {
                sum1 += doubled_num - 9;
            }
            else
            {
                sum1 += doubled_num;
            }
        }
        else if (i % 2 == 0)
        {
            sum2 += credit_text[i];
        }
    }

    int total_sum = sum1 + sum2;

    //check if total_sum is valid or not
    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //check VISA/MASTERCARD/AMEX
    if (digits_count == 13 && credit_text[12] == 4)
    {
        printf("VISA\n");
    }

    if (digits_count == 16 && credit_text[15] == 5)
    {
        if (credit_text[14] == 1 || credit_text[14] == 2 || credit_text[14] == 3 || credit_text[14] == 4 || credit_text[14] == 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    if (digits_count == 16 && credit_text[15] == 4)
    {
        printf("VISA\n");
    }

    if (digits_count == 15)
    {
        if (credit_text[14] == 3 && (credit_text[13] == 4 || credit_text[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    return 0;
}
