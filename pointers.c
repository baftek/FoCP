#include <stdio.h>

// for malloc (memory allocate):
#include <stdlib.h>

/*

FoCP laboratory: Pointers
2013-11-21

1.	void change(int a, int b)
    void change2(int *a, int *b)
2.	Write a function which allocates mem. for an array of ints.
3.	Write a program, which:
    a)	asks the user for the number of ints,
    b)	collects data,
    c) prints collected data in inverted order,
    d) frees the memory.

*/

// exchanges two integers (no change in original values!)
void exchange(int a, int b)
{
    int i = a;
    a = b;
    b = i;
}

// exchanges two integers operating on pointers
void exchange_ptr(int *a, int *b)
{
    int i = *a;
    *a = *b;
    *b = i;
}

// allocates given number of integers to form an array
int* allocate_ints(unsigned num)
{
    return (int *) malloc(num * sizeof(int));
}

int main()
{
    //  exchanging of values
    int x = 5, y = 8;
    printf("first:\nx = %d, y = %d\n\n", x, y);

    exchange(x, y);
    printf("exchange:\nx = %d, y = %d\n\n", x, y); // no change!

    exchange_ptr(&x, &y);
    printf("exchange_ptr:\nx = %d, y = %d\n\n", x, y); // here values are changed
    
    unsigned size; // number of elements
    printf("How many elements would you like to store? ");
    scanf("%u", &size);

    int *nums = allocate_ints(size);

    if (!nums) // Houston, we have a problem here
    {
        perror("Cannot allocate array of that size.");
        return 1;
    }

    unsigned pos = 0; // current element position

    // collection of data
    printf("Enter data:\n");

    while (pos < size)
    {
        printf("%u = ", pos);
        scanf("%d", &nums[pos++]);
    }

    // dumping of data
    printf("The stored data is as follows:");

    while (pos)
        printf(" %d", nums[--pos]);

    // free data array, not needed anymore
    free(nums);

    getchar(); getchar(); // ugly hack for redundant cr lf

    return 0;
}


