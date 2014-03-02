#include <stdio.h>

// atoi:
#include <stdlib.h>

int main(int argc, char **argv)
{
    int x;
    int y;

    if (argc < 3) // program.exe arg1 arg2
    {
        fprintf(stderr, "Too few arguments!"); // error message
        return 1;
    }

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    printf("%d", x + y);

    return 0;
}
