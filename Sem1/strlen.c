// returns string length (without null)
unsigned strlen(char *str)
{
    unsigned size = 0;

    // while current char different than null
    while (str[size])
        size++;

    return size;
}
