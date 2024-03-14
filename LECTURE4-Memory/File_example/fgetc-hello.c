#include <stdio.h>

int main (void)
{
    // Open hello.txt for reading
    FILE *ogfile = fopen("hello.txt","r");
    if (ogfile == NULL)
    {
        printf("Could not open hello.txt");
        return 1;
    }

    // open new file fgetc-hello.txt for writing
    FILE *newfile = fopen("fgetc-hello.txt","w");
    if (newfile == NULL)
    {
        printf("Could not write new file");
        return 1;
    }

    // FN1 - Use a loop to read from hello.txt to copy to fgetc-hello.txt using fgetc & fputc
    int ch;
    while ((ch = fgetc(ogfile)) != EOF)
    {
        fputc(ch, newfile);
    }

    // Close hello.txt
    fclose (ogfile);

    // Close copyhello.txt
    fclose (newfile);


}
