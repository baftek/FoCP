#include <stdio.h>

// sin:
#include <math.h>

#define COUNT 10

int main()
{
    double nums[COUNT];
    double *num;
    int i; // index of current number

    // fill data
    for (i = 0; i < COUNT; ++i)
    {
        num = &nums[i]; // get address of i-th element
        *num = sin((double) i); // set some value
    }

    // print
    for (i = 0; i < COUNT; ++i)
        printf("nums[%d] = %lf\n", i, nums[i]);

    return 0;
}
