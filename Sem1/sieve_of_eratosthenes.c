#include <stdio.h>

#define MIN_NUM 2
#define MAX_NUM 200

int main()
{
    int i, num = MIN_NUM, nums[MAX_NUM + 1];

    // suppose all nums are primes
    for (i = MIN_NUM; i <= MAX_NUM; ++i)
        nums[i] = true;

    // apply the sieve of Eratosthenes
    for (i = MIN_NUM; i <= MAX_NUM; ++i)
        for (num = 2 * i; num <= MAX_NUM; num += i)
            nums[num] = false;

    // print out prime numbers
    for (i = MIN_NUM; i <= MAX_NUM; ++i)
        if (nums[i])
            printf("%d\t", i);

    // wait for Enter
    getchar();

    return 0;
}
