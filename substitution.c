#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    string plaintext;
    char ciphertext[100];
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    // handles lack of argv[1]
    if (argc != 2)
    {
        printf("Usage: /.substitution key\n");
        return 1;
    }
    // handles length of argv[1]
    if (strlen(argv[1]) != 26)
    {
        printf("Usage: /.substitution key\n");
        return 1;
    }
    // handles if argv[1] contains a non-alphabetic character
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("Usage: /.substitution key\n");
            return 1;
        }
    }
    // handles duplicate character in uppercase and lowercase key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Usage: /.substitution key\n");
                return 1;
            }
        }
    }

    // Asking for input
    plaintext = get_string("plaintext: ");

    // cipher
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {

            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (plaintext[i] == toupper(alphabet[j]))

                        ciphertext[i] = toupper(argv[1][j]);
                }
            }
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (plaintext[i] == alphabet[j])
                        ciphertext[i] = tolower(argv[1][j]);
                }
            }
        }
        else
            ciphertext[i] = plaintext[i];
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
