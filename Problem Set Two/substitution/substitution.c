#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // BASE CASE:
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n"); // error if no key was provided
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n"); // error because there 
        return 1;                                    // was less than 26 characters
    }
    for (int i = 0; i < 26; i++)
    {
        if (isdigit(key[i]))
        {
            printf("Usage: ./substitution key\n"); // error because there was a 
            return 1;                              // a number in the key
        }
        for (int j = i + 1; j < 26; j++)
        {
            if (key[i] == key[j])
            {
                printf("Usage: ./substitution key\n"); // error because a character
                return 1;                              // appeared twice.
            }
        }
        if (key[i] > 96)
        {
            key[i] = (char)((int)key[i] - 32); // if lowercase change to uppercase
        }
    }
    
    // HERE'S de real code:
    string input = get_string("plaintext: "); // get user text.
    int index;
    
    printf("ciphertext: ");
    for (int k = 0; k < strlen(input); k++)
    {
        index = (int)input[k]; // makes the char into an int, easier to use.
        
        if (index > 96 && index < 123) // if lowercase
        {
            printf("%c", key[index -= 97] + 32); // index from key + lowercase it.

        }
        else if (index > 64 && index < 91) // if uppercase
        {
            printf("%c", key[index -= 65]); // index from key
        }
        else 
        {
            printf("%c", input[k]); // insert whatever symbol or space there was.
        }
    }
    
    printf("\n");
    return 0; // exit with 0
}