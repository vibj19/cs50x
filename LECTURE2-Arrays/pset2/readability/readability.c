#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int i=0, L=0, S=0, words=0, letters=0, sent=0, X=0, spaces=0;
float index = 0.0;

int main (void)
{
    // Ask user to input some text

    string text = get_string("Text: ");
    int length= strlen(text);

    // Calculate number of words

    for (i=0; i<length; i++)
    {
        if (isspace(text[i])!=0)
        {
            spaces++;
        }
    }
    words = spaces+1;

    // Calculate number of letters

    for (i=0; i<length; i++)
        {
            if (isalpha(text[i])!=0)
            {
            letters++;
            }
        }

    // Calculate average number of letters per 100 words in the text (L)

    L= (letters*100)/words;


    // Calculate number of sentences
    for (i=0; i<length; i++)
        {
           if (text[i] == '.' || text[i] == '?' || text[i] == '!')
            {
                if (i-1>=0 && text[i-1] != '.')
                {
                     sent++;
                 }
            }
        }

    // Calculate average number of sentences per 100 words in the text (S)

      S = sent*100/words;

    // Input L and S into the "INDEX" with return X

    index = (0.0588 * L) - (0.296 * S) - 15.8;
    X = round(index);

    // Round X to the nearest integer and print GRADE X; if X =>16, Grade 16+; if X<1, Before Grade 1

    if (X >= 1 && X<16)
    {
        printf("Grade %i\n", X);
    }
    else if (X < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (X>16)
    {
        printf("Grade 16+\n");
    }
}
