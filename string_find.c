#include <stdio.h>

// has to be int for not found case -1
int string_find(char str[], char c)
{
    int pos; // current position

    // for:
    // set initial value for pos
    // do the loop while end of string not reached
    //    str[pos] <=> str[pos] != 0 <=> str[pos] != false
    // increment pos

    for (pos = 0; str[pos]; ++pos)
        if (str[pos] == c) // char matches
            return pos;

    // not found
    return -1;
}

int main()
{
    char c = 'g';

    char str1[] = "Testing";
    char str2[] = "gvcqable";
    char str3[] = "riodsgholskdf";
    char str4[] = "Azxczxczxc";

    printf("Position of '%c' in (-1 means not found):\n", c);
    printf("<%s> = %d\n", str1, string_find(str1, c));
    printf("<%s> = %d\n", str2, string_find(str2, c));
    printf("<%s> = %d\n", str3, string_find(str3, c));
    printf("<%s> = %d\n", str4, string_find(str4, c));

    return 0;
}
