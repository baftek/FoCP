#include <stdio.h>

void multiple_by_2(double *num)
{
    *num *= 2;
}

int main()
{
    double x = 1579.0/367.0;

    printf("Value: %.3lf\n", x);
    multiple_by_2(&x);
    printf("Value: %.3lf\n", x);

    return 0;
}
