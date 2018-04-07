#import <stdio.h>
#import <cs50.h>
#import <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc > 2)
    {
        printf("Only one key please.\n");
        return 1;
    }
    else if (argc < 2)
    {
        printf("Please provide a key.\n");
        return 1;
    }

    int k;

    k = atoi(argv[1]);

    // Get text input
    string textInput = get_string("Enter your text: ");

    int reset;
    int overflow;

    printf("ciphertext: ");

    for (int i = 0, n = strlen(textInput); i < n; i++)
    {
        if (textInput[i] >= 'A' && textInput[i] <= 'z')
        {
            // greater than 122
            if (textInput[i] + k > 'z')
            {

                // Return to 'a' or 'A'
                reset = 26 - ('z' - textInput[i]);

                // Get the module to add
                overflow = (k - ('z' - textInput[i])) % 26;

                // Print out
                printf("%c", textInput[i] - reset + overflow);
            }
            else
            {
                printf("%c", textInput[i] + k);
            }
        }
        else
        {
            printf("%c", textInput[i]);
        }
    }

    printf("\n");
    return 0;
}