#include <stdio.h>

// stack corrupted

int main()
{
    int i; char c;
    char data['Z'];

    for (i = 'A'; i <= 'Z'; ++i)
        data[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= 'a')
            c -= 'a' - 'A';

        if (c >= 'A' && c <= 'Z')
            ++data[c];
    }

    for (i = 'A'; i <= 'Z'; ++i)
        printf("%c: %d\t", i, data[i]);

    return 0;
}
