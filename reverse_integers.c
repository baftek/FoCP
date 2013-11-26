#include <stdio.h>

#define N 5

int main()
{
    int i = N;
    int data[N];

    printf("Enter %d numbers. Each of them should be in one line:\n", N);

    for (i = 0; i < N; ++i)
        scanf("%d", &data[i]);

    printf("Numbers in reverse order:\n");

    for (i = N; --i >= 0; )
        printf("%d\n", data[i]);

    return 0;
}
