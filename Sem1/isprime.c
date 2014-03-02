#include <stdio.h>

#define START_NUM 2

typedef unsigned long long Big;

Big get_factor(Big num)
{
    if (num == 0 || num == 1 || num == 2)
        return false;

    Big cur;

    for (cur = START_NUM; cur < num; ++cur)
        if (num % cur == 0)
            return cur;

    return false;
}

void factorize(Big num)
{
    Big factor;

    if (factor = get_factor(num))
    {
        if (factor > 1)
        {
            printf("%I64u\n", factor);
            return factorize(num/factor);
        }
    }
    else
        printf("%I64u\n", num);
}

int main()
{
    Big num, factor;

    num = 0;
    factor = 0;

    do
    {
        printf("Enter an integer: ");
        scanf("%I64u", &num);

        if (factor = get_factor(num))
        {
            printf("%I64u = NOT PRIME\n", num, factor);
            factorize(num);
        }

        else
            printf("%I64u = PRIME\n", num);
    }
    while (num);

    return 0;
}
