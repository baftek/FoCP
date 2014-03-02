#include <stdio.h>

int main()
{
    unsigned long long num;
    unsigned pos = 0;
    char result[512];

    printf("Enter a number: ");
    scanf("%I64u", &num);
    printf("%I64u dec => ", num);

    // special case
    if (num == 0)
        printf("0");

    // calculate bits
    for (; num > 0; num /= 2)
        result[pos++] = '0' + num % 2;

    // print in reverse order
    while (pos) // <=> pos > 0
        printf("%c", result[--pos]);

    printf(" bin\n");

    return 0;
}
