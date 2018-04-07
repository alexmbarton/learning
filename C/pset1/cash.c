#import <cs50.h>
#import <stdio.h>
#include <math.h>

int main(void)
{
    // number = 0
    // 0.25, 0.10, 0.05, 0.01

    int number = 0;
    float amount;
    int change;

    // Get int
    do
    {
        amount = get_float("Cash: ");
    }
    while (amount < 0);

    // convert float to int

    amount = amount * 100;
    amount = round(amount);
    change = (int) amount;


    while(change >= 25) {
        change -= 25;
        number++;
    }

    while(change >= 10) {
        change -= 10;
        number++;
    }

    while(change >= 5) {
        change -= 5;
        number++;
    }

    while(change >= 1) {
        change -= 1;
        number++;
    }

    printf("%i\n",number);
}