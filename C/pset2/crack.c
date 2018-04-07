#define _XOPEN_SOURCE
#include <unistd.h>
#import <stdio.h>
#import <cs50.h>
#import <string.h>

int checkPassword();

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./crack hash\n");
    }

    // Get salt
    char salt[3];

    for (int i = 0; i < 2; i++)
    {
        salt[i] = argv[1][i];
    }

    // Declare password
    char password[6];

    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Solve a single letter
    for (int j = 0; j < strlen(alphabet); j++)
    {
        password[0] = alphabet[j];

        if (strcmp(argv[1],crypt(password,salt)) == 0)
            {
                printf("\nSuccess: %s\n",password);
                return 0;
            }
    }
    printf(".");

    // Solve for two letters
    for (int j = 0; j < strlen(alphabet); j++)
    {
        password[0] = alphabet[j];

        for (int k = 0; k < strlen(alphabet); k++)
        {
            password[1] = alphabet[k];

            if (strcmp(argv[1],crypt(password,salt)) == 0)
            {
                printf("\nSuccess: %s\n",password);
                return 0;
            }
        }
    }
    printf(".");


    // Solve for three letters
    for (int j = 0; j < strlen(alphabet); j++)
    {
        password[0] = alphabet[j];

        for (int k = 0; k < strlen(alphabet); k++)
        {
            password[1] = alphabet[k];

            for (int m = 0; m < strlen(alphabet); m++)
            {
                password[2] = alphabet[m];

                if (strcmp(argv[1],crypt(password,salt)) == 0)
                {
                    printf("\nSuccess: %s\n",password);
                    return 0;
                }
            }
        }
    }
    printf(".");

    // Solve for four letters
    for (int j = 0; j < strlen(alphabet); j++)
    {
        password[0] = alphabet[j];

        for (int k = 0; k < strlen(alphabet); k++)
        {
            password[1] = alphabet[k];

            for (int m = 0; m < strlen(alphabet); m++)
            {
                password[2] = alphabet[m];

                for (int o = 0; o < strlen(alphabet); o++)
                {
                    password[3] = alphabet[o];

                    if (strcmp(argv[1],crypt(password,salt)) == 0)
                    {
                        printf("\nSuccess: %s\n",password);
                        return 0;
                    }
                }
            }
        }
    }
    printf(".");

    // Solve for five letters
    for (int j = 0; j < strlen(alphabet); j++)
    {
        password[0] = alphabet[j];

        for (int k = 0; k < strlen(alphabet); k++)
        {
            password[1] = alphabet[k];

            for (int m = 0; m < strlen(alphabet); m++)
            {
                password[2] = alphabet[m];

                for (int o = 0; o < strlen(alphabet); o++)
                {
                    password[3] = alphabet[o];

                    for (int p = 0; p < strlen(alphabet); p++)
                    {
                        password[4] = alphabet[p];

                        if (strcmp(argv[1],crypt(password,salt)) == 0)
                        {
                            printf("\nSuccess: %s\n",password);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf(".");
    printf("Failed to find password\n");
    return 1;


}
