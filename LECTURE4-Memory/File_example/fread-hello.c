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

    // open new file fread-hello.txt for writing
    FILE *newfile = fopen("fread-hello.txt","w");
    if (newfile == NULL)
    {
        printf("Could not write new file");
        return 1;
    }

    // FN1 - Use a loop to read from hello.txt to copy to fread-hello.txt using fread & fwrite
    char buffer[sizeof(char)*20];
    while (fread(buffer, 1, 1, ogfile) == 1)
    {
        fwrite(buffer,1, 1, newfile);
    }

    // Close hello.txt
    fclose (ogfile);

    // Close copyhello.txt
    fclose (newfile);

}
