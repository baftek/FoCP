#include <stdio.h>
#include <math.h>

int main()
{
    float num;

    for (num = 2; num > 0; num -= 1/pow(10.0f, 10.0f))
        if (pow(num, num) == 2.0f)
            printf("%.2f\n", pow(sqrt(2.0f), sqrt(2.0f)));

    return 0;
}
