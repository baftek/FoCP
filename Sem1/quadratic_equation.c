#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    a = b = c = 0;

    printf("Enter coefficients of quadratic equation: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0)
    {
        printf("This is a linear equation!\n");
        return 0;
    }

    float delta = b * b - 4 * a * c;

    if (delta > 0) // 2 solutions
    {
        float x1 = (-b - sqrt(delta)) / (2 * a);
        float x2 = (-b + sqrt(delta)) / (2 * a);

        printf("Solutions: x1 = %.2f, x2 = %.2f.\n", x1, x2);
    }
    else if (delta == 0) // 1 solution
    {
        float x = (-b) / (2 * a);

        printf("Solution: x = %.2f.\n", x);
    }
    else // delta < 0, no real solution
        printf("There is no solution.\n");

    return 0;
}
