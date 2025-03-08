#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long Number;
    long MNumber;
    int sum;
    int subsum;
    int mathrel;
    int Numberdigit;
    int digit;
    long twofirstdigit;
    Number = 0;
    Number = get_long("Number: ");
    MNumber = Number;
    Numberdigit = 1;
    sum = 0;
    subsum = 0;
    // counting number of digits
    while (Number / 10 > 0)
    {
        Numberdigit += 1;
        Number = Number / 10;
    };
    if (Numberdigit == 13 || Numberdigit == 15 || Numberdigit == 16)
    {
        digit = 0;
        twofirstdigit = 0;
        // counting the sum of each digt times 2 and the sum of other digits
        for (int i = 0; i < Numberdigit; i++)
        {
            digit = MNumber % 10;
            MNumber = MNumber / 10;
            if (i % 2 != 0)
            {
                digit = 2 * digit;
                if (digit > 10 || digit == 10)
                {
                    digit = digit / 10 + digit % 10;
                }
                sum += digit;
            }
            if (i % 2 == 0)
                subsum += digit;

            if (i == Numberdigit - 3)
                twofirstdigit = MNumber;
        }
        // checksum
        mathrel = (sum + subsum) % 10;
        if (mathrel != 0)
        {
            printf("INVALID\n");
            return 0;
        }
        else
        {
            if ((twofirstdigit == 37 || twofirstdigit == 34) && Numberdigit == 15)
            {
                printf("VALID\n");
                printf("AMEX\n");
                return 0;
            }

            if ((twofirstdigit > 39 && twofirstdigit < 50) &&
                (Numberdigit == 13 || Numberdigit == 16))
            {
                printf("VALID\n");
                printf("VISA\n");
                return 0;
            }

            if ((twofirstdigit > 50 && twofirstdigit < 56) && (Numberdigit == 16))
            {
                printf("VALID\n");
                printf("MASTERCARD\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
