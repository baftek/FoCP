#include <stdio.h>

#define START_NUM 2

typedef unsigned long long Big;

Big get_factor(Big num)
{
    Big cur;

    for (cur = 2; cur < num; ++cur)
        if (num % cur == 0)
            return cur;

    return 0;
}

int main()
{
    Big num = 6321246989923;

    if (Big factor = get_factor(num))
    {
        printf("%I64u is not a prime number. Factorization:\n", num);
        printf("%I64u\n", factor);

        factor = num;
        do
            factor = get_factor(factor);
        while (get_factor(factor));
    }

    return 0;
}
