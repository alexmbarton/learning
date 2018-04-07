#import <cs50.h>
#import <stdio.h>


int main(void)
{
    int n;
    // Get an int from the user
    do
    {
        n = get_int("Int: ");
    }
    while (n < 0 || n > 23);

    for (int i=0, counter = 1;i<n;i++, counter++) {

        for (int j=0;j<(n-counter);j++) {
            printf(" ");
        }
        for (int j=0;j<counter;j++) {
            printf("#");
        }

        printf("  ");

        for (int j=0;j<counter;j++) {
            printf("#");
        }

        printf("\n");
    }
}