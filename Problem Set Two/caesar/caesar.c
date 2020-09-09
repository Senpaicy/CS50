#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n"); // error if there
        return 1;                         // not just two arguments
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i])) 
        {
            printf("Usage: ./caesar key \n"); // error if there is
            return 1;                         // an letter in the key
        }
    }
    
    int key = 0; 
    int tens = 1;
    for (int j = strlen(argv[1]) - 1; j > -1 ; j--)
    {
        key = key + ((int)(argv[1][j]) - 48) * tens; // convert string to int
        tens *= 10;
    }

    string input = get_string("plaintext: ");
    int index;
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(input); i++)
    {
        index = (int) input[i];
        
        if (index > 96 && index < 123) // if lower case 
        {
            index = (index - 97 + key) % 26; //changing the index
            printf("%c", index + 97);
        }
        else if (index < 91 && index > 64) // if upper case
        {
            index = (index - 65 + key) % 26; // changing the index
            printf("%c", index + 65);
        }
        else
        {
            printf("%c", input[i]); // if a symbol
        }
    }
    
    printf("\n");
    return 0;
}