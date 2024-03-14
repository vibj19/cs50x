#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_long("x: ");
    float y = get_long("y: ");

    double z = (double) x/ (double) y;
    printf("%.20f\n", z);
}
