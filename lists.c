#include <stdio.h>

// malloc:
#include <stdlib.h>

// Read count of numbers
// Read numbers to the list
// Display list contents
// Free memory

typedef struct data
{
    int value;
    struct data *next;
} Data;

Data* AddToList(Data *head, Data *d)
{
    d->next = head;
    head = d;

    return d;
}

void FreeList(Data *head)
{
    Data *prev;

    while (head)
    {
        prev = head;
        head = head->next;
        free(prev);
    }
}

int main()
{
    Data *head = NULL;

    // read count
    unsigned count;

    printf("Enter number count: ");
    scanf("%u", &count);

    // read data to the list
    while (count--)
    {
        Data *d = (Data *) calloc(1, sizeof(*d)); // allocate new element
        scanf("%i", &d->value);
        head = AddToList(head, d);
    }

    // display contents
    Data *curr = head;

    while (curr)
    {
        printf("%3d ", curr->value);
        curr = curr->next;
    }

    // free memory
    FreeList(head);

    return 0;
}
