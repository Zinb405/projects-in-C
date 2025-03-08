#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    string plaintext;
    char ciphertext[100];
    int result;
    result = 0;
    if (argc != 2)
    {
        printf("Usage: /.caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: /.caesar key\n");
            return 1;
        }
    }

    plaintext = get_string("plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            result = (plaintext[i]) + atoi(argv[1]);
            if (isupper(plaintext[i]))
            {
                if (result > 90)

                    ciphertext[i] = ((result - 90) % 26) + 64;

                else
                    ciphertext[i] = result;
            }
            if (islower(plaintext[i]))
            {
                if (result > 122)
                    ciphertext[i] = ((result - 122) % 26) + 96;
                else
                    ciphertext[i] = result;
            }
        }
        else
            ciphertext[i] = (plaintext[i]);
    }

    printf("Ciphertext: %s\n", ciphertext);
}
