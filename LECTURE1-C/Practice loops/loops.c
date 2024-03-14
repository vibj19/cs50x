//
#include <stdio.h>
#include <cs50.h>

int i,j=1,n,store;
_Bool prime=1;
int main(void)
{
    do
    {
        n= get_int("Number to check: ");
    }
    while(n<1);

    for (i=2;i<n;i++)
    {
        //check remainder =0
        j=n%i;
        if(j==0)
        {
            prime=0;
            printf("This number is not prime\n");
            break;
        }
    }

    if (prime==1)
    {
        printf("This number is prime\n");
    }

}
