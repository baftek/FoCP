// Copyright 2014 by Siarkowy.
// Released under the terms of GNU GPL v3 license.

#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "data.txt"

typedef struct Data
{
    double value;
    struct Data *next;
} Data;

int main()
{
    FILE* input = NULL;
    Data* head = NULL;
    Data* current = NULL;

    // Opening of the file
    if (!(input = fopen(FILE_NAME, "r")))
    {
        fprintf(stderr, "Could not open input file.");
        return 1;
    }

    // Reading from file
    do
    {
        double value;

        if (fscanf(input, "%lf", &value) == 1)
        {
            current = (Data *) malloc(sizeof(*current));

            if (!current)
            {
                fprintf(stderr, "Out of memory.");
                return 2;
            }

            current->value = value;
            current->next = head;
            head = current;
        }
    } while (!feof(input));

    // Printing
    for (current = head; current != NULL; current = current->next)
        printf("%.2lf\n", current->value);

    // Memory freeing
    while (head)
    {
        current = head->next;
        free(head);
        head = current;
    }

    return 0;
}
