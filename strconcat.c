#include <stdio.h>

// malloc:
#include <stdlib.h>

// returns string length (without null)
unsigned strlen(char *str)
{
    unsigned size = 0;

    // while current char different than null
    while (str[size])
        size++;

    return size;
}

// concatenates two strings returning a new string
char* strconcat(char *strA, char *strB)
{
    // allocate (length of a + length of b + null) * (size of char) bytes of memory
    char *result = (char *) malloc((strlen(strA) + strlen(strB) + 1) * sizeof(char));

    int posA = 0, posB = 0;

    while (strA[posA]) // not null
        result[posA++] = strA[posA];

    while (strB[posB]) // not null
        result[posA++] = strB[posB++];

    // terminate with null
    result[posA] = '\0';

    return result;
}

int main()
{
    char *str1 = "computer";
    char *str2 = " programming";
    char *str3 = strconcat(str1, str2);

    printf("str1 = '%s'\n", str1);
    printf("str2 = '%s'\n", str2);
    printf("str3 = '%s'\n", str3);

    // let's clean up after malloc!
    free(str3);

    return 0;
}
