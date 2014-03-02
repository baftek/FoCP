#include <stdio.h>

#define LINE_SIZE 100

int main()
{
    char c, line[LINE_SIZE];
    int i, num = 0;

    while ((c = getchar()) != EOF)
    {
        line[num++] = c;

        if (c == '\n') // handle Enter press
        {
            for (i = 0; i < 2 * num; ++i)
                printf("%c", line[i % num]); // 0, 1, ..., N, 0, 1, ..., N
                
            num = 0;
        }
    }

    return 0;
}
