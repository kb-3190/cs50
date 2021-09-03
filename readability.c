#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// define functions
int letter_count(string text);
int word_count(string text);
int sentence_count(string text);

int main(void)
{
    //prompt user input
    string text = get_string("Text: ");

    //call function to cumpute each values
    float number_of_letters = letter_count(text);
    float number_of_words = word_count(text);
    float number_of_sentences = sentence_count(text);

    //calculate L & S
    float L = (float)100 / number_of_words * number_of_letters;
    float S = (float)100 / number_of_words * number_of_sentences;

    //calculate the grade
    float grade = 0.0588 * L - 0.296 * S - 15.8;

    //print grade
    if (round(grade) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(grade) >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(grade));
    }
}

// function to compute the number of letters in the text
int letter_count(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (tolower(text[i]) >= 97 && tolower(text[i]) <= 122)
        {
            letters += 1;
        }
        else
        {
            letters += 0;
        }
    }
    return letters;
}

// function to cuompute the number of words in the text
int word_count(string text)
{
    int words = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            words += 1;
        }
        else
        {
            words += 0;
        }
    }
    words += 1;
    return words;
}

//function to compute the number of sentences in the text
int sentence_count(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences += 1;
        }
        else
        {
            sentences += 0;
        }
    }
    return sentences;
}
