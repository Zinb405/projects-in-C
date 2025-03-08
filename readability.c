#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string Text;
    float index;
    float L, S, Grade;
    float words, letters, sentences;

    L = 0;
    S = 0;
    letters = 0;
    words = 1;
    sentences = 0;
    Text = get_string("Text: ");

    for (int i = 0; i < strlen(Text); i++)
    {
        if (Text[i] == '.' || Text[i] == '!' || Text[i] == '?')
            sentences++;
        if (Text[i] == ' ')
            words++;
        if ((Text[i] >= 'A' && Text[i] <= 'Z') || (Text[i] >= 'a' && Text[i] <= 'z'))
            letters++;
    }
   

    // the average number of letters per 100 words
    L = (letters * 100) / words;
    // printf("L: %f \n",L);
    //  the average number of sentences per 100 words
    S = (sentences * 100) / words;
    // printf("S: %f \n",S);
    index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("sentences: %f \n",index);
    Grade = round(index);
    if (Grade < 1)
        printf("Before Grade 1\n");
    else if (Grade > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %.f\n", Grade);
}
