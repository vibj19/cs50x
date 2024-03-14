#include <stdio.h>

int main(void)
{

    FILE *hello = fopen("hello.txt","w");
    if (hello == NULL)
    {
        return 1;
    }
    fprintf(hello,"Hello world");
    fclose(hello);
}
