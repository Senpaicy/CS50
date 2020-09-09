#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //input:
    string text = get_string("Text: ");
    
    int words = 0; // words counter
    int letters = 0; // letter counter
    int sentences = 0; // sentence counter
    
    for (int i = 0; i < strlen(text); i++) //goes through the text given
    {
        if (text[i] == ' ') // if theres a space, then theres a finished word
        {
            words++; // add to word counter
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // sentence enders.
        {
            sentences++; // add add to sentence counter
        }
        if (isalpha(text[i])) // if it's a letter
        {
            letters++; // add to letter counter
        }
    }
    words++;
    
    float Letters = 100 * (float)letters / (float)words; // letter per 100 words
    float Sentences = 100 * (float)sentences / (float)words; // sentences per 100 words
    
    int grade = (round)((0.0588 * Letters) - (0.296 * Sentences) - 15.8); //that equation
    
    if (grade < 1) // if negative --> before grade 1
    {
        printf("Before Grade 1\n");
    }
    else if (grade <= 16 && grade > 0) // between grades 1-16
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n"); // grades 16+
    }
}