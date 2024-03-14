#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void Do_substitute(); // for further substitute
void alpha_arr_val(char pos, string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < strlen(argv[1]) ; i++)
            {

                if (! isalpha(argv[1][i])) 
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }

                for (int j = i + 1 ; j < strlen(argv[1]) ; j++) // checking to the next element of arg[i]
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i])) // checking repeated element
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }

            Do_substitute(argv[1]);

        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}


void Do_substitute(string key)
{
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(p); i++)
    {
        if (isalpha(p[i])) // checking p[i] is alphabet
        {
            char x = p[i];
            if (islower(p[i]))
            {
                alpha_arr_val(tolower(x), key); // passing p[i] in lower-case
            }
            else
            {
                alpha_arr_val(toupper(x), key); // passing p[i] in UPPER-CASE
            }


        }
        else
        {
            printf("%c", p[i]); // print the element as it is (such as space | , | special characters | ? | etc...)
        }
    }

    printf("\n");

}
void alpha_arr_val(char pos, string key) // passing p[i] and upper/lower(alpha array)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // alphabet array

    for (int i = 0; i < strlen(alpha); i++)
    {
        if (islower(pos)) // p[i] is lower
        {
            if (pos == tolower(alpha[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else
        {
            if (pos == toupper(alpha[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}
