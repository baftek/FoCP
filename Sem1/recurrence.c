#include <stdio.h>
#include <stdlib.h>

// 1. power & factorial function
// 2. Fibonacci recursively
// 3. W = sum[i = 0 -> k](a_i) + sum[i = 0 -> k - 1](a_i) (?)

#define NUM_START 0
#define NUM_END 6

unsigned int power(int x, unsigned int k)
{
    return k == 0 ? 1 : x * power(x, k - 1);
}

unsigned long long int factorial(unsigned int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

unsigned int fibonacci(unsigned int n)
{
    return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    // factorial n!
    for (n = NUM_START; n <= NUM_END; ++n)
        printf("%d! = %I64u\n", n, factorial(n));

    printf("\n");

    // power n^n
    for (n = NUM_START; n <= NUM_END; ++n)
        printf("%d ^ %d = %d\n", n, n, power(n, n));

    printf("\n");

    // fibonacci fib(n)
    for (n = NUM_START; n <= NUM_END; ++n)
        printf("fib %d = %d\n", n, fibonacci(n));

    return 0;
}
