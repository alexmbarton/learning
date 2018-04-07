#import <stdio.h>
#import <cs50.h>
#import <stdlib.h>

int fact();

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Only one argument please\n");
    }

    int sum = 0;
    int input =  atoi(argv[1]);

    sum = fact(input);

    printf("The factorial of %i is %i\n",input,sum);
}

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}