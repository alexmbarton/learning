#import <stdio.h>
#import <cs50.h>
#import <math.h>

int main(void)
{

    long long creditCardNumber;

    do
    {
        creditCardNumber = get_long_long("Enter Card: ");
    }
    while (creditCardNumber <= 0);

    int cardLength = (int) log10(creditCardNumber) + 1;

    if (cardLength != 13 && cardLength != 15 && cardLength != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int creditCardArray[cardLength];
    long long count = creditCardNumber;
    int i = 0;

    while (count > 0)
    {
        // get array position
        // -1 = end && reduce by i
        // Get last number
        creditCardArray[ cardLength - 1 - i] = count % 10;

        // Remove last digit
        count = count / 10;

        i++;
    }

    // Start the checksum
    int checkSum = 0;
    int multipliedInt;
    int firstTwoDigits[2];

    for (int j = 0; j < cardLength; j++)
    {

        // Grab the first two digits
        if (j < 2)
        {
            firstTwoDigits[j] = creditCardArray[j];
        }

        // If every second
        if (j % 2 != 0)
        {

            multipliedInt = creditCardArray[cardLength - 1 - j] * 2;

            if (multipliedInt > 9)
            {
                // Split ints
                int split_digit = 0;
                checkSum += multipliedInt % 10;
                split_digit = multipliedInt / 10;
                checkSum += split_digit;
            }
            else
            {
                checkSum += multipliedInt;
            }

        }
        else
        {
            checkSum += creditCardArray[cardLength - 1 - j];
        }
    }

    // If the checksum doesn't end in a 0
    if (checkSum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Test initial card digits for brand
    if (firstTwoDigits[0] == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else if ((firstTwoDigits[0] == 3 && firstTwoDigits[1] == 4) || (firstTwoDigits[0] == 3 && firstTwoDigits[1] == 7))
    {
        printf("AMEX\n");
        return 0;
    }
    else if (firstTwoDigits[0] == 5 && (firstTwoDigits[1] == 1 || firstTwoDigits[1] == 2 || firstTwoDigits[1] == 3
                                        || firstTwoDigits[1] == 4 || firstTwoDigits[1] == 5))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}