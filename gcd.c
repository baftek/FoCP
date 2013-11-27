#include <stdio.h>

// greatest common divisor
// 0, 0 case produces 0!
unsigned int gcd(unsigned int a, unsigned int b)
{
    if (a == 0) return b;       // gcd(0, b) => b
    if (b == 0) return a;       // gcd(a, 0) => a

    while (a != b)
        if (a > b)
            a -= b;
        else // if (a <= b)     // a == b checked in while loop already
            b -= a;

    return a;
}

int main()
{
    int x, y, pos = 0;

    // test cases: pairs of x, y
    // zero pair marks end of list
    int pairs[] = {
        0, 3,
        3, 7,
        4, 0,
        8, 28,
        15, 25,
        12, 78,
        28, 8,
        79, 67,
        640, 512,
        816, 228,
        0, 0
    };

    while (true)
    {
        x = pairs[pos++];
        y = pairs[pos++];

        // check for zero pair
        if (x == 0 && y == 0)
            break;

        printf("gcd(%4d, %4d) => %4d\n", x, y, gcd(x, y));
    }

    return 0;
}
