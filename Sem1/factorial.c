#include <stdio.h>

// restrict results to non-negative numbers only
long long unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main()
{
    int i;

    for (i = 0; i <= 10; ++i)
        printf("%3u! = %I64u\n", i, factorial(i));

    return 0;
}
