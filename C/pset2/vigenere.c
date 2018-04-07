#import <stdio.h>
#import <cs50.h>
#import <ctype.h>
#import <string.h>

int main(int argc, string argv[])
{

    // Get rid of args that don't match
    if (argc > 2 || argc < 2)
    {
        printf("Please enter 1 string.\n");

        return 1;
    }

    int keyLength = strlen(argv[1]);


    // Loop through key
    for (int i = 0; i < keyLength; i++)
    {
        if (! isalpha(argv[1][i]))
        {
            printf("Please only use alphanumeric chars.\n");

            return 1;
        }

        // Change capital to lowercase
        if (argv[1][i] < 'a')
        {
            argv[1][i] += 32;
        }
    }

    string key = argv[1];

    // // Get text input
    string textInput = get_string("Enter your text: ");

    printf("ciphertext: ");

    int keyPosition = 0;
    int keyDelta;
    int reset;
    int overflow;
    char currentKeyAlpha;

    // Loop through the string to cypher
    for (int j = 0, n = strlen(textInput); j < n; j++)
    {
        if (textInput[j] >= 'A' && textInput[j] <= 'z')
        {
            currentKeyAlpha = key[keyPosition];

            keyDelta = currentKeyAlpha - 'a';

            // If letter is upper
            // Consider refactor
            if (isupper(textInput[j]))
            {
                if (textInput[j] + keyDelta > 'Z')
                {
                    reset = 26 - ('Z' - textInput[j]);

                    overflow = (keyDelta - ('Z' - textInput[j])) % 26;

                    // get key position
                    printf("%c", textInput[j] - reset + overflow);
                }
                else
                {
                    printf("%c", textInput[j] + keyDelta);
                }
            }
            else
            {
                if (textInput[j] + keyDelta > 'z')
                {
                    reset = 26 - ('z' - textInput[j]);

                    overflow = (keyDelta - ('z' - textInput[j])) % 26;

                    // get key position
                    printf("%c", textInput[j] - reset + overflow);
                }
                else
                {
                    printf("%c", textInput[j] + keyDelta);
                }
            }


            // Reset key position
            if (keyPosition == keyLength - 1)
            {
                keyPosition = 0;
            }
            else
            {
                keyPosition++;
            }
        }
        else
        {
            printf("%c", textInput[j]);
        }
    }
    printf("\n");
}