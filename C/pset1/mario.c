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

    // Print out that many #
    for (int i=0;i<n;i++) {

        int k = 2+i;

        for (int j=(n-k);j>=0;j--) {
            printf(" ");
        }
        for (int j=k;j>0;j--) {
            printf("#");
        }
        printf("\n");

    }
}