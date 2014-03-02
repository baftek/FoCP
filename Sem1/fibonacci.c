#include <stdio.h>

int main()
{
    unsigned i, num;

    // this type allows computation of ~90th Fibonacci number
    unsigned long long fib, prev1, prev2;

    printf("Enter a number: ");
    scanf("%u", &num);

    prev1 = 1;
    prev2 = 1;

    printf("0 -> %I64u\n", prev1);
    printf("1 -> %I64u\n", prev2);

    for (i = 2; i <= num; ++i)
    {
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;

        printf("%d -> %I64u\n", i, fib);
    }

    return 0;
}
